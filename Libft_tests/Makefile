# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clu <clu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 15:08:55 by clu               #+#    #+#              #
#    Updated: 2024/11/12 09:40:33 by clu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SOURCES = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strlcpy.c \
ft_strnstr.c ft_toupper.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strchr.c \
ft_strlen.c ft_strrchr.c ft_isascii.c ft_memchr.c ft_memmove.c ft_strlcat.c ft_strncmp.c \
ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_striteri.c 

BONUS_SOURCES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

all: $(NAME)

# Compile and run tests for the Libft library.
$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS) 		# ar: Archive utility used to create static libraries.
		     						# r: Insert the files ($^) into the archive, replacing older files.
		     						# c: Create the archive if it doesn't exist.
									# s: Write an index to the archive, or update an existing index.

# Compile and run tests for the Libft library with bonus functions.
bonus: $(OBJECTS) $(BONUS_OBJECTS)
	@ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 	# $<: The first prerequisite (the source file).
									# $@: The target file (the object file).
									# -c: Compiles the source file without linking.
									# -o: Specifies the output file name (the object file).

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
