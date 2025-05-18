/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:50:37 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/09 17:22:46 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
** Updates envp when using cd
** PWD will always be created if unset
** OLDPWD will be updated only if it exists
*/
void	update_pwd(t_ms *ms, bool alloc)
{
	char	*pwd;
	char	*check;
	char	*newpwd;

	oldpwd(ms);
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		if (errno == ENOENT)
		{
			alloc = false;
			pwd = "";
		}
		else
			getcwd_error(ms, "cd: ", "getcwd");
	}
	check = find_var(ms, ms->envp, "PWD");
	if (check)
	{
		newpwd = ft_strjoin("PWD=", pwd);
		export_var_to_envp(ms, newpwd);
		free(newpwd);
	}
	if (alloc == true)
		free(pwd);
}

/*
** Handles the case of cd -
** Will return error if OLDPWD is unset
*/
int	cd_special_case(t_ms *ms)
{
	char	*dest;

	dest = find_var(ms, ms->envp, "OLDPWD");
	if (!dest)
		return (print_error(ms, "cd: ", "OLDPWD not set"));
	if (chdir(dest) < 0)
		return (print_error(ms, dest, ": No such file or directory"));
	update_pwd(ms, true);
	return (0);
}

/*
** Runs cd builtin command
** If loc is null will attempt to return to HOME
** Else will attempt to change directory to loc
** Sets exit code to 0
*/
int	changedir(t_ms *ms, char *loc)
{
	char	*home;

	if (!loc)
	{
		home = find_var(ms, ms->envp, "HOME");
		if (!home)
			return (print_error(ms, "cd: ", "HOME not set"));
		if (chdir(home) < 0)
			return (print_error(ms, home, ": No such file or directory"));
		update_pwd(ms, true);
		return (0);
	}
	if (loc[0] == '-' && loc[1] == 0)
		return (cd_special_case(ms));
	else if (chdir(loc) < 0)
		return (print_error(ms, loc, ": No such file or directory"));
	update_pwd(ms, true);
	ms->exit_status = 0;
	return (0);
}

/*
** Check if directory is specified for cd
*/
int	parse_cd(t_ms *ms, char **dir)
{
	if (dir[1])
		return (changedir(ms, dir[1]));
	else
		return (changedir(ms, NULL));
}
