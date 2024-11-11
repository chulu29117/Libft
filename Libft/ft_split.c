/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:51:38 by clu               #+#    #+#             */
/*   Updated: 2024/11/11 14:40:00 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static char		*get_next_word(char const *s, char c, size_t *i);
static void		ft_freearray(char **split, size_t j);
static void		write_split(char **split, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	write_split(split, s, c);
	return (split);
}

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*get_next_word(char const *s, char c, size_t *i)
{
	size_t	start;
	size_t	end;
	char	*word;

	start = *i;
	while (s[start] && s[start] == c)
		start++;
	end = start;
	while (s[end] && s[end] != c)
		end++;
	word = ft_substr(s, start, end - start);
	if (!word)
	{
		*i = end;
		return (NULL);
	}
	*i = end;
	return (word);
}

static void	ft_freearray(char **split, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

static void	write_split(char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			split[j] = get_next_word(s, c, &i);
			if (!split[j])
			{
				ft_freearray(split, j);
			}
			j++;
		}
		else
			i++;
	}
	split[j] = NULL;
}
