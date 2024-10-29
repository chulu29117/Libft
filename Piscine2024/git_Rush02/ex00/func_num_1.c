/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:24:19 by clu               #+#    #+#             */
/*   Updated: 2024/09/22 20:24:24 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <stdlib.h>

int	get_group_len(int group_index, int start)
{
	if (group_index == 0)
		return (start);
	return (3);
}

void	process_hundreds(int num_value, t_dict *dict_entries)
{
	int	hundreds;
	int	remainder;

	hundreds = num_value / 100;
	remainder = num_value % 100;
	if (hundreds > 0)
	{
		print_word(hundreds, dict_entries);
		print_word(100, dict_entries);
	}
	if (remainder > 0)
	{
		process_remainder(remainder, dict_entries);
	}
}

void	process_remainder(int remainder, t_dict *dict_entries)
{
	int	tens;
	int	ones;

	if (remainder <= 20)
	{
		print_word(remainder, dict_entries);
	}
	else
	{
		tens = (remainder / 10) * 10;
		ones = remainder % 10;
		print_word(tens, dict_entries);
		if (ones > 0)
			print_word(ones, dict_entries);
	}
}

void	print_word(int number, t_dict *dict_entries)
{
	char	*word;

	word = find_word(number, dict_entries);
	if (word != 0)
	{
		ft_putstr(word);
		ft_putstr(" ");
	}
	else
		ft_putstr("unknown ");
}

void	print_scale(int scale_index)
{
	char	*scale;

	scale = scale_words(scale_index);
	if (scale != 0 && scale[0] != '\0')
	{
		ft_putstr(scale);
		ft_putstr(" ");
	}
}
