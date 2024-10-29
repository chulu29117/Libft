/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:13:29 by clu               #+#    #+#             */
/*   Updated: 2024/09/24 16:13:32 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sep(char c, char *charset)
{
	int = i;
	
	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_string(char *str)
{
	int	i;
	int	count;
	int	flag;
	
	i = 0;
	count = 0;
	flag = 0;
	while (str[count])
	{
		if (!ft_sep(str[count], charset) && flag == 0)
		{
			count++;
			flag = 1;
		}
			
		

char	**ft_split(char *str, char *charset)
{
	
