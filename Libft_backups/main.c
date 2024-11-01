/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:51:49 by clu               #+#    #+#             */
/*   Updated: 2024/11/01 10:27:00 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

// Test for ft_isalpha
// int	main(void)
// {
// 	printf("ft_isalpha('Q') = %d\n", ft_isalpha('Q'));
// 	printf("ft_isalpha('7') = %d\n", ft_isalpha('7'));
// 	printf("ft_isalpha('Y') = %d\n", ft_isalpha('Y'));
// 	printf("ft_isalpha('@') = %d\n", ft_isalpha('@'));
// 	return 0;
// }

// Test for ft_isdigit
// int	main(void)
// {
// 	printf("ft_isdigit('Q') = %d\n", ft_isdigit('Q'));
// 	printf("ft_isdigit('7') = %d\n", ft_isdigit('7'));
// 	printf("ft_isdigit('3') = %d\n", ft_isdigit('3'));
// 	printf("ft_isdigit('@') = %d\n", ft_isdigit('@'));
// 	return 0;
// }

// Test for ft_isalnum
// int	main(void)
// {
// 	printf("ft_isalnum('Q') = %d\n", ft_isalnum('Q'));
// 	printf("ft_isalnum('7') = %d\n", ft_isalnum('7'));
// 	printf("ft_isalnum(' ') = %d\n", ft_isalnum(' '));
// 	printf("ft_isalnum('@') = %d\n", ft_isalnum('@'));
// 	return 0;
// }

// Test for ft_isascii
// int	main(void)
// {
// 	printf("ft_isascii('Q') = %d\n", ft_isascii('Q'));
// 	printf("ft_isascii('7') = %d\n", ft_isascii('7'));
// 	printf("ft_isascii(-123) = %d\n", ft_isascii(-123));
// 	printf("ft_isascii(402) = %d\n", ft_isascii(402));
// 	return (0);
// }

// // Test for ft_isprint
// int	main(void)
// {
// 	printf("ft_isprint('Q') = %d\n", ft_isprint('Q'));
// 	printf("ft_isprint('7') = %d\n", ft_isprint('7'));
// 	printf("ft_isprint(-129) = %d\n", ft_isprint(-129));
// 	printf("ft_isprint(128) = %d\n", ft_isprint(128));
// 	return (0);
// }

// Test for ft_strlen
// int	main(void)
// {
// 	int	string;

// 	string = ft_strlen("Hello");
// 	printf("Number of characters: %d\n", string);
// 	return (0);
// }

// Test for ft_memset
// int	main(void)
// {
// 	char	str[50] = "Hello, World!";
// 	ft_memset(str, '*', 5);
// 	printf("After memset: %s\n", str);
// 	return (0);
// }

// Test for ft_strchr
// int	main(void)
// {
// 	char *string = "Hello, World!";
// 	char *result;
// 	result = ft_strchr(string, 'o');
// 	printf("String after |%c| is - |%s|\n", 'o', result);
// 	return (0);
// }

// Test for ft_strrchr
// int	main(void)
// {
// 	char	*string = "Hello, World!";
// 	char	*result;
// 	result = ft_strrchr(string, 'o');
// 	printf("String after |%c| is - |%s|\n", 'o', result);
// 	return (0);
// }

// Test for ft_strnstr
// int	main(void)
// {
// 	char	src[20] = "Hello, World!";
// 	char	dest[10];
// 	t_size_t	result;

// 	result = ft_strlcpy(dest, src, 8);
// 	printf("Source string: %s\n", src);
// 	printf("Destination string: %s\n", dest);
// 	printf("Result: %ld\n", result);
// 	return (0);
// }

// Test for ft_strlcat
// int	main(void)
// {
// 	char	dest[] = "Hello";
// 	char	src[] = "Good Morning World";

// 	printf("src: %s dest: %s\n", src, dest);
// 	printf("Dest with size n: %ld\n", ft_strlcat(dest, src, 3));
// 	printf("dest: %s\n", dest);
// 	return (0);
// }

// Test for ft_bzero
// int	main(void) 
// {
// 	char buffer[10];
// 	t_size_t i;
// 	// Fill buffer with non-zero values using a while loop
// 	i = 0;
// 	while (i < 10) {
// 		buffer[i] = 'A';
// 		i++;
// 	}
// 	// Zero out the buffer using ft_bzero
// 	ft_bzero(buffer, 10);
// 	// Print the buffer contents using a while loop
// 	i = 0;
// 	while (i < 10) {
// 		printf("%d ", buffer[i]); // Output: 0 0 0 0 0 0 0 0 0 0
// 		i++;
// 	}
// 	printf("\n");
// 	return (0);
// }

// Test for ft_memcpy
// int	main(void)
// {
// 	char	src[30] = "Hello, World!";
// 	char	dest[30] = "Good Morning!";
// 	char	*result;

// 	result = ft_memcpy(dest, src, 5);
// 	printf("Result: %s\n", result);
// 	return (0);
// }

// Test for ft_memmove
// int	main(void)
// {
// 	char src[] = "Hello, World!";
// 	char dest[] = "Good Morning!";

// 	printf("Before memmove, src: %s, dest: %s\n", src, dest);
// 	ft_memmove(dest, src, 14);
// 	printf("After memmove, src: %s, dest: %s\n", src, dest);
// 	return (0);
// }

// Test for ft_mmmove overlapped case
int main(void)
{
    char buffer[] = "Hello, World!";
    // Overlapping case: `dest` starts partway into `src`
    char *src = buffer;
    char *dest = buffer + 7; // Points to 'W' in "World!"

    printf("Before memmove, buffer: \"%s\"\n", buffer);
    // Move 6 bytes from src to dest within the same buffer, causing overlap
    ft_memmove(dest, src, 6);
    printf("After memmove, buffer: \"%s\"\n", buffer);
    return (0);
}

// Test for ft_toupper
// int	main(void)
// {
// 	printf("ft_toupper('Q') = %c\n", ft_toupper('Q'));
// 	printf("ft_toupper('7') = %c\n", ft_toupper('7'));
// 	printf("ft_toupper('y') = %c\n", ft_toupper('y'));
// 	printf("ft_toupper('a') = %c\n", ft_toupper('a'));
// 	return (0);
// }

// Test for ft_tolower
// int	main(void)
// {
// 	printf("ft_tolower('Q') = %c\n", ft_tolower('Q'));
// 	printf("ft_tolower('7') = %c\n", ft_tolower('7'));
// 	printf("ft_tolower('y') = %c\n", ft_tolower('y'));
// 	printf("ft_tolower('A') = %c\n", ft_tolower('A'));
// 	return (0);
// }

// Test for ft_strncmp
// int	main(void)
// {
// 	char		*str1 = "Hello, World!";
// 	char		*str2 = "Morning!";
// 	t_size_t	n = 5;

// 	printf("ft_strncmp: %d\n", ft_strncmp(str1, str2, n));
// 	return (0);
// }

// Test for ft_memchr
// int	main(void)
// {
// 	char		*str = "Hello, World!";
// 	char		*result;
// 	int			c = 'W';
// 	t_size_t	n = 13;

// 	result = ft_memchr(str, c, n);
// 	printf("String after %c is - %s\n", c, result);
// 	return (0);
// }

// Test for ft_memcmp
// int	main(void)
// {
// 	char		*str1 = "Hello, World!";
// 	char		*str2 = "World!";
// 	t_size_t	n = 13;

// 	printf("ft_memcmp: %d\n", ft_memcmp(str1, str2, n));
// 	return (0);
// }

// Test for ft_atoi
// int	main(void)
// {
// 	char	*str = "-12345";
// 	int		result;

// 	result = ft_atoi(str);
// 	printf("Result: %d\n", result);
// 	return (0);
// }
