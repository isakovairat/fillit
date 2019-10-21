/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosella <erosella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:11:14 by erosella          #+#    #+#             */
/*   Updated: 2019/10/21 18:56:58 by erosella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct		s_block
{
	char			letter;
	int				coord[8];
	struct s_block	*next;
}					t_block;

typedef struct		s_map
{
	char			**arr;
}					t_map;

int					valid(char *buf, int size);
int					charcount(char *buf);
int					adjacency_counter(char *buf);
t_block				*make_list(char *str, int size);
t_block				*make_block(char *str, char letter);
void				print_list(t_block	*head);
int					count_in_list(t_block *head);
t_map				*new_map(int map_size);
size_t				count_pieces(t_block *piecelist);
void				print_map(t_map *map, int size);
void				free_map(t_map *map, int map_size);
t_block				*get_cord(char *str, t_block *block);

#endif
