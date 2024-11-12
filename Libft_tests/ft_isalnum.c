/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:01:51 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 14:42:04 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function prototypes //
int	ft_isalpha(int c);
int	ft_isdigit(int c);

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
	return (0);
}

// Test for ft_isalnum //
#include <stdio.h>
#include <ctype.h> // For isalnum

void test_ft_isalnum()
{
    char test_chars[] = {'a', 'Z', '5', '!', ' ', '0', '9', 'b', 'G'};
    size_t i = 0;
    while (i < sizeof(test_chars))
    {
        int result_ft = ft_isalnum(test_chars[i]);
        int result_std = isalnum(test_chars[i]);
        printf("ft_isalnum('%c') = %d, isalnum('%c') = %d, Match: %s\n",
               test_chars[i], result_ft, test_chars[i], result_std,
               (result_ft == result_std) ? "Yes" : "No");
        i++;
    }
}

int main()
{
    test_ft_isalnum();
    return 0;
}

// Helper functions for ft_isalnum //
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}