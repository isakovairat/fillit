/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosella <erosella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:08:24 by erosella          #+#    #+#             */
/*   Updated: 2019/10/26 12:19:38 by erosella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		get_map_size(int num)
{
	int		size;

	size = MINMAP;
	while (size * size < num)
	{
		size++;
	}
	return (size);
}

t_map		*new_map(int map_size)
{
	t_map	*map;
	int		i;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->arr = (char**)ft_memalloc(sizeof(char*) * map_size);
	i = 0;
	while (i < map_size)
	{
		map->arr[i] = ft_strnew(map_size);
		ft_memset(map->arr[i], '.', map_size);
		i++;
	}
	return (map);
}

void		print_map(t_map *map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map->arr[i]);
		ft_putchar('\n');
		i++;
	}
}

void		free_map(t_map *map, int map_size)
{
	int		i;

	i = 0;
	while (i < map_size)
	{
		ft_memdel((void **)&(map->arr[i]));
		i++;
	}
	ft_memdel((void **)&(map->arr));
	ft_memdel((void **)&map);
}
