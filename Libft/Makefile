# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clu <clu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 15:08:55 by clu               #+#    #+#              #
#    Updated: 2024/10/31 14:12:40 by clu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_DIR = srcs
INC_DIR = includes

SRC_FILES = ft_bzero.c    ft_isascii.c  ft_memchr.c   ft_memset.c   ft_strlcpy.c  \
ft_strnstr.c  ft_toupper.c ft_isalnum.c  ft_isdigit.c  ft_memcpy.c   ft_strchr.c  \
ft_strlen.c   ft_strrchr.c  main.c ft_isalpha.c  ft_isprint.c  ft_memmove.c  \
ft_strlcat.c  ft_strncmp.c  ft_tolower.c 


OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $@ $^

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all