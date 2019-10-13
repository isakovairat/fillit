/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:53:48 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/10 11:11:03 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char			*res;
	size_t			len;
	unsigned int	nb;

	len = ft_numlen(n);
	nb = n;
	if (n < 0)
	{
		nb = n * -1;
		len++;
	}
	if (!(res = ft_strnew(len)))
		return (NULL);
	res[--len] = (nb % 10) + '0';
	while (nb /= 10)
	{
		res[--len] = (nb % 10) + '0';
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
