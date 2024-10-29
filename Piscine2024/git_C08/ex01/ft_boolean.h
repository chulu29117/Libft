/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:58:27 by clu               #+#    #+#             */
/*   Updated: 2024/09/18 18:13:28 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

// Macros in C are a way to define code snippets or constants that can be reused throughout your program. They are handled by the preprocessor before the actual compilation of the code begins. Macros allow you to avoid hard-coding values or repeating code, making the program more flexible and maintainable.

// Object-like Macros (Constants)
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define SUCCESS 0
# define TRUE 1
# define FALSE 0

// Function-like Macros (Code Snippets)
# define EVEN(nbr) ((nbr) % 2 == 0)

// Function prototypes
void	ft_putstr(char *str);		// Print string

typedef int	t_bool;			// Defines t_bool as an alias for int
t_bool	ft_is_even(int nbr);		// Checks the nbr and returns t_bool

#endif
