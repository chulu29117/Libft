#include <stdio.h>
#include <string.h>

// Test for ft_memmove

int main(void)
{
    char src[] = "Hello, World!";
    char dest[] = "Good Morning!";

    printf("Before memmove, src: %s, dest: %s\n", src, dest);
    ft_memmove(dest, src, 14);
    printf("After memmove, src: %s, dest: %s\n", src, dest);

    // Additional test cases
    char src2[] = "Hello";
    char dest2[] = "World";

    printf("Before memmove, src2: %s, dest2: %s\n", src2, dest2);
    ft_memmove(dest2, src2, 5);
    printf("After memmove, src2: %s, dest2: %s\n", src2, dest2);

    char src3[] = "123456789";
    char dest3[] = "abcdefghi";

    printf("Before memmove, src3: %s, dest3: %s\n", src3, dest3);
    ft_memmove(dest3, src3, 9);
    printf("After memmove, src3: %s, dest3: %s\n", src3, dest3);

    return 0;
}
#include <string.h>
// Test for ft_memmove
int main(void)
{
    char src[] = "Hello, World!";
    char dest[] = "Good Morning!";
    printf("Before memmove, src: %s, dest: %s\n", src, dest);
    ft_memmove(dest, src, 14);
    printf("After memmove, src: %s, dest: %s\n", src, dest);
    // Additional test cases
    char src2[] = "Hello";
    char dest2[] = "World";
    printf("Before memmove, src2: %s, dest2: %s\n", src2, dest2);
    ft_memmove(dest2, src2, 5);
    printf("After memmove, src2: %s, dest2: %s\n", src2, dest2);
    char src3[] = "123456789";
    char dest3[] = "abcdefghi";
    printf("Before memmove, src3: %s, dest3: %s\n", src3, dest3);
    ft_memmove(dest3, src3, 9);
    printf("After memmove, src3: %s, dest3: %s\n", src3, dest3);
    char src4[] = "Hello, World!";
    char dest4[] = "Good Morning!";
    printf("Before memmove, src4: %s, dest4: %s\n", src4, dest4);
    ft_memmove(dest4, src4, 5);
    printf("After memmove, src4: %s, dest4: %s\n", src4, dest4);
    char src5[] = "123456789";
    char dest5[] = "abcdefghi";
    printf("Before memmove, src5: %s, dest5: %s\n", src5, dest5);
    ft_memmove(dest5, src5, 3);
    printf("After memmove, src5: %s, dest5: %s\n", src5, dest5);
    return 0;
}