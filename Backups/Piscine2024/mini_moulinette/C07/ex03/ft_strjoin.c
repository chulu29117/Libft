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
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		maxlen;
	char	*res;

	i = 0;
	maxlen = 0;
	while (i < size)
		maxlen = maxlen + ft_strlen(strs[i++]);
	if (size > 0)
		maxlen = maxlen + (size - 1) * ft_strlen(sep);
	res = (char *) malloc((maxlen + 1) * sizeof (char));
	res[0] = '\0';
	if (res == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		res = ft_strcat(res, strs[i]);
		if (i < size - 1)
			res = ft_strcat(res, sep);
		i++;
	}
	res[maxlen] = '\0';
	return (res);
}

/*int	main(int argc, char *argv[])
{
	int	size;
	
	size = atoi(argv[1]);
	
	if (argc != 4)
	{
		printf("1 Inputs required: size, str, sep\n");
		return (1);
	}
	else	
		printf("%s ", ft_strjoin(size, &argv[2], argv[3]));
	return (0);
}*/
