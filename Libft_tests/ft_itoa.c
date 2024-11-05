/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:57:03 by clu               #+#    #+#             */
/*   Updated: 2024/11/05 12:52:53 by clu              ###   ########.fr       */
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

// Used to duplicate the min integer value
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

// Calculate the number of digits in the number
static int	count_digits(int n)
{
	int	digits;

	digits = 0;
	if (n <= 0)		// If n is negative or zero, add one digit for the sign
		digits++;
	while (n != 0)	// Count the number of digits in the number	 
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}
static void	ft_putnbr(char *str, int n, int digits)
{
	int	sign;
	int	i;
	// Set the sign of the number
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	// Convert the number to a string
	i = digits - 1;
	while (i >= 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	// Add the sign to the string
	if (sign == -1)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	// Declare variables
	char	*str;
	int		digits;
	
	// Check for minimum integer value
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	// Calculate the number of digits in the number
	digits = count_digits(n);
	// Allocate memory for the string
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	ft_putnbr(str, n, digits);
	str[digits] = '\0';
	return (str);	
}

// Test for ft_itoa
#include <stdio.h>

int	main(void)
{
	int		n;
	char	*str;

	n = -123456;
	str = ft_itoa(n);
	if (str)
	{
		printf("Number: %d\n", n);
		printf("String: %s\n", str);
		free(str);
	}
	return (0);
}