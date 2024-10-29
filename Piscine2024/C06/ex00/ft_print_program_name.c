/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:12:36 by clu               #+#    #+#             */
/*   Updated: 2024/09/16 13:12:38 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*void	ft_putstr (char *c)
{
	int	i;
	
	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	write(1, &"\n", 1);
}*/

int	main (int argc, char *argv[])
{
	write(1, argv[0], sizeof(argv[0]));
	(void) argc;
	return (0);
}
