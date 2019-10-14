/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:11:14 by erosella          #+#    #+#             */
/*   Updated: 2019/10/14 17:58:19 by ycameron         ###   ########.fr       */
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
	struct t_tetris	*next;
}					t_block;

int					valid(char *buf, int size);
int					charcount(char *buf);
int					adjacency_counter(char *buf);

#endif
