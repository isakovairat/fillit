/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosella <erosella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:24:29 by ycameron          #+#    #+#             */
/*   Updated: 2019/10/27 14:57:05 by erosella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			overlap(t_map *map, t_block *block)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	x = block->coord[i] + block->x_offset;
	y = block->coord[i + 1] + block->y_offset;
	while (i <= 6 && map->arr[y][x] == '.')
	{
		i += 2;
		x = block->coord[i] + block->x_offset;
		y = block->coord[i + 1] + block->y_offset;
	}
	return (i != 8);
}

void		place(t_block *block, t_map *map, char letter)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = block->coord[i] + block->x_offset;
		y = block->coord[i + 1] + block->y_offset;
		map->arr[y][x] = letter;
		i += 2;
	}
}

int			in_bounds(t_block *block, int map_size, char axis)
{
	if (axis == 'y')
		return (block->coord[1] + block->y_offset < map_size &&
		block->coord[3] + block->y_offset < map_size &&
		block->coord[5] + block->y_offset < map_size &&
		block->coord[7] + block->y_offset < map_size);
	else
		return (block->coord[0] + block->x_offset < map_size &&
		block->coord[2] + block->x_offset < map_size &&
		block->coord[4] + block->x_offset < map_size &&
		block->coord[6] + block->x_offset < map_size);
}

int			solve_map(t_map *map, t_block *block, int map_size)
{
	if (!block)
		return (1);
	block->x_offset = 0;
	block->y_offset = 0;
	while (in_bounds(block, map_size, 'y'))
	{
		while (in_bounds(block, map_size, 'x'))
		{
			if (!overlap(map, block))
			{
				place(block, map, block->letter);
				if (solve_map(map, block->next, map_size))
					return (TRUE);
				else
				{
					place(block, map, '.');
				}
			}
			block->x_offset++;
		}
		block->x_offset = 0;
		block->y_offset++;
	}
	return (FALSE);
}

void		finder(t_block *head)
{
	t_map	*map;
	int		map_size;

	map_size = get_map_size(count_in_list(head) * 4);
	map = new_map(map_size);
	while (!solve_map(map, head, map_size))
	{
		free_map(map, map_size);
		map_size++;
		map = new_map(map_size);
	}
	print_map(map, map_size);
	free_map(map, map_size);
}
