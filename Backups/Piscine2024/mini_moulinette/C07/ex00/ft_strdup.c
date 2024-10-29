/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:12:50 by clu               #+#    #+#             */
/*   Updated: 2024/09/16 16:12:52 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int	len(char *str)
{
	int	i;
	int	count;
	count = 0;
	i = 0;
	while (str[i])
	{
		count++;
		i++;
	}
	return (count);
}
char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;
	ptr = (char *) malloc(len(src) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*int	main(int argc, char *argv[])
{
	if (argc == 2)
		printf("String duplicate: %s\n", ft_strdup(argv[1]));
	return (0);
}
*/
