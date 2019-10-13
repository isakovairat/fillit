/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 09:44:24 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/12 09:50:26 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstrev(t_list **begin_list)
{
	t_list	*node;
	t_list	*next;
	t_list	*previous;

	if (!begin_list || !*begin_list)
		return ;
	previous = NULL;
	next = NULL;
	node = *begin_list;
	while (node != NULL)
	{
		next = node->next;
		node->next = previous;
		previous = node;
		node = next;
	}
	*begin_list = previous;
}
