# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oexall <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/13 08:50:18 by oexall            #+#    #+#              #
#    Updated: 2016/06/17 07:17:49 by oexall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc -g -o
CFLAGS = -Wall -Werror -Wextra

SRC = wolf3d.c error.c read_file.c hooks.c draw.c \
	  intersect.c read_map.c

LIBMLX = -lmlx -framework OpenGL -framework AppKit
LIBFT = -L libft -lft

all: $(NAME)

$(NAME):
	@clear
	@echo "Compiling Libft"
	@make -C libft/ fclean
	@make -C libft
	@make -C libft/ clean
	@echo "Finished Compiling Libft"
	@echo "Compiling $(NAME)"
	@$(CC) $(NAME) $(CFLAGS) $(SRC) $(LIBMLX) $(LIBFT)
	@echo "Finished compiling $(NAME)"

quick:
	@clear
	@echo "Compiling $(NAME)"
	@$(CC) $(NAME) $(CFLAGS) $(SRC) $(LIBMLX) $(LIBFT)
	@echo "Finished compiling $(NAME)"

clean:
	@rm -f $(NAME)
	@echo "Cleaned $(NAME)"

fclean: clean
	@make -C libft/ fclean
	@echo "Finished Full clean"

re: fclean all
