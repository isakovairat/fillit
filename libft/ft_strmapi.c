/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:35:41 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/09 10:44:05 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	i;

	i = 0;
	if (!s || f == NULL)
		return (NULL);
	dst = ft_strnew(ft_strlen(s));
	if (!dst)
		return (NULL);
	while (s[i] != '\0')
	{
		*(dst + i) = (*f)(i, *(s + i));
		i++;
	}
	return (dst);
}
