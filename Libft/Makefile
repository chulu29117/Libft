# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clu <clu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 15:08:55 by clu               #+#    #+#              #
#    Updated: 2024/11/05 16:49:21 by clu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SOURCES = sources
INCLUDES = includes

SOURCES = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strlcpy.c \
ft_strnstr.c ft_toupper.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strchr.c \
ft_strlen.c ft_strrchr.c ft_isascii.c ft_memchr.c ft_memmove.c ft_strlcat.c ft_strncmp.c \
ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
ft_itoa.c ft_strmapi.c ft_putchar_fd.c

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(SOURCES) -I libft.h -c $< -o $@

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
