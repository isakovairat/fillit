/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:27:46 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/09 12:42:29 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dst;
	size_t			len;

	if (s1 && s2)
		len = (size_t)(ft_strlen((char*)s1) + ft_strlen((char*)s2));
	else if (s1)
		len = (size_t)(ft_strlen((char*)s1));
	else if (s2)
		len = (size_t)(ft_strlen((char*)s2));
	else
		return (NULL);
	if (!(dst = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	if (s1)
		dst = ft_strcpy(dst, (char*)s1);
	else
		dst = ft_strcpy(dst, (char*)s2);
	if (s1 && s2)
		dst = ft_strcat(dst, (char*)s2);
	return (dst);
}
