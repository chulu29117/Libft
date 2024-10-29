/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:21:54 by clu               #+#    #+#             */
/*   Updated: 2024/09/16 14:22:00 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr (char *c)
{
	int	i;
	
	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	write(1, &"\n", 1);
}

int	main (int argc, char *argv[])
{
	int	i;
	
	i = 1;
	while (argc > i)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
