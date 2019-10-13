/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:17:34 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/12 11:09:37 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (!del)
		return ;
	if ((*alst)->next && alst && del)
		ft_lstdel(&(*alst)->next, del);
	ft_lstdelone(&(*alst), del);
}
