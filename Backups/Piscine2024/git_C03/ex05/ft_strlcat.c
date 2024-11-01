/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:25:07 by clu               #+#    #+#             */
/*   Updated: 2024/09/11 12:25:10 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	destlen;
	unsigned int	srclen;

	destlen = 0;
	while ((dest[destlen] != '\0') && (destlen < size))
		destlen++;
	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	if (size <= destlen)
		return (size + srclen);
	i = destlen;
	j = 0;
	while ((src[j] != '\0') && (i <= size - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (i < size)
		dest[i] = '\0';
	return (destlen + srclen);
}