/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:47:54 by erosella          #+#    #+#             */
/*   Updated: 2019/10/25 17:49:24 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int static		count_chars(char const *str)
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

int	static		adjacency_counter(char const *str)
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

int			valid(char *str, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if (count_chars(str + i) != 4)
		{
			return (FALSE);
		}
		if (adjacency_counter(str + i) != 6 && adjacency_counter(str + i) != 8)
		{
			return (FALSE);
		}
		i += 21;
	}
	return (TRUE);
}
