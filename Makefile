# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/27 19:33:24 by mbourdel          #+#    #+#              #
#    Updated: 2014/11/27 19:40:59 by mbourdel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = ./src/

LIBFT_PATH = ./libft/

MLX_PATH = ./minilibx_macos/

FLAF = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):

clean:

fclean: clean

re: fclean all
