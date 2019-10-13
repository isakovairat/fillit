/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:44:05 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/06 14:47:44 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)src;
	p2 = (unsigned char *)dst;
	while (i < n)
	{
		*p2 = *p1;
		if (*p1 == (unsigned char)c)
			return ((void *)dst + i + 1);
		p1++;
		p2++;
		++i;
	}
	return (NULL);
}
