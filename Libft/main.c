/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:51:49 by clu               #+#    #+#             */
/*   Updated: 2024/10/31 11:09:25 by clu              ###   ########.fr       */
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
