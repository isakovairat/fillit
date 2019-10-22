/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiftcoord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:16:51 by ycameron          #+#    #+#             */
/*   Updated: 2019/10/22 15:50:38 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

t_block		*shift(t_block *block)
{
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
	return(block);
}
