make -C libft fclean && make -C libft
clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror -I libft/includes -o check.o -c check.c
clang -g -O0 -o check.out check.o get_next_line.o -I libft/includes -L libft/ -lft
# clang -g -O0 -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
# clang -g -O0 -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
