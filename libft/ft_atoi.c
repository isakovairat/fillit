/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:29:27 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/10 11:30:07 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	n;
	unsigned long	border;
	size_t			i;
	short			sign;

	i = 0;
	n = 0;
	sign = 1;
	border = (unsigned long)(LONG_MAX / 10);
	while (ft_isspace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		if ((n > border || (n == border && (str[i] - '0') > 7)) && sign == 1)
			return (-1);
		else if ((n > border || (n == border && (str[i] - '0') > 8)) \
			&& sign == -1)
			return (0);
		n = n * 10 + (str[i++] - '0');
	}
	return ((int)(n * sign));
}
