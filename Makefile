# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erosella <erosella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 14:10:22 by ycameron          #+#    #+#              #
#    Updated: 2019/10/26 12:34:30 by erosella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = block.c shift.c map.c finder.c main.c valid.c
OBJECTS = $(SOURCES:.c=.o)
HEADER = fillit.h

all: $(NAME)

$(NAME): libft/libft.a $(OBJECTS)
	$(CC) $(OBJECTS) libft/libft.a -I libft -o $(NAME)

%.o: %.c fillit.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJECTS)
	make clean -C libft

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f libft/libft.a

re: fclean all

libft/libft.a:
	make -C libft

.PHONY: all clean fclean re