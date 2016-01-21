# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adespond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 14:14:20 by adespond          #+#    #+#              #
#    Updated: 2016/01/11 06:26:35 by rdidier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRC		= src/algo.c \
		  src/algo_tools.c \
		  src/check_tris.c \
		  src/create_conf.c \
		  src/create_tris.c \
		  src/fillit.c \
		  src/grid_op.c \
		  src/main.c \
		  src/read_file.c 

OBJ		= $(patsubst src/%.c,./%.o,$(SRC))

INCLUDE	= include/fillit.h \
		  include/libft.h

.SILENT:

$(NAME): $(OBJ)
	gcc -Wall -Werror -Wextra $(OBJ) -L libft/ -lft -o $(NAME)
	printf '\033[4m'
	printf '\033[32m[ ✔ ] %s\n\033[0m' "fillit is done !"
./%.o: src/%.c
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf *.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all
