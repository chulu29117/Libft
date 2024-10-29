/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datikhom <datikhom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:28:34 by datikhom          #+#    #+#             */
/*   Updated: 2024/09/22 20:04:27 by datikhom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <stdlib.h>

int	get_group_start(int len)
{
	if (len % 3 == 0)
		return (3);
	return (len % 3);
}

void	process_group_word(t_group_info group, t_dict *dict_entries)
{
	int	num_value;

	num_value = ft_atoi_substr(group.number, group.pos, group.group_len);
	if (num_value != 0)
	{
		process_hundreds(num_value, dict_entries);
		print_scale(group.scale_index);
	}
}

void	process_group_loop(char *number, int group_count,
				int start, t_dict *dict_entries)
{
	int				pos;
	int				group_index;
	int				group_len;
	int				scale_index;
	t_group_info	group;

	pos = 0;
	group_index = 0;
	while (group_index < group_count)
	{
		group_len = get_group_len(group_index, start);
		scale_index = group_count - group_index - 1;
		group.number = number;
		group.pos = pos;
		group.group_len = group_len;
		group.scale_index = scale_index;
		process_group_word(group, dict_entries);
		pos += group_len;
		group_index++;
	}
}

void	num_to_word(char *number, t_dict *dict_entries)
{
	int	len;
	int	group_count;
	int	start;

	len = ft_strlen(number);
	group_count = (len + 2) / 3;
	start = get_group_start(len);
	if (group_count > 12)
	{
		ft_putstr("Number too large\n");
		return ;
	}
	process_group_loop(number, group_count, start, dict_entries);
	ft_putstr("\n");
}
