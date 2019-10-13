/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:19:39 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/12 09:21:37 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t content_size)
{
	if (!content)
		return ;
	ft_memdel(&content);
	(void)content_size;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*list;
	t_list		*prev;

	if (!lst || !f)
		return (NULL);
	list = NULL;
	prev = NULL;
	while (lst)
	{
		if (!(new = f(lst)))
		{
			ft_lstdel(&list, &del);
			return (NULL);
		}
		if (!prev)
		{
			list = new;
			prev = list;
		}
		prev->next = new;
		prev = prev->next;
		lst = lst->next;
	}
	return (list);
}
