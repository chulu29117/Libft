#include "rush-02.h"

// Function to find the corresponding word for a number in the dictionary
char	*find_word(int number, t_dict *dict_entries)
{
	int i = 0;

	while (dict_entries[i].word != NULL) 	// Loop through the dictionary until we reach the end
	{
		if (dict_entries[i].number == number) // If the number matches, return word
			return dict_entries[i].word;
		i++;
	}
	return NULL; // Return NULL if the number is not found in the dictionary
}

char	*scale_words(int index)
{
	if (index == 0)
		return ("");
	else if (index == 1)
		return (" thousand");
	else if (index == 2)
		return (" million");
	else if (index == 3)
		return (" billion");
	else if (index == 4)
		return (" trillion");
	else if (index == 5)
		return (" quadrillion");
	else if (index == 6)
		return (" quintillion");
	else if (index == 7)
		return (" sextillion");
	else if (index == 8)
		return (" septillion");
	else if (index == 9)
		return (" octillion");
	else if (index == 10)
		return (" nonillion");
	else if (index == 11)
		return (" decillion");
	else if (index == 12)
		return (" undecillion");
	else
		return (NULL);
}

void	process_group(char *number, int pos, int group_len,
		int scale_index, t_dict *dict_entries)
{
	int		num_value;
	char	*scale;

	num_value = ft_atoi_substr(number, pos, group_len);
	if (num_value != 0)
	{
		process_hundreds(num_value, dict_entries);
		scale = scale_words(scale_index);
		if (scale != NULL)
		{
			ft_putstr(scale);
			ft_putstr(" ");
		}
	}
}

void	process_hundreds(int num_value, t_dict *dict_entries)
{
	int		hundreds;
	int		remainder;
	int		tens;
	int		ones;
	char	*word;

	hundreds = num_value / 100;
	remainder = num_value % 100;
	if (hundreds > 0)
	{
		word = find_word(hundreds, dict_entries);
		if (word != NULL)
		{
			ft_putstr(word);
			ft_putstr(" ");
			word = find_word(100, dict_entries);
			if (word != NULL)
			{
				ft_putstr(word);
				ft_putstr(" ");
			}
			else
				ft_putstr("unknown ");
		}
		else
			ft_putstr("unknown ");
	}
	if (remainder > 0)
	{
		if (remainder <= 20)
		{
			word = find_word(remainder, dict_entries);
			if (word != NULL)
			{
				ft_putstr(word);
				ft_putstr(" ");
			}
			else
				ft_putstr("unknown ");
		}
		else
		{
			tens = (remainder / 10) * 10;
			ones = remainder % 10;
			word = find_word(tens, dict_entries);
			if (word != NULL)
			{
				ft_putstr(word);
				ft_putstr(" ");
			}
			else
				ft_putstr("unknown ");
			if (ones > 0)
			{
				word = find_word(ones, dict_entries);
				if (word != NULL)
				{
					ft_putstr(word);
					ft_putstr(" ");
				}
				else
					ft_putstr("unknown ");
			}
		}
	}
}

void	num_to_word(char *number, t_dict *dict_entries)
{
	int		len;
	int		group_count;
	int		group_index;
	int		start;
	int		group_len;
	int		pos;
	int		num_value;
	int		scale_index;
	char	*scale;

	len = ft_strlen(number);
	pos = 0;
	group_count = (len + 2) / 3;
	if (group_count > 12)
	{
		ft_putstr("Number too large\n");
		return ;
	}
	start = len % 3;
	if (start == 0)
		start = 3;
	group_index = 0;
	while (group_index < group_count)
	{
		if (group_index == 0)
			group_len = start;
		else
			group_len = 3;
		num_value = ft_atoi_substr(number, pos, group_len);
		if (num_value != 0)
		{
			process_hundreds(num_value, dict_entries);
			scale_index = group_count - group_index - 1;
			scale = scale_words(scale_index);
			if (scale != NULL && scale[0] != '\0')
			{
				ft_putstr(scale);
				ft_putstr(" ");
			}
		}
		pos += group_len;
		group_index++;
	}
	ft_putstr("\n");
}

