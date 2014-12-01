# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/27 19:33:24 by mbourdel          #+#    #+#              #
#    Updated: 2014/12/01 17:57:21 by mbourdel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = ./

SRC = fdf.c ft_get_the_map.c get_next_line.c

OBJ = fdf.o ft_get_the_map.o get_next_line.o

LIBFT_PATH = ./libft/

MLX_PATH = ./minilibx_macos/

FLAG = -Wall -Werror -Wextra

FRAM = -framework OpenGL -framework AppKit

RED = \x1B[0;31m

GREEN = \x1B[0;32m

YELLOW = \x1B[1;33m

NC = \x1B[0m

all: $(NAME)

$(NAME):
	@cd $(LIBFT_PATH); $(MAKE) -f Makefile
	@cd $(MLX_PATH); $(MAKE) -f Makefile
	@gcc $(FLAG) $(SRC_PATH)$(SRC) -o $(NAME) $(LIBFT_PATH)libft.a $(MLX_PATH)libmlx.a $(FRAM)
	@echo "${GREEN}     ████████╗██╗  ██╗██╗███████╗    ██╗███████╗"
	@echo "     ╚══██╔══╝██║  ██║██║██╔════╝    ██║██╔════╝"
	@echo "        ██║   ███████║██║███████╗    ██║███████╗"
	@echo "        ██║   ██╔══██║██║╚════██║    ██║╚════██║"
	@echo "        ██║   ██║  ██║██║███████║    ██║███████║"
	@echo "        ╚═╝   ╚═╝  ╚═╝╚═╝╚══════╝    ╚═╝╚══════╝"
	@echo "${YELLOW}                                                               "
	@echo "FFFFFFFFFFFFFFFFFFFFFFDDDDDDDDDDDDD      FFFFFFFFFFFFFFFFFFFFFF"
	@echo "F::::::::::::::::::::FD::::::::::::DDD   F::::::::::::::::::::F"
	@echo "F::::::::::::::::::::FD:::::::::::::::DD F::::::::::::::::::::F"
	@echo "FF::::::FFFFFFFFF::::FDDD:::::DDDDD:::::DFF::::::FFFFFFFFF::::F"
	@echo "  F:::::F       FFFFFF  D:::::D    D:::::D F:::::F       FFFFFF"
	@echo "  F:::::F               D:::::D     D:::::DF:::::F             "
	@echo "  F::::::FFFFFFFFFF     D:::::D     D:::::DF::::::FFFFFFFFFF   "
	@echo "  F:::::::::::::::F     D:::::D     D:::::DF:::::::::::::::F   "
	@echo "  F:::::::::::::::F     D:::::D     D:::::DF:::::::::::::::F   "
	@echo "  F::::::FFFFFFFFFF     D:::::D     D:::::DF::::::FFFFFFFFFF   "
	@echo "  F:::::F               D:::::D     D:::::DF:::::F             "
	@echo "  F:::::F               D:::::D    D:::::D F:::::F             "
	@echo "FF:::::::FF           DDD:::::DDDDD:::::DFF:::::::FF           "
	@echo "F::::::::FF           D:::::::::::::::DD F::::::::FF           "
	@echo "F::::::::FF           D::::::::::::DDD   F::::::::FF           "
	@echo "FFFFFFFFFFF           DDDDDDDDDDDDD      FFFFFFFFFFF          ${NC} "

clean:
	@rm -rf $(OBJ)
	@echo "${RED}▓█████▄ ▓█████   ██████ ▄▄▄█████▓ ██▀███   █    ██  ▄████▄  ▄▄▄█████▓ ██▓ ▒█████   ███▄    █ "
	@echo "▒██▀ ██▌▓█   ▀ ▒██    ▒ ▓  ██▒ ▓▒▓██ ▒ ██▒ ██  ▓██▒▒██▀ ▀█  ▓  ██▒ ▓▒▓██▒▒██▒  ██▒ ██ ▀█   █ "
	@echo "░██   █▌▒███   ░ ▓██▄   ▒ ▓██░ ▒░▓██ ░▄█ ▒▓██  ▒██░▒▓█    ▄ ▒ ▓██░ ▒░▒██▒▒██░  ██▒▓██  ▀█ ██▒"
	@echo "░▓█▄   ▌▒▓█  ▄   ▒   ██▒░ ▓██▓ ░ ▒██▀▀█▄  ▓▓█  ░██░▒▓▓▄ ▄██▒░ ▓██▓ ░ ░██░▒██   ██░▓██▒  ▐▌██▒"
	@echo "░▒████▓ ░▒████▒▒██████▒▒  ▒██▒ ░ ░██▓ ▒██▒▒▒█████▓ ▒ ▓███▀ ░  ▒██▒ ░ ░██░░ ████▓▒░▒██░   ▓██░"
	@echo " ▒▒▓  ▒ ░░ ▒░ ░▒ ▒▓▒ ▒ ░  ▒ ░░   ░ ▒▓ ░▒▓░░▒▓▒ ▒ ▒ ░ ░▒ ▒  ░  ▒ ░░   ░▓  ░ ▒░▒░▒░ ░ ▒░   ▒ ▒ "
	@echo " ░ ▒  ▒  ░ ░  ░░ ░▒  ░ ░    ░      ░▒ ░ ▒░░░▒░ ░ ░   ░  ▒       ░     ▒ ░  ░ ▒ ▒░ ░ ░░   ░ ▒░"
	@echo " ░ ░  ░    ░   ░  ░  ░    ░        ░░   ░  ░░░ ░ ░ ░          ░       ▒ ░░ ░ ░ ▒     ░   ░ ░ "
	@echo "   ░       ░  ░      ░              ░        ░     ░ ░                ░      ░ ░           ░ "
	@echo " ░                                                 ░                                         "
	@echo " ▄████▄   ▒█████   ███▄    █   █████▒██▓ ██▀███   ███▄ ▄███▓▓█████ ▓█████▄                   "
	@echo "▒██▀ ▀█  ▒██▒  ██▒ ██ ▀█   █ ▓██   ▒▓██▒▓██ ▒ ██▒▓██▒▀█▀ ██▒▓█   ▀ ▒██▀ ██▌                  "
	@echo "▒▓█    ▄ ▒██░  ██▒▓██  ▀█ ██▒▒████ ░▒██▒▓██ ░▄█ ▒▓██    ▓██░▒███   ░██   █▌                  "
	@echo "▒▓▓▄ ▄██▒▒██   ██░▓██▒  ▐▌██▒░▓█▒  ░░██░▒██▀▀█▄  ▒██    ▒██ ▒▓█  ▄ ░▓█▄   ▌                  "
	@echo "▒ ▓███▀ ░░ ████▓▒░▒██░   ▓██░░▒█░   ░██░░██▓ ▒██▒▒██▒   ░██▒░▒████▒░▒████▓                   "
	@echo "░ ░▒ ▒  ░░ ▒░▒░▒░ ░ ▒░   ▒ ▒  ▒ ░   ░▓  ░ ▒▓ ░▒▓░░ ▒░   ░  ░░░ ▒░ ░ ▒▒▓  ▒                   "
	@echo "  ░  ▒     ░ ▒ ▒░ ░ ░░   ░ ▒░ ░      ▒ ░  ░▒ ░ ▒░░  ░      ░ ░ ░  ░ ░ ▒  ▒                   "
	@echo "░        ░ ░ ░ ▒     ░   ░ ░  ░ ░    ▒ ░  ░░   ░ ░      ░      ░    ░ ░  ░                   "
	@echo "░ ░          ░ ░           ░         ░     ░            ░      ░  ░   ░                      "
	@echo "░                                                                   ░            ${NC}            "



fclean: clean
	@rm -rf $(NAME)

re: fclean all
