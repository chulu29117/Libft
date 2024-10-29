/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datikhom <datikhom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:34:09 by datikhom          #+#    #+#             */
/*   Updated: 2024/09/22 20:02:27 by datikhom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "rush_02.h"

int	parse_line(char *line, t_dict *dict_entries, int index)
{
	char	*colon_pos;
	char	*number_part;
	char	*word_part;

	if (line[0] == '\0' || line[0] == '#')
		return (-1);
	colon_pos = ft_strchr(line, ':');
	if (!colon_pos)
	{
		return (-1);
	}
	*colon_pos = '\0';
	number_part = trim_space(line);
	word_part = trim_space(colon_pos + 1);
	if (!is_num(number_part) || word_part[0] == '\0')
	{
		return (-1);
	}
	dict_entries[index].number = ft_atoi(number_part);
	dict_entries[index].word = ft_strdup(word_part);
	return (0);
}

int	process_buffer(char *buffer, t_dict *dict_entries, int *entry_i)
{
	char	*line_start;
	char	*line_end;

	line_start = buffer;
	while (*line_start != '\0')
	{
		line_end = line_start;
		while (*line_end != '\n' && *line_end != '\0')
			line_end++;
		if (*line_end == '\n')
			*line_end = '\0';
		if (parse_line(line_start, dict_entries, *entry_i) == 0)
			(*entry_i)++;
		line_start = line_end + 1;
	}
	return (0);
}

t_dict	*parse(int file)
{
	char	buffer[4096];
	int		entries;
	int		entry_i;
	t_dict	*dict_entries;

	entry_i = 0;
	dict_entries = (t_dict *)malloc(sizeof(t_dict) * 2048);
	if (dict_entries == NULL)
		return (NULL);
	entries = read(file, buffer, 4096);
	while (entries > 0)
	{
		buffer[entries] = '\0';
		process_buffer(buffer, dict_entries, &entry_i);
		entries = read(file, buffer, 4096);
	}
	if (entries == -1)
	{
		write(1, "Dict_Error\n", 11);
		free(dict_entries);
		return (NULL);
	}
	dict_entries[entry_i].word = NULL;
	return (dict_entries);
}
