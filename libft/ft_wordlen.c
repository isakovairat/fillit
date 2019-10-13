/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:57:32 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/10 13:58:05 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordlen(char const *s, unsigned int i)
{
	int len;

	len = 0;
	while (ft_isalpha(s[i]))
	{
		i++;
		len++;
	}
	return (len);
}
