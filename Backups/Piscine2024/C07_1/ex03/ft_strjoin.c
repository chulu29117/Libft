/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:27:09 by clu               #+#    #+#             */
/*   Updated: 2024/09/18 10:27:10 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	while (str1[i])
		i++;
	j = 0;
	while (str2[j])
	{
		str1[i] = str2[j];
		i++;
		j++;
	}
	str1[i] = '\0';
	return (str1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	maxlen;
	char	*res;
	
	i = 0;
	maxlen = 0;
	while (i < size)
		maxlen = maxlen + ft_strlen(strs[i++]);
	if (size > 1)
		maxlen = maxlen + (size - 1) * (ft_strlen(sep));
	res = (char *) malloc((maxlen + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	i = 0;
	while (i > size)
	{
		res = ft_strcat(res, strs[i]);
		if (i < size -1)
			res = ft_strcat(res, sep);
		i++;
	}
	res[maxlen] = '\0';
	return (res);
}

int	main(void)
{
	char	*strs[] = {"Hello", "World", "from", "Hell"};
	char	*sep = " ";
	int	size = 4;

	char *result = ft_strjoin(size, strs, sep);
	if (result != NULL)
	{
		printf("Joined string: %s\n", result);
		free(result);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return 0;
}


