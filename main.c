/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:08:48 by erosella          #+#    #+#             */
/*   Updated: 2019/10/25 18:06:00 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	str[545];
	int		byte;
	t_block *head;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (TRUE);
	}
	fd = open(argv[1], O_RDONLY);
	byte = read(fd, str, 545);
	close(fd);
	if (!valid(str, byte) || (byte > 544 || byte < 19))
	{
		ft_putstr("error\n");
		exit(0);
	}
	head = make_list(str, byte);
	finder(head);
	free_list(head);
	return (0);
}
