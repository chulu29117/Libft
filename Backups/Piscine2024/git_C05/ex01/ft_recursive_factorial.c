/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:22:10 by clu               #+#    #+#             */
/*   Updated: 2024/09/13 11:33:15 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb <= 1)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

/*int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
	int	nb = atoi(argv[1]);
	printf("Factorial of %d: %d\n", nb, ft_recursive_factorial(nb));
	}
	else
	{
		printf("1 input required");
	}
	return (0);
}
*/
