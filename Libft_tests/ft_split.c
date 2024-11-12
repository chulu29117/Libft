/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:53:40 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 10:15:12 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prototype functions //
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
static size_t	count_words(char const *s, char c);
static char		*get_next_word(char const *s, char c, size_t *i);
static void		ft_freearray(char **split, size_t j);
static void		write_split(char **split, char const *s, char c);

// ft_split splits the string s using the delimiter c and returns an array of strings.
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

// Test for ft_split
#include <stdio.h>

int	main(void)
{
	char	**split;
	int		i;

	// Test case 1: Normal case with spaces
	split = ft_split("Hello Good Morning World This is a Test", ' ');
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	ft_freearray(split, i);
	printf("\n");

	// Test case 2: Single word
	split = ft_split("hello!", ' ');
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	ft_freearray(split, i);
	printf("\n");

	// Test case 3: Empty string
	split = ft_split("", ' ');
	if (split[0] == NULL)
		printf("Empty string test passed\n");
	ft_freearray(split, 0);
	printf("\n");

	// Test case 4: String with only delimiters
	split = ft_split("     ", ' ');
	if (split[0] == NULL)
		printf("Only delimiters test passed\n");
	ft_freearray(split, 0);
	printf("\n");

	// Test case 5: String with leading delimiters
	split = ft_split("   Leading spaces", ' ');
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	ft_freearray(split, i);
	printf("\n");

	// Test case 6: String with trailing delimiters
	split = ft_split("Trailing spaces   ", ' ');
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	ft_freearray(split, i);
	printf("\n");

	// Test case 7: String with multiple consecutive delimiters
	split = ft_split("Multiple   spaces   between   words", ' ');
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	ft_freearray(split, i);
	printf("\n");

	// Test case 8: String with different delimiter
	split = ft_split("Comma,separated,values", ',');
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	ft_freearray(split, i);
	printf("\n");

	// Test case 9: NULL string
	split = ft_split(NULL, ' ');
	if (split == NULL)
		printf("NULL string test passed\n");
}

/// Helper functions ///
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

// Function to extract a substring from the string s starting at index start and of length len
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
	while (s[i] && s[i] == c)
		i++;
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
	if (!word)	// If the word is NULL, free the memory allocated
	{
		*i = end;	// Update the index to the end of the current word
		return (NULL);
	}
	*i = end; 		// Update the index to the end of the current word
	return (word);
}

// Function to free the memory allocated for the split array
static void	ft_freearray(char **split, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// Function to write the words to the split array
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
			// Extract the next word from the string
			split[j] = get_next_word(s, c, &i);
			// If the word is NULL, free the memory allocated
			if (!split[j])
				ft_freearray(split, j);
			j++;
		}
		else
			i++;
	}
	split[j] = NULL;
}
