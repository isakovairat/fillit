/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosella <erosella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:11:14 by erosella          #+#    #+#             */
/*   Updated: 2019/10/19 15:13:46 by erosella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct		s_block
{
	char			letter;
	char 			*str;
	struct t_tetris	*next;
}					t_block;

typedef struct		s_map
{
	char			**arr;
}					t_map;

int		valid(char *buf, int size);
int		charcount(char *buf);
int		adjacency_counter(char *buf);
t_map	*new_map(int map_size);
size_t	count_pieces(t_block *piecelist);
void	print_map(t_map *map, int size);
void	free_map(t_map *map, int map_size);


#endif
