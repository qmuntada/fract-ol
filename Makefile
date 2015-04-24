#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 16:04:22 by qmuntada          #+#    #+#              #
#    Updated: 2015/04/24 18:37:09 by qmuntada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wall -Werror -Wextra
SRC = display.c env.c event.c julia.c main.c mandelbrot.c newton.c tools.c
OBJ = $(SRC:.c=.o)
mlx = minilibx_macos
ft = libft

all : $(NAME)

$(NAME) : $(ft) $(mlx)
	@echo "Creating MAC executable $@ ..."
	@gcc $(FLAGS) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) -L $(ft) -lft -L $(mlx) -lmlx -framework OpenGl -framework AppKit

libft:
	@make -C libft fclean
	@make -C libft

clean :
	@echo "Removing object files ..."
	@rm -f $(OBJ)

fclean : clean
	@echo "Removing $(NAME) ..."
	@rm -f $(NAME)

re : fclean all
