/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:48:20 by clu               #+#    #+#             */
/*   Updated: 2024/09/22 20:48:21 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

char	*trim_space(char *str)
{
	int	start;
	int	end;

	start = 0;
	while (str[start] == ' ' || str[start] == '\t')
		start++;
	end = start;
	while (str[end] != '\0')
		end++;
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
		end--;
	str[end] = '\0';
	return (&str[start]);
}
