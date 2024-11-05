/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:53:40 by clu               #+#    #+#             */
/*   Updated: 2024/11/05 10:54:25 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char		*ptr;
	size_t		len;

	len = ft_strlen(s1) + 1;
	ptr = (char *)malloc(len);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, len);
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ptr_dest;
	char		*ptr_src;

	if (!dest && !src && n > 0)
		return (NULL);
	i = 0;
	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	actual_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	actual_len = ft_strlen(s + start);
	if (len > actual_len)
		len = actual_len;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// Function to count the number of words in the string separated by the delimiter
static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;			// Increment word count when a non-delimiter character is found
			while (s[i] && s[i] != c)
				i++;			// Skip the characters of the current word
		}
		else
			i++;				// Skip the delimiter
	}
	return (words);				// Return the total number of words found
}

// Function to extract the next word from the string at index i
static char	*get_next_word(char const *s, char c, size_t *i)
{
	size_t	start;
	size_t	end;
	char	*word;

	start = *i;
	// Skip any delimiter characters at the start of the word
	while (s[start] && s[start] == c)
		start++;
	end = start;
	// Find the end of the word by skipping the characters of the word
	while (s[end] && s[end] != c)
		end++;
	// Extract the word using ft_substr
	word = ft_substr(s, start, end - start);
	*i = end; 			// Update the index to the end of the current word
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split; 	// Array of strings to store the words
	size_t	words;
	size_t	i;			// Index of the current character in the string
	size_t	j;			// Index of the current word in the array

	if (!s)
		return (NULL);
	// Count the number of words in the string
	words = count_words(s, c);
	// Allocate memory for the array of strings
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	// Extract the words from the string
	while (s[i])
	{
		if (s[i] != c)
		{
			split[j] = get_next_word(s, c, &i); // Extract the next word
			j++;
		}
		else	// Skip the delimiter
			i++;
	}
	split[j] = NULL; // Set the last element of the array
	return (split);
}

// Test for ft_split
#include <stdio.h>

int	main(void)
{
	char	**split;
	char	**split_1;

	int		i;

	split = ft_split("Hello Good Morning World This is a Test", ' ');
	split_1 = ft_split("Hello,Good,Morning,World,This,is,a,Test", ',');
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (split_1[i])
	{
		printf("%s\n", split_1[i]);
		i++;
	}
	// Free the memory allocated
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	// Free the memory allocated
	i = 0;
	while (split_1[i])
	{
		free(split_1[i]);
		i++;
	}
	free(split_1);
	return (0);
}
