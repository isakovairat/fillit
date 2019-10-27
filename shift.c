/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosella <erosella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:16:51 by ycameron          #+#    #+#             */
/*   Updated: 2019/10/26 12:18:51 by erosella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		shift_axis(t_block *block, int axis)
{
	if (axis == X)
	{
		while (axis <= 6)
		{
			block->coord[axis]--;
			axis += 2;
		}
	}
	else
	{
		while (axis <= 7)
		{
			block->coord[axis]--;
			axis += 2;
		}
	}
}

t_block		*shift(t_block *block)
{
	while (block->coord[0] != 0 &&
	block->coord[2] != 0 &&
	block->coord[4] != 0 &&
	block->coord[6] != 0)
		shift_axis(block, X);
	while (block->coord[1] != 0 &&
	block->coord[3] != 0 &&
	block->coord[5] != 0 &&
	block->coord[7] != 0)
		shift_axis(block, Y);
	return (block);
}
