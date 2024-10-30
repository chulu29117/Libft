/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:51:49 by clu               #+#    #+#             */
/*   Updated: 2024/10/30 14:36:50 by clu              ###   ########.fr       */
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
int	main(void)
{
	char *string = "Hello, World!";
	char *result;
	result = ft_strrchr(string, 'o');
	printf("String after |%c| is - |%s|\n", 'o', result);
	return (0);
}

// Test for ft_strstr
