/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:54:31 by clu               #+#    #+#             */
/*   Updated: 2024/09/18 17:56:23 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// These lines are header guards, which prevent the content of this file from being included multiple times during the compilation process. It ensures that FT_H is defined only once.
#ifndef FT_H
# define FT_H

// Function prototypes
void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif //End of the header guard
