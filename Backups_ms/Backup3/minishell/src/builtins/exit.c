/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:01:42 by clu               #+#    #+#             */
/*   Updated: 2025/05/17 19:36:45 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_valid_arg_exit(t_ms *ms, char *code)
{
	int	i;

	i = -1;
	if (code[0] == 0)
	{
		ft_putendl_fd("minishell: exit: : numeric argument required", 2);
		bi_exit(ms, 2, 0);
	}
	while (code[++i])
	{
		if (code[i] < 48 || code[i] > 57)
		{
			ft_putendl_fd("minishell: exit: : numeric argument required", 2);
			bi_exit(ms, 2, 0);
		}
	}
	bi_exit(ms, ft_atoi(code), 0);
}

/*
** Builtin exit function
** Frees all allocated memory
** Can be used in case of error with the error variable
*/
void	bi_exit(t_ms *ms, int ex_code, int error)
{
	(void)error;
	if (ms)
	{
		if (ms->prompt)
			free(ms->prompt);
		close_fd(ms);
		free_envp(ms);
		if (ms->pids)
			free(ms->pids);
		// if (!error)
		// 	write(2, "exit\n", 5);
		free_structs(ms);
	}
	exit(ex_code);
}
