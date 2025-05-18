/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:18:00 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/16 13:36:48 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Global variable for signal handler

volatile sig_atomic_t	g_signal = 0;

/*
** Returns the number of elements in the envp array
*/
int	countenvp(char **envp)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (envp[++i])
		j++;
	return (i);
}

/*
** Assigns the system envp to internal envp array
*/
char	**assignenvp(t_ms *ms, char **envp)
{
	char	**temp;
	int		i;

	i = -1;
	ms->elements = countenvp(envp);
	temp = malloc((ms->elements + 1) * sizeof(char *));
	if (!temp)
		exit(-1);
	while (envp[++i])
	{
		temp[i] = ft_strdup(envp[i]);
		if (!temp[i])
			arr_dup_fail(ms, temp, i);
	}
	temp[i] = NULL;
	return (temp);
}

/*
** Initialise all variables for ms struct
*/
void	init_ms(t_ms *ms, char **envp)
{
	ms->envp = assignenvp(ms, envp);
	ms->exit_status = 0;
	ms->token = NULL;
	ms->ast = NULL;
	ms->word = NULL;
	ms->cmd = NULL;
	ms->fd_in = -1;
	ms->fd_out = -1;
	ms->pids = NULL;
	ms->pid_index = 0;
	ms->cmd_path = NULL;
	ms->std_copy[0] = -1;
	ms->std_copy[1] = -1;
	ms->ms_fd[0] = -1;
	ms->ms_fd[1] = -1;
	ms->prev_fd = -1;
	ms->cmd_index = 0;
	ms->child = true;
	ms->prompt = NULL;
	ms->heredoc_name = NULL;
	ms->heredoc_no = 0;
	ms->prompt = NULL;
	ms->syntax_error = false;
	ms->heredoc_no = 0;
	ms->sigfirst = false;
}

/*
** Main function for minishell
** Handles signals and runs main loop
*/
int	main(int argc, char **argv, char **envp)
{
	t_ms				ms;

	(void)argc;
	(void)argv;
	init_ms(&ms, envp);
	get_minishell(&ms);
	shlvl(&ms);
	get_prompt(&ms);
	while (true)
	{
		set_signals();
		process_input(&ms);
		get_prompt(&ms);
		free_structs(&ms);
	}
	return (0);
}
