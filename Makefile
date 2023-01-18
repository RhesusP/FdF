# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 23:40:27 by cbernot           #+#    #+#              #
#    Updated: 2023/01/18 13:40:17 by cbernot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = ./main.c ./srcs/parse_file.c ./srcs/cell_utils.c ./srcs/draw_map.c \
	   ./srcs/bresenham.c ./srcs/point_utils.c ./srcs/key_translation.c ./srcs/key_utils.c
OBJS = ${SRCS:.c=.o}
INCLUDES = ./includes/fdf.h
FLAGS = 

%.o: %.c ${INCLUDES}
	cc ${FLAGS} -g -I ./minilibx -I ${INCLUDES} -c $< -o $@

${NAME}: ${OBJS}
	make -C ./minilibx
	make -C ./libft
	cc ${OBJS} -L ./minilibx -l mlx -framework OpenGL -framework AppKit -L ./libft -lft -o ${NAME}
#cc ${OBJS} -L minilibx -lmlx -framework OpenGL -framework AppKit -L ./libft -lft -o ${NAME}

all: ${NAME}

clean:
	make clean -C ./libft
	make clean -C ./minilibx
	rm -f ${OBJS}

fclean: clean
	make fclean -C ./libft
	rm -f ./minilibx/libmlx.a
	rm -f ${NAME}

re: fclean all