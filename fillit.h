/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:11:14 by erosella          #+#    #+#             */
/*   Updated: 2019/10/21 18:02:51 by ycameron         ###   ########.fr       */
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
	char 			*str;
	struct s_block	*next;
}					t_block;

int					valid(char *buf, int size);
int					charcount(char *buf);
int					adjacency_counter(char *buf);
t_block				*make_list(char *str, int size);
t_block				*make_block(char *str, char letter);
void				print_list(t_block	*head);
int					count_in_list(t_block *head);

#endif
