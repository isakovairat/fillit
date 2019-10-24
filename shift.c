/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:16:51 by ycameron          #+#    #+#             */
/*   Updated: 2019/10/24 11:17:38 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	    round_sqrt(int num)
{
	int size;

	size = MINMAP;
	while (size * size < num)
	{
		size++;
	}
	return (size);
}

void	shift_x(t_block *block)
{
	block->coord[0]--;
	block->coord[2]--;
	block->coord[4]--;
	block->coord[6]--;
}

void	shift_y(t_block *block)
{
	block->coord[1]--;
	block->coord[3]--;
	block->coord[5]--;
	block->coord[7]--;
}

t_block		*shift(t_block *block)
{
	while (block->coord[0] != 0 && \
			block->coord[2] != 0 && \
			block->coord[4] != 0 && \
			block->coord[6] != 0)
		shift_x(block);
	while (block->coord[1] != 0 && \
			block->coord[3] != 0 && \
			block->coord[5] != 0 && \
			block->coord[7] != 0)
		shift_y(block);
	return(block);
}
