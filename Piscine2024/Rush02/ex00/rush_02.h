/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datikhom <datikhom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:52:51 by datikhom          #+#    #+#             */
/*   Updated: 2024/09/22 20:05:24 by datikhom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

typedef struct s_dict
{
	int		number;
	char	*word;
}	t_dict;

typedef struct s_group_info
{
	char	*number;
	int		pos;
	int		group_len;
	int		scale_index;
}	t_group_info;

t_dict	*parse(int file);

void	ft_putstr(char *str);
char	*trim_space(char *str);

char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
char	*ft_strchr(char *str, int c);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

void	process_hundreds(int num_value, t_dict *dict_entries);
void	process_remainder(int remainder, t_dict *dict_entries);
void	print_word(int number, t_dict *dict_entries);
void	print_scale(int scale_index);
char	*find_word(int number, t_dict *dict_entries);
char	*scale_words(int index);
int		get_group_len(int group_index, int start);
int		is_num(char *str);
int		ft_atoi(char *str);
int		ft_atoi_substr(const char *str, int start, int len);

void	num_to_word(char *number, t_dict *dict_entries);
void	process_group_loop(char *number, int group_count,
			int start, t_dict *dict_entries);
void	process_group_word(t_group_info group, t_dict *dict_entries);
int		get_group_start(int len);

#endif
