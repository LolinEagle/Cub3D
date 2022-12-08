# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frrusso <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 13:18:13 by frrusso           #+#    #+#              #
#    Updated: 2022/12/08 13:18:15 by frrusso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
SRC			=	${addprefix src/, \
					main.c \
				}
C			=	cc
CFLAG		=	-Wall -Wextra -Werror -MMD
RM			=	rm -rf
INC			=	-I ./inc/
SRC_PATH	=	./src/
OBJ_PATH	=	./obj/
OBJ_DIRS	=	${OBJ_PATH}
OBJ			=	${SRC:${SRC_PATH}%.c=${OBJ_PATH}%.o}
DEP			=	${SRC:.c=.d}
LIBFT		=	./libft/libft.a
LIBMLX		=	./minilibx-linux/libmlx.a

all:${NAME}

clean:
	make -s -C libft clean
	${RM} ${OBJ_PATH}

fclean:clean
	make -s -C libft fclean
	${RM} ${NAME}

re:fclean
	make

bonus:${NAME}

run:${NAME}
	clear
	./${NAME}

debug:${NAME}
	clear
	valgrind ./${NAME}

${OBJ_PATH}%.o:${SRC_PATH}%.c
	${C} ${CFLAG} -c $< -o $@

${OBJ_DIRS}:
	mkdir ${OBJ_DIRS}

${NAME}:${OBJ_DIRS} ${OBJ}
	make -s -C libft
	make -s -C minilibx-linux
	${C} ${CFLAG} ${LIBFT} ${LIBMLX} ${OBJ} -o ${NAME}

.PHONY:all clean fclean re bonus run debug

-include ${DEP}

