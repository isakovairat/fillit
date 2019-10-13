/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosella <erosella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:47:54 by erosella          #+#    #+#             */
/*   Updated: 2019/10/13 15:16:19 by erosella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

//	Считаем символы

int		charcount(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < 19)
	{
		if (str[i] && str[i] != '\n' && str[i] != '#' && str[i] != '.')
			return (0);
		if (str[i] == '\n' && !(((i + 1) % 5) == 0))
			return (0);
		if (str[i] == '#')
			count++;
		i++;
	}
	if (!str[i] || str[i] != '\n')
		return (0);
	return (count);
}

/*
**	Проверям что каждая '#' граничит с другой
**	https://medium.com/@bethnenniger/fillit-solving-for-the-smallest-square-of-tetrominos-c6316004f909
**	Сумма для каждой валидной тетриминки поучается 6 или 8. Всего валидных тетриминок 19
**	Индексы в массивы получаеются следующие:
	0  1  2  3  4
	5  6  7  8  9
	10 11 12 13 14
	15 16 17 18 19
	20
*/

int		adjacency_counter(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (str[i] == '#')
		{
			if (i + 1 <= 18 && str[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && str[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && str[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && str[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

// Проверка на валидность

int		valid(char *str, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if (charcount(str + i) != 4)
		{
			printf("Block is invalid\n");
			return (0);
		}
		if (adjacency_counter(str + i) != 6 && adjacency_counter(str+ i) != 8)
		{
			printf("Block is invalid\n");
			return (0);
		}
		i += 21;
		printf("Block is valid\n");
	}
	return (1);
}
