/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:08:36 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 15:43:41 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Test for ft_isalpha /////////////////////////////////////////////////
#include <stdio.h>
#include <ctype.h> // For isalpha

void test_ft_isalpha()
{
    char test_chars[] = {'a', 'Z', '5', '!', ' ', 'b', 'G'};
    size_t i = 0;
    while (i < sizeof(test_chars))
    {
        int result_ft = ft_isalpha(test_chars[i]);
        int result_std = isalpha(test_chars[i]);
        printf("ft_isalpha('%c') = %d, isalpha('%c') = %d, Match: %s\n",
               test_chars[i], result_ft, test_chars[i], result_std,
               (result_ft == result_std) ? "Yes" : "No");
        i++;
    }
}

int main()
{
    test_ft_isalpha();
    return 0;
}