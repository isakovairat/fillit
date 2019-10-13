/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:26:56 by ycameron          #+#    #+#             */
/*   Updated: 2019/10/13 12:40:52 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
INVALID EXAMPLES:

...#	.##.	.123
..#.	....	....
.#..	.##.	1234
#...	....	....

VALID EXAMPLES:

###.\n
#...\n  --->
....\n	--->
....\n

*/

#include <fcntl.h>
#include "get_next_line.h"

#define TRUE 1
#define FALSE 0

char g_block[4][4];
int g_block_check[4][4];

// long long int	ft_pow(int n, unsigned int p)
// {
// 	unsigned int	i;
// 	long long int	res;

// 	if (p == 0)
// 		return (1);
// 	res = (long long int)n;
// 	i = 0;
// 	while (++i < p)
// 		res *= n;
// 	return (res);
// }

// int	bin_to_decimal(const char *str)
// {
// 	int res;
// 	int i;
// 	int cursor;

// 	cursor = 15;
// 	i = 0;
// 	res = 0;
// 	while (str && str[i])
// 	{
// 		res = res + (str[i] - '0') * ft_pow(2, cursor);
// 		cursor--;
// 		i++;
// 	}
// 	return (res);
// }

// void change_ch(char *str)
// {
// 	while(str && *str)
// 	{
// 		*str = *str == '.' ? '0': '1';
// 		str++;
// 	}
// }

// void	fill_block(char *str)
// {
// 	int i,j;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		j = 0;
// 		while (j < 4)
// 		{
// 			g_block[i][j] = *str;
// 			str++;
// 			j++;
// 		}
// 		i++;
// 	}
// }


int count_tetriminos(char *str)
{
	int count;

	count = 0;
	if (ft_strlen(str) != 16)
		return(FALSE);
	while (str && *str && (*str == '#' || *str == '.'))
	{
		if (*str == '#')
			count++;
		str++;
	}
	if (count == 4 && *str == '\0')
		return (TRUE);
	return (FALSE);
}

int is_valid_block(char *str)
{
	if (!count_tetriminos(str))
		return (FALSE);
	return (TRUE);
}

void fill_block(char *str)
{
	int i;
	int j;

	i = 0;
	if(count_tetriminos(str))
	{
		while (i++ < 4)
		{
			j = 0;
			while (j++ < 4)
			{
				g_block[i][j] = *str;
				str++;
			}
		}
	}
}
// ЭТА ДУРЬ НЕ РАБОТАЕТ ПОЧЕМУ ТА!!!!
void check_block()
{
	int i;
	int j;
	int value;
	int sum;

	sum = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			value = 0;
			if(g_block[i][j] == '#')
			{
				// left
				if (j - 1 >= 0)
					if (g_block[i][j-1] == '#')
						value++;
				// up
				if (i - 1 >= 0)
					if (g_block[i-1][j] == '#')
						value++;
				// right
				if (j + 1 <= 3)
					if (g_block[i][j+1] == '#')
						value++;
				//down
				if (i + 1 <= 3)
					if (g_block[i+1][j] == '#')
						value++;
				g_block_check[i][j] = value;
			}
			else
				g_block_check[i][j] = 0;
			j++;
		}
		i++;
	}
}


int main(int ac, char **av)
{
	int fd;
	char *line;
	int i, j;
	char *res;
	// int int_res;
	// char **block;

	i = 0;
	fd = open(av[1], O_RDONLY);
	printf("======================================%s====================================\n", av[1]);
	while (get_next_line(fd, &line) == 1)
	{
		i++;
		res = ft_strjoin(res,line);
		printf("line[%d] = %s\n", i, line);
		free(line);
	}
	// printf("res len = %zu\n", ft_strlen(res));
	// printf("res = %s\n",res);
	if (is_valid_block(res))
		printf("Block is valid\n");
	else
		printf("Block is invalid\n");

	fill_block(res);

	// print g_block
	printf("Блок состоящий из # и .\n");
	i = 0;
	while (i++ < 4)
		{
			j = 0;
			while (j++ < 4)
			{
				printf("g_block[%d][%d] = %c ", i, j, g_block[i][j]);
			}
			printf("\n");
		}
	printf("\n");
	check_block();
	// print g_block_check
	printf("матрица показывающая сколько соседей имееет каждая ячейка\n");
	i = 0;
	while (i++ < 4)
		{
			j = 0;
			while (j++ < 4)
			{
				printf("[%d][%d] = %d ", i, j, g_block_check[i][j]);
			}
			printf("\n");
		}
	close(fd);
	return (ac);
}
