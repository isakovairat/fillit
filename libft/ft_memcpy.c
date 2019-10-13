/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:09:00 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/06 12:43:18 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *p1;
	char *p2;

	p1 = (char *)src;
	p2 = dst;
	if (n == 0 || src == dst)
		return (dst);
	while (n > 0)
	{
		*p2++ = *p1++;
		n--;
	}
	return (dst);
}
