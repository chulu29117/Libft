/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:03:13 by clu               #+#    #+#             */
/*   Updated: 2024/11/01 11:57:24 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
typedef unsigned long	t_size_t;
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_strlen(char *str);
void		*ft_memset(void *s, int c, t_size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *str, const char *to_find, t_size_t len);
t_size_t	ft_strlcpy(char *dest, const char *src, t_size_t size);
t_size_t	ft_strlcat(char *dest, const char *src, t_size_t size);
void		ft_bzero(void *s, t_size_t n);
void		*ft_memcpy(void *dest, const void *src, t_size_t n);
void		*ft_memmove(void *dest, const void *src, t_size_t n);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_strncmp(const char *s1, const char *s2, t_size_t n);
void		*ft_memchr(const void *s, int c, t_size_t n);
int			ft_memcmp(const void *s1, const void *s2, t_size_t n);
int			ft_atoi(const char *str);

#endif
