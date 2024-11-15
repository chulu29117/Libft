/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:28:21 by clu               #+#    #+#             */
/*   Updated: 2024/11/13 15:30:23 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prototype functions //
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

// Allocates malloc and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (res);
}


// Test for ft_strjoin /////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test_ft_strjoin1()
{
    // Test case 1: Both strings are empty
    const char *s1 = "checkin ";
    const char *s2 = "event soon!";
    char *result_ft = ft_strjoin(s1, s2);
    char *result_std = strcat(strdup(s1), s2);
    printf("Test case 1:\nresult_ft = %s\nresult_std = %s\n", result_ft, result_std);
    printf("Match: %s\n\n", (strcmp(result_ft, result_std) == 0) ? "Yes" : "No");
    free(result_ft);
    free(result_std);
}

void test_ft_strjoin2()
{
    // Test case 2: First string is empty
    const char *s1 = "";
    const char *s2 = "World";
    char *result_ft = ft_strjoin(s1, s2);
    char *result_std = strcat(strdup(s1), s2);
    printf("Test case 2:\nresult_ft = %s\nresult_std = %s\n", result_ft, result_std);
    printf("Match: %s\n\n", (strcmp(result_ft, result_std) == 0) ? "Yes" : "No");
    free(result_ft);
    free(result_std);
}

void test_ft_strjoin3()
{
    // Test case 3: Second string is empty
    const char *s1 = "Hello";
    const char *s2 = "";
    char *result_ft = ft_strjoin(s1, s2);
    char *result_std = strcat(strdup(s1), s2);
    printf("Test case 3:\nresult_ft = %s\nresult_std = %s\n", result_ft, result_std);
    printf("Match: %s\n\n", (strcmp(result_ft, result_std) == 0) ? "Yes" : "No");
    free(result_ft);
    free(result_std);
}

void test_ft_strjoin4()
{
    // Test case 4: Both strings are non-empty
    const char *s1 = "Hello";
    const char *s2 = " World";
    char *result_ft = ft_strjoin(s1, s2);
    char *result_std = strcat(strdup(s1), s2);
	printf("%s\n", result_ft);
    printf("Test case 4:\nresult_ft = %s\nresult_std = %s\n", result_ft, result_std);
    printf("Match: %s\n\n", (strcmp(result_ft, result_std) == 0) ? "Yes" : "No");
    free(result_ft);
    free(result_std);
}

int	main(void)
{
    test_ft_strjoin1();
    test_ft_strjoin2();
    test_ft_strjoin3();
    test_ft_strjoin4();
    return (0);
}
/////////////////////////////////////////////////////////////////////////////

// Helper functions //
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ptr_dest;
	char		*ptr_src;

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

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (src_len + size);
	i = 0;
	while (src[i] && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}