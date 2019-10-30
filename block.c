/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosella <erosella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:19:06 by ycameron          #+#    #+#             */
/*   Updated: 2019/10/26 12:21:33 by erosella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block			*get_cord(char const *str, t_block *block)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	x = 0;
	y = 1;
	while (i < 19)
	{
		if (*(str + i) == '#')
		{
			block->coord[x] = (i >= 5) ? i % 5 : i;
			block->coord[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	return (shift(block));
}

t_block			*make_list(char *str, int size)
{
	t_block		*head;
	t_block		*current;
	int			i;
	char		letter;

	i = 0;
	letter = 'A';
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
		letter++;
		i += 21;
	}
	current->next = NULL;
	return (head);
}

t_block			*make_block(char *str, char letter)
{
	t_block		*new;

	if (!(new = (t_block*)malloc(sizeof(t_block))))
		return (NULL);
	new->letter = letter;
	return (get_cord(str, new));
}

void			free_list(t_block *block)
{
	t_block		*temp;

	while (block != NULL)
	{
		temp = block;
		block = block->next;
		free(temp);
	}
}

int				count_in_list(t_block *head)
{
	int			count;
	t_block		*current;

	current = head;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
