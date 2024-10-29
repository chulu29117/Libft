# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clu <clu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 15:16:02 by clu               #+#    #+#              #
#    Updated: 2024/09/22 15:16:37 by clu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

# Source files
SRCS    = rush-02.c \
          utils.c \
          dictionary.c \
          number_to_words.c

# Object files
OBJS    = $(SRCS:.c=.o)

# Executable name
NAME    = rush-02

# Default rule
all: $(NAME)

# Rule to build the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Rule to compile source files into object files
%.o: %.c rush-02.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean object files and executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all
