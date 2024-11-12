/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:54:17 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 15:43:22 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
		ptr[i++] = 0;
}

// Test for ft_bzero /////////////////////////////////////////////////
#include <stdio.h>
#include <strings.h> // For bzero
// Helper function to print buffer
void print_buffer(const char *buffer, size_t size)
{
    for (size_t i = 0; i < size; i++)
        printf("%d ", buffer[i]);
    printf("\n");
}

// Test for zeroing the entire buffer
void test_ft_bzero_entire_buffer(void)
{
    char buffer1[10], buffer2[10];
    size_t i;

    // Initialize buffers with 'A'
    for (i = 0; i < 10; i++)
        buffer1[i] = buffer2[i] = 'A';

    // Zero the entire buffer using ft_bzero
    ft_bzero(buffer1, 10);
    // Zero the entire buffer using built-in bzero
    bzero(buffer2, 10);

    // Print and compare the buffers
    printf("ft_bzero: ");
    print_buffer(buffer1, 10); // Expected output: 0 0 0 0 0 0 0 0 0 0
    printf("bzero:    ");
    print_buffer(buffer2, 10); // Expected output: 0 0 0 0 0 0 0 0 0 0
}

// Test for zeroing the first half of the buffer
void test_ft_bzero_first_half(void)
{
    char buffer1[10], buffer2[10];
    size_t i;

    // Initialize buffers with 'A'
    for (i = 0; i < 10; i++)
        buffer1[i] = buffer2[i] = 'A';

    // Zero the first half of the buffer using ft_bzero
    ft_bzero(buffer1, 5);
    // Zero the first half of the buffer using built-in bzero
    bzero(buffer2, 5);

    // Print and compare the buffers
    printf("ft_bzero: ");
    print_buffer(buffer1, 10); // Expected output: 0 0 0 0 0 65 65 65 65 65
    printf("bzero:    ");
    print_buffer(buffer2, 10); // Expected output: 0 0 0 0 0 65 65 65 65 65
}

// Test for zeroing the second half of the buffer
void test_ft_bzero_second_half(void)
{
    char buffer1[10], buffer2[10];
    size_t i;

    // Initialize buffers with 'A'
    for (i = 0; i < 10; i++)
        buffer1[i] = buffer2[i] = 'A';

    // Zero the second half of the buffer using ft_bzero
    ft_bzero(buffer1 + 5, 5);
    // Zero the second half of the buffer using built-in bzero
    bzero(buffer2 + 5, 5);

    // Print and compare the buffers
    printf("ft_bzero: ");
    print_buffer(buffer1, 10); // Expected output: 65 65 65 65 65 0 0 0 0 0
    printf("bzero:    ");
    print_buffer(buffer2, 10); // Expected output: 65 65 65 65 65 0 0 0 0 0
}

// Test for zeroing a single element in the buffer
void test_ft_bzero_single_element(void)
{
    char buffer1[10], buffer2[10];
    size_t i;

    // Initialize buffers with 'A'
    for (i = 0; i < 10; i++)
        buffer1[i] = buffer2[i] = 'A';

    // Zero a single element in the buffer using ft_bzero
    ft_bzero(buffer1 + 5, 1);
    // Zero a single element in the buffer using built-in bzero
    bzero(buffer2 + 5, 1);

    // Print and compare the buffers
    printf("ft_bzero: ");
    print_buffer(buffer1, 10); // Expected output: 65 65 65 65 65 0 65 65 65 65
    printf("bzero:    ");
    print_buffer(buffer2, 10); // Expected output: 65 65 65 65 65 0 65 65 65 65
}

// Test for zeroing an empty buffer
void test_ft_bzero_empty_buffer(void)
{
    char buffer1[10], buffer2[10];
    size_t i;

    // Initialize buffers with 'A'
    for (i = 0; i < 10; i++)
        buffer1[i] = buffer2[i] = 'A';

    // Zero an empty buffer (n = 0) using ft_bzero
    ft_bzero(buffer1, 0);
    // Zero an empty buffer (n = 0) using built-in bzero
    bzero(buffer2, 0);

    // Print and compare the buffers
    printf("ft_bzero: ");
    print_buffer(buffer1, 10); // Expected output: 65 65 65 65 65 65 65 65 65 65
    printf("bzero:    ");
    print_buffer(buffer2, 10); // Expected output: 65 65 65 65 65 65 65 65 65 65
}

int main(void)
{
    test_ft_bzero_entire_buffer();
    test_ft_bzero_first_half();
    test_ft_bzero_second_half();
    test_ft_bzero_single_element();
    test_ft_bzero_empty_buffer();
    return 0;
}