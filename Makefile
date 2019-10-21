# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 14:10:22 by ycameron          #+#    #+#              #
#    Updated: 2019/10/21 15:22:01 by ycameron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft/
SOURCES = *.c

OBJECTS = $(SOURCES:%.c=%.o)

HEADER = fillit.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LIB)
	$(CC) $(FLAGS) -o $(NAME) $(SOURCES) -I $(HEADER) -L $(LIB) -lft

clean:
	/bin/rm -f $(OBJECTS)
	make -C $(LIB) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIB) fclean

re: fclean all
