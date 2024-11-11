/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:47:11 by clu               #+#    #+#             */
/*   Updated: 2024/11/04 20:38:07 by clu              ###   ########.fr       */
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
	// Find the start index
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	// Find the end index
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	// Allocate memory for the trimmed string
	trimmed = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!trimmed)
		return (NULL);
	// Copy the trimmed string
	ft_memcpy(trimmed, &s1[start], end - start);
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
