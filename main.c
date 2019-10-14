/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:08:48 by erosella          #+#    #+#             */
/*   Updated: 2019/10/14 12:57:32 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	str[545];
	int		byte;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	byte = read(fd, str, 545);
	close(fd);
	valid(str, byte);
	return (0);
}
