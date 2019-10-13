/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 09:37:14 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/09 11:19:04 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	char	*p;
	size_t	i;

	i = 0;
	if (!s || f == NULL)
		return (NULL);
	dst = ft_strnew(ft_strlen(s));
	if (!dst)
		return (NULL);
	p = dst;
	while (*s != '\0')
	{
		*(p++) = (*f)(*(s++));
	}
	return (dst);
}
