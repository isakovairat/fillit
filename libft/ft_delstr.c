/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:30:37 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/10 17:13:35 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delstr(char **s, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
		ft_strdel(&s[i++]);
	ft_memdel((void**)s);
}
