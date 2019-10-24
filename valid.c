/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:47:54 by erosella          #+#    #+#             */
/*   Updated: 2019/10/24 18:52:37 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block		*get_cord(char const *str, t_block *block)
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
	return (shift(block));
}

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
		if (str[i] == '\n' && (i + 1) % 5 != 0)
			return (FALSE);
		if (str[i] == '#')
			count++;
		i++;
	}
	if (!str[i] || str[i] != '\n')
		return (FALSE);
	return (count);
}

int		adjacency_counter(char const *str)
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

int		valid(char *str, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if (charcount(str + i) != 4)
        {
			return (FALSE);
		}
		if (adjacency_counter(str + i) != 6 && adjacency_counter(str+ i) != 8)
		{
			return (FALSE);
		}
		i += 21;
	}
	return (TRUE);
}
