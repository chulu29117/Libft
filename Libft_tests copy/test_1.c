/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:47:52 by clu               #+#    #+#             */
/*   Updated: 2024/11/11 16:50:52 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	// Test for ft_atoi
	char	*str1 = "2532452452345345";
	char	*str2 = "-2532452452345345";
	char	*str3 = "2147483647"; // INT_MAX
	char	*str4 = "-2147483648"; // INT_MIN
	char	*str5 = "42";
	char	*str6 = "   -42";
	char	*str7 = "4193 with words";
	char	*str8 = "words and 987";
	char	*str9 = "-91283472332";
	char	*str10 = "91283472332";
	int		result;

	result = ft_atoi(str1);
	printf("Result for \"%s\": %d\n", str1, result);
	result = ft_atoi(str2);
	printf("Result for \"%s\": %d\n", str2, result);
	result = ft_atoi(str3);
	printf("Result for \"%s\": %d\n", str3, result);
	result = ft_atoi(str4);
	printf("Result for \"%s\": %d\n", str4, result);
	result = ft_atoi(str5);
	printf("Result for \"%s\": %d\n", str5, result);
	result = ft_atoi(str6);
	printf("Result for \"%s\": %d\n", str6, result);
	result = ft_atoi(str7);
	printf("Result for \"%s\": %d\n", str7, result);
	result = ft_atoi(str8);
	printf("Result for \"%s\": %d\n", str8, result);
	result = ft_atoi(str9);
	printf("Result for \"%s\": %d\n", str9, result);
	result = ft_atoi(str10);
	printf("Result for \"%s\": %d\n", str10, result);

	// Test for ft_bzero
	char buffer1[10];
	char buffer2[10];
	size_t i;

	// Test case 1: Zero the entire buffer
	i = 0;
	while (i < 10) 
		buffer1[i++] = 'A';
	ft_bzero(buffer1, 10);
	i = 0;
	while (i < 10) 
		printf("%d ", buffer1[i++]); // Output: 0 0 0 0 0 0 0 0 0 0
	printf("\n");

	// Test case 2: Zero the first half of the buffer
	i = 0;
	while (i < 10) 
		buffer2[i++] = 'A';
	ft_bzero(buffer2, 5);
	i = 0;
	while (i < 10) 
		printf("%d ", buffer2[i++]); // Output: 0 0 0 0 0 65 65 65 65 65
	printf("\n");
	return (0);

	// Test for ft_calloc
	int		*ptr;
	int		i;
	int		n;

	n = 5;
	ptr = (int *)ft_calloc(n, sizeof(int));
	i = 0;
	while (i < n)
		printf("%d\n", ptr[i++]);
	// free memory
	free(ptr);

	return (0);	
}