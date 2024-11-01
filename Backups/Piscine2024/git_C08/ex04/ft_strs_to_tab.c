/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:49:09 by clu               #+#    #+#             */
/*   Updated: 2024/09/19 13:49:12 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}	

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;			// Array of t_stock_str struct
	int			i;

	tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < ac)				// For each string in av, store them
	{
		if (av[i] == NULL)
			return (NULL);
		tab[i].str = av[i];
		tab[i].size = ft_strlen(av[i]);
		tab[i].copy = ft_strdup(av[i]);
		if (tab[i].copy == NULL)	// Error handling, if malloc with strdup fails to copy
		{
			while (i > 0)
				free(tab[--i].copy);
			free(tab);
			return (NULL);
		}
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}

/*#include <stdio.h>

int main(void)
{
	char *tab[] = {"Hello", "World", "42", "Piscine"};
	int i;

	t_stock_str *stock = ft_strs_to_tab(4, tab);
	i = 0;
	while (stock[i].str != NULL)
	{
		printf("Original: %s, Copy: %s, Size: %d\n",
			stock[i].str, stock[i].copy, stock[i].size);
		i++;
	}

	i = 0;
	while (stock[i].str != NULL)
	{
		free(stock[i].copy);
		i++;
	}
	free(stock);

	return 0;
}*/