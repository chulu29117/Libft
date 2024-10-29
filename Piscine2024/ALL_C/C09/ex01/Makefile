# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clu <clu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 16:48:44 by clu               #+#    #+#              #
#    Updated: 2024/09/23 16:48:46 by clu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = cc
# Compiler flags
CFLAGS = -Wall -Werror -Wextra
# Directories
SRC_DIR = srcs
INC_DIR = includes
# Source files
SRC_FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
# Object files (replace .c with .o)
OBJ_FILES = $(SRC_FILES:.c=.o)
# Static ibrary name
LIBRARY = libft.a
# Rule to build the library
all: $(LIBRARY)

$(LIBRARY): $(OBJ_FILES)
	ar rc $@ $^  # ar: Archive utility used to create static libraries.
		     # r: Insert the files ($^) into the archive, replacing older files.
		     # c: Create the archive if it doesn't exist.
		     # $@: Automatic variable representing the target name ($(LIBRARY)).
		     # $^: Automatic variable representing all prerequisites ($(OBJ_FILES)).
	@ranlib $@   # ranlib: Generates an index to the contents of the archive, which speeds up linking.
		     # The @ symbol suppresses the command output in the terminal.

# Compile source files into object files
# Pattern Rule: Defines how to compile any .c file in $(SRC_DIR) into a .o file.
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	# $<: The first prerequisite (the source file).
	# $@: The target file (the object file).
	# -c: Compiles the source file without linking.
	# -o $@: Specifies the output file name (the object file).

# Clean rule to remove object files
# Forcefully removes the object files without prompting or displaying errors if files do not exist.
clean:
	rm -f $(OBJ_FILES)

# Fclean rule to remove the library and object files
# Forcefully removes the library file libft.a.
fclean: clean
	rm -f $(LIBRARY)

# Rebuild rule to clean and then build again
# Runs the 'all' target to build everything anew.
re: fclean all

# Declares all, clean, fclean, and re as phony targets.
# Phony targets are not files; they are names for a recipe to be executed when explicitly requested.
# Prevents conflicts with files of the same name that might exist in the directory.
.PHONY: all clean fclean re
