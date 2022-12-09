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
SRC_NAME	=	main.c
SRC			=	${addprefix src/,${SRC_NAME}}
C			=	cc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -rf
SRC_PATH	=	./src/
OBJ_PATH	=	./obj/
OBJ_DIRS	=	${OBJ_PATH}
OBJ			=	${addprefix ${OBJ_PATH},${SRC_NAME:.c=.o}}
DEP			=	${addprefix ${OBJ_PATH},${SRC_NAME:.c=.d}}
INCDIR		=	${addprefix -I,_libft _minilibx-linux /usr/include includes inc}
LIBDIR		=	${addprefix -L,_libft _minilibx-linux /usr/lib}
LIBINC		=	-lXext -lX11 -lm -lz -lmlx -lft
LIBFT		=	./_libft/libft.a
LIBMLX		=	./_minilibx-linux/libmlx.a

# **************************************************************************** #
#    Mandatory rules                                                           #
# **************************************************************************** #

all:${NAME}

clean:
	make -sC _libft clean
	${RM} ${OBJ_PATH}

fclean:clean
	make -sC _libft fclean
	make -sC _minilibx-linux clean
	${RM} ${NAME}

re:fclean
	make

# **************************************************************************** #
#    Other rules                                                               #
# **************************************************************************** #

bonus:${NAME}

run:${NAME}
	clear
	./${NAME} map/map.cub

debug:${NAME}
	clear
	valgrind --leak-check=full --show-leak-kinds=all ./${NAME} map/map.cub

${OBJ_PATH}%.o:${SRC_PATH}%.c
	${C} ${CFLAG} -MMD -c $< -o $@ ${INCDIR}

${OBJ_DIRS}:
	mkdir ${OBJ_DIRS}

${NAME}:${OBJ_DIRS} ${OBJ}
	make -sC _libft
	make -sC _minilibx-linux
	${C} ${CFLAG} ${OBJ} ${LIBDIR} ${LIBINC} -o $@

# **************************************************************************** #
#    Other                                                                     #
# **************************************************************************** #

.PHONY:all clean fclean re bonus run debug

-include ${DEP}
