/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:24:36 by clu               #+#    #+#             */
/*   Updated: 2024/09/26 13:27:35 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_neg(int n)
{
	if (n < 0)
		write (1, &"N", 1);
	else
		write (1, &"P", 1);
}

int	main(void)
{
	ft_neg(20);
	return (0);
}
