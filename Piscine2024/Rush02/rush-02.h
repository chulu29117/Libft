#ifndef RUSH_02_H
# define RUSH_02_H
# include <unistd.h>
# include <stdlib.h>

typedef	struct s_dict
{
	int	number;
	char	*word;
}	t_dict;

void	ft_putstr(char *str);
int	is_num(char *str);
int	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
int	ft_strcmp(char *s1, char *s2);
int	ft_atoi(char *str);
char	*ft_strchr(char *str, int c);
char	*trim_space(char *str);
t_dict	*parse(int file);
char	*find_word(int number, t_dict *dict_entries);
void	num_to_word(char *number, t_dict *dict_entries);
int	ft_atoi_substr(const char *str, int start, int len);
void	process_hundreds(int num_value, t_dict *dict_entries);
void	process_group(char *number, int pos, int group_len,
		int scale_index, t_dict *dict_entries);
char	*scale_words(int index);


#endif
