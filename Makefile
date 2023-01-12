# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 13:18:13 by frrusso           #+#    #+#              #
#    Updated: 2023/01/12 13:32:03 by sle-huec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
SRC			=	main.c \
				cub3d.c
SRC			+=	${addprefix map/,\
				map_algo.c}
SRC			+=	${addprefix parsing/,\
				initialization_utils.c \
				initialization.c \
				parsing.c}
SRC			+=	${addprefix useful/,\
				free.c \
				useful.c \
				debug.c}

SRC			+=	${addprefix wall_renderer/,\
				init_renderer.c \
				test.c}

# **************************************************************************** #
#    Compiler                                                                  #
# **************************************************************************** #
CC			=	cc
CFLAG		=	-Wall -Wextra -Werror -g3
RM			=	rm -rf

# **************************************************************************** #
#    Source                                                                    #
# **************************************************************************** #
SRC_PATH	=	./src/
OBJ_PATH	=	./obj/
OBJ			=	${addprefix ${OBJ_PATH},${SRC:.c=.o}}
DEP			=	${addprefix ${OBJ_PATH},${SRC:.c=.d}}

# **************************************************************************** #
#    Include & Library                                                         #
# **************************************************************************** #
INCDIR		=	${addprefix -I,_libft _minilibx-linux /usr/include inc}
LIBDIR		=	${addprefix -L,_libft _minilibx-linux /usr/lib}
LIBINC		=	-lft -lmlx -lX11 -lXext -lm -lz

# **************************************************************************** #
#    Rules                                                                     #
# **************************************************************************** #

all:${NAME}

clean:
	@make -sC _libft clean
	${RM} ${OBJ_PATH}

fclean:clean
	@make -sC _libft fclean
	@make -sC _minilibx-linux clean
	${RM} ${NAME}

re:fclean
	make

bonus:${NAME}

run:${NAME}
	clear
	./${NAME} map/map.cub

debug:${NAME}
	clear
	valgrind --leak-check=full --show-leak-kinds=all ./${NAME} map/map.cub

${OBJ_PATH}%.o:${SRC_PATH}%.c
	@mkdir -p ${dir $@}
	${CC} ${CFLAG} -MMD -c $< -o $@ ${INCDIR}

${NAME}:${OBJ}
	@make -sC _libft
	@make -sC _minilibx-linux
	${CC} ${CFLAG} ${OBJ} ${LIBDIR} ${LIBINC} -o $@

# **************************************************************************** #
#    Other                                                                     #
# **************************************************************************** #

.PHONY:all clean fclean re bonus run debug

-include ${DEP}
