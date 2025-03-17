# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 19:39:14 by nglaizau          #+#    #+#              #
#    Updated: 2025/03/06 14:40:26 by nglaizau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c check_map.c main.c map.c check_map2.c flood_fil.c mlx.c
OBJS = ${SRCS:.c=.o}
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
LIBFT = ./include
INCLUDES = -I/usr/include -Imlx -Iincludes
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11


all : ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./include/
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ./include/include.a ${MLX_FLAGS}

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	${MAKE} clean -C ./include/
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ./include/include.a

re: fclean all

.PHONY: all clean fclean re