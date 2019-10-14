/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:11:14 by erosella          #+#    #+#             */
/*   Updated: 2019/10/14 13:04:07 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define TRUE 1
# define FALSE 0

int		valid(char *buf, int size);
int		charcount(char *buf);
int		adjacency_counter(char *buf);

#endif
