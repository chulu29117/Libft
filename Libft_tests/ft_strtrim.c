/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:47:11 by clu               #+#    #+#             */
/*   Updated: 2024/11/04 20:35:15 by clu              ###   ########.fr       */
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

// Function to locate the first occurrence of character c in string s
char	*ft_strchr(const char *s, int c)
{
	int	i;
	unsigned char	uc;

	uc = (unsigned char)c; 	// Convert c to unsigned char
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == uc) 	// If character is found, return pointer to it
			return ((char *) &s[i]);
		i++;
	}
	if (uc == '\0') // If c is '\0', return pointer to the null terminator
		return ((char *) &s[i]);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*last_occurrence;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	last_occurrence = 0;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			last_occurrence = (char *) & s[i];
		i++;
	}
	if (s[i] == uc)
		last_occurrence = (char *) & s[i];
	return (last_occurrence);
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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start])) 	// Find the start index
		start++;
	end = ft_strlen(s1); 	// Get the length of the string
	while (end > start && ft_strrchr(set, s1[end - 1])) 	// Find the end index
		end--;
	trimmed = (char *)malloc(sizeof(char) * (end - start + 1)); // Allocate memory for the trimmed string
	if (!trimmed) 			// Check for memory allocation failure
		return (NULL);
	ft_memcpy(trimmed, &s1[start], end - start); 	// Copy the trimmed string
	trimmed[end - start] = '\0';
	return (trimmed);
}

// Test for ft_strtrim
#include <stdio.h>

int	main(void)
{
	char	*s1 = "***Hello, World!***";
	char	*set = "*";
	char	*result;

	result = ft_strtrim(s1, set);
	if (result)
	{
		printf("Original: '%s'\n", s1);
		printf("Trimmed: '%s'\n", result);
		free(result);
	}
	else
		printf("Trimming failed.\n");
	return (0);
}
