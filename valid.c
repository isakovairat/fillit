/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosella <erosella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:47:54 by erosella          #+#    #+#             */
/*   Updated: 2019/10/21 19:15:04 by erosella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_block	*make_list(char *str, int size)
{
	t_block *head;
	t_block *current;
	int i;
	char letter;

	i = 0;
	// printf("str in make_list() = %s, size = %d\n", str, size);
	letter = 'A';
	// printf("%d\n",size);
	while (i < size)
	{
		if (letter == 'A')
		{
			head = make_block(str + i, letter);
			current = head;
		}
		else
		{
			current->next = make_block(str + i, letter);
			current = current->next;
		}
		// printf("str + %d:\n%s\n", i, str + i);
		letter++;
		i += 21;
		// printf("%d\n", i);
	}
	// current = make_block(str + i - 21, letter);
	current->next = NULL;
	return(head);
}

void	shift_x(t_block *block, int n)
{
	block->coord[0] += n;
	block->coord[2] += n;
	block->coord[4] += n;
	block->coord[6] += n;
}

void	shift_y(t_block *block, int n)
{
	block->coord[1] += n;
	block->coord[3] += n;
	block->coord[5] += n;
	block->coord[7] += n;
}

t_block *get_cord(char *str, t_block *block)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 1;
	while (i < 19)
	{
		if (*(str + i) == '#')
		{
			block->coord[x] = i / 5;
			block->coord[y] = (i >= 5) ? i % 5 : i;
			x += 2;
			y += 2;
		}
		i++;
	}
	while (block->coord[0] != 0 && \
			block->coord[2] != 0 && \
			block->coord[4] != 0 && \
			block->coord[6] != 0)
		shift_x(block, -1);
	while (block->coord[1] != 0 && \
			block->coord[3] != 0 && \
			block->coord[5] != 0 && \
			block->coord[7] != 0)
		shift_y(block, -1);
	return (block);
}

t_block	*make_block(char *str, char letter)
{
	t_block *new;

	if (!(new = (t_block*)malloc(sizeof(t_block))))
		return (NULL);
	new->letter = letter;
	return (get_cord(str,new));
}

void	print_list(t_block	*head)
{
	t_block *tmp;
	int i;

	i = 0;
	tmp = head;
	while(tmp)
	{
		printf("[%c]:\n %d%d%d%d%d%d%d%d\n->\n", tmp->letter, tmp->coord[0],tmp->coord[1],tmp->coord[2],tmp->coord[3],tmp->coord[4],tmp->coord[5],tmp->coord[6],tmp->coord[7]);
		tmp = tmp->next;
		i++;
	}
}

int		count_in_list(t_block *head)
{
	int count;
	t_block *current;

	current = head;
	count = 0;
	while(current)
	{
		count++;
		current = current->next;
	}
	return(count);
}

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
			return (FALSE);
		if (str[i] == '\n' && !(((i + 1) % 5) == 0))
			return (FALSE);
		if (str[i] == '#')
			count++;
		i++;
	}
	if (!str[i] || str[i] != '\n')
		return (FALSE);
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
//size == strlen(str) ????????
int		valid(char *str, int size)
{
	int i;

	// printf("strlen(str) = %zu\n", ft_strlen(str));
	// printf("size = %d\n", size);
	i = 0;
	while (i <= size)
	{
		if (charcount(str + i) != 4)
		{
			// ft_putstr("Block is invalid\n");
			return (FALSE);
		}
		if (adjacency_counter(str + i) != 6 && adjacency_counter(str+ i) != 8)
		{
			// ft_putstr("Block is invalid\n");
			return (FALSE);
		}
		i += 21;
		// ft_putstr("Block is valid\n");
	}
	return (TRUE);
}
