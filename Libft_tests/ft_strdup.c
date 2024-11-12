/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:00:47 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 15:57:30 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prototype functions //
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_strdup(const char *s1)
{
	char		*ptr;
	size_t		len;

	len = ft_strlen(s1) + 1;	// +1 for the null-terminator
	ptr = (char *)malloc(len); 	// Allocate memory for the string
	if (ptr == NULL)			// If malloc fails, return 0
		return (NULL);
	ft_memcpy(ptr, s1, len);	// Copy the string to the allocated memory
	return (ptr);
}

// Test for ft_strdup /////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test_ft_strdup1()
{
	// Test case 1: String is empty
	const char *str = "";
	char *result_ft = ft_strdup(str);
	char *result_std = strdup(str);
	printf("Test case 1:\nresult_ft = %s\nresult_std = %s\n", result_ft, result_std);
	printf("Match: %s\n\n", (strcmp(result_ft, result_std) == 0) ? "Yes" : "No");
	free(result_ft);
	free(result_std);
}

void test_ft_strdup2()
{
	// Test case 2: String is not empty
	const char *str = "Hello, World!";
	char *result_ft = ft_strdup(str);
	char *result_std = strdup(str);
	printf("Test case 2:\nresult_ft = %s\nresult_std = %s\n", result_ft, result_std);
	printf("Match: %s\n\n", (strcmp(result_ft, result_std) == 0) ? "Yes" : "No");
	free(result_ft);
	free(result_std);
}

void test_ft_strdup3()
{
	// Test case 3: String is a single character
	const char *str = "H";
	char *result_ft = ft_strdup(str);
	char *result_std = strdup(str);
	printf("Test case 3:\nresult_ft = %s\nresult_std = %s\n", result_ft, result_std);
	printf("Match: %s\n\n", (strcmp(result_ft, result_std) == 0) ? "Yes" : "No");
	free(result_ft);
	free(result_std);
}

void test_ft_strdup4()
{
	// Test case 4: String is a single character
	const char *str = "H";
	char *result_ft = ft_strdup(str);
	char *result_std = strdup(str);
	printf("Test case 4:\nresult_ft = %s\nresult_std = %s\n", result_ft, result_std);
	printf("Match: %s\n\n", (strcmp(result_ft, result_std) == 0) ? "Yes" : "No");
	free(result_ft);
	free(result_std);
}

int	main(void)
{
	test_ft_strdup1();
	test_ft_strdup2();
	test_ft_strdup3();
	test_ft_strdup4();
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