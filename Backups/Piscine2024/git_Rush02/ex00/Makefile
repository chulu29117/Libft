# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: datikhom <datikhom@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 15:16:02 by clu               #+#    #+#              #
#    Updated: 2024/09/22 18:34:30 by datikhom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = rush-02.c \
          dictionary.c \
          func_num_1.c \
          func_num_2.c \
          func_strings.c \
          func_out.c \
          number_to_words.c

OBJS    = $(SRCS:.c=.o)

NAME    = rush-02

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c rush-02.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
