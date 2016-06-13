# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oexall <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/13 08:50:18 by oexall            #+#    #+#              #
#    Updated: 2016/06/13 09:01:22 by oexall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc -o
CFLAGS = -Wall -Werror -Wextra

SRC = 

LIBMLX = -lmlx -framework OpenGL -framework AppKit
LIBFT = -L libft -lft

all: $(NAME)

$(NAME):
	@echo "Compiling Libft"
	@make -C libft/ fclean
	@make -C libft
	@make -C libft/ clean
	@echo "Finished Compiling Libft"
	@echo "Compiling $(NAME)"
	@$(CC) $(NAME) $(CFLAGS) $(SRC) $(LIBMLX) $(LIBFT)
	@echo "Finided compiling $(NAME)"

clean:
	@rm -f $(NAME)
	@echo "Cleaned $(NAME)"

fclean: clean
	@make -C libft/ fclean
	@echo "Finished Full clean"

re: fclean all
