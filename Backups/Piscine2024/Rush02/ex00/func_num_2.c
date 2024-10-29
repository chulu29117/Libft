/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_num_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:25:25 by clu               #+#    #+#             */
/*   Updated: 2024/09/22 20:25:26 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <stdlib.h>

char	*find_word(int number, t_dict *dict_entries)
{
	int	i;

	i = 0;
	while (dict_entries[i].word != 0)
	{
		if (dict_entries[i].number == number)
			return (dict_entries[i].word);
		i++;
	}
	return (0);
}

char	*scale_words(int index)
{
	static char	*scales[] = {
		"", "thousand", "million", "billion", "trillion", "quadrillion",
		"quintillion", "sextillion", "septillion", "octillion",
		"nonillion", "decillion", "undecillion"
	};

	if (index < 0 || index > 12)
		return (0);
	return (scales[index]);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_atoi_substr(const char *str, int start, int len)
{
	char	*buffer;
	int		i;
	int		result;

	buffer = (char *)malloc(len + 1);
	if (buffer == NULL)
		return (0);
	i = 0;
	while (i < len && str[start + i] != '\0')
	{
		buffer[i] = str[start + i];
		i++;
	}
	buffer[i] = '\0';
	result = ft_atoi(buffer);
	free(buffer);
	return (result);
}
