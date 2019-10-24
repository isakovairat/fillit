/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:11:14 by erosella          #+#    #+#             */
/*   Updated: 2019/10/24 19:04:41 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define TRUE 1
# define FALSE 0
# define MINMAP 2

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct		s_block
{
	char			letter;
	int				coord[8];
	int				x_offset;
	int				y_offset;
	struct s_block	*next;
}					t_block;

typedef struct		s_map
{
	char			**arr;
}					t_map;

int					valid(char *str, int size);
int					charcount(char *str);
int					adjacency_counter(char const *str);
t_block				*make_list(char *str, int size);
t_block				*make_block(char *str, char letter);
void				print_list(t_block	*head);
size_t				count_in_list(t_block *head);
void				free_list(t_block *block);
t_map				*new_map(int map_size);
void				print_map(t_map *map, int map_size);
void				free_map(t_map *map, int map_size);
t_block				*get_cord(char const *str, t_block *block);
void				shift_x(t_block *block);
void				shift_y(t_block *block);
t_block				*shift(t_block *block);
size_t              round_sqrt(int num);
int	                overlap(t_map *map, t_block *block);
void	            place(t_block *block, t_map *map, char letter);
int		            in_bounds(t_block *block, int map_size, char axis);
int		            solve_map(t_map *map, t_block *block, int map_size);
void	            finder(t_block *head);

#endif
