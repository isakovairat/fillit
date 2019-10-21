/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:08:48 by erosella          #+#    #+#             */
/*   Updated: 2019/10/21 16:29:53 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	str[545];
	int		byte;
	t_block *head;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	byte = read(fd, str, 545);
	close(fd);
	// printf("str = %s\n", str);
	if (!valid(str, byte) || (byte > 544 || byte < 19))
	{
		ft_putstr("error\n");
		exit(0);
	}
	// printf("%s\n", str);
	head = make_list(str, byte);
	// print_list(head);
	printf("%d in linked list", count_in_list(head));
	return (0);
}
