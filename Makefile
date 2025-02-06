# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 19:39:14 by nglaizau          #+#    #+#              #
#    Updated: 2025/02/06 18:28:42 by nglaizau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c check_map.c main.c map.c check_map2.c flood_fil.c
OBJS = ${SRCS:.c=.o}
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
LIBFT = ./include
INCLUDES = -I/usr/include -Imlx -Iincludes

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