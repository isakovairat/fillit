/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:19:06 by ycameron          #+#    #+#             */
/*   Updated: 2019/10/24 18:21:55 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_block	*make_list(char *str, int size)
{
    t_block *head = NULL;
    t_block *current = NULL;
    int i;
    char letter;

    i = 0;
    letter = 'A';
    while (i < size)
    {
        if (letter == 'A')
        {
            head = make_block(str + i, letter);
            current = head;
        }
        else
        {
            current->next = make_block(str + i, letter);
            current = current->next;
        }
        letter++;
        i += 21;
    }
    current->next = NULL;
    return(head);
}

t_block	*make_block(char *str, char letter)
{
    t_block *new;

    if (!(new = (t_block*)malloc(sizeof(t_block))))
        return (NULL);
    new->letter = letter;
    return (get_cord(str,new));
}

void	print_list(t_block	*head)
{
    t_block *tmp;
    int i;

    i = 0;
    tmp = head;
    while(tmp != NULL)
    {
        printf("[%c]:\n %d%d%d%d%d%d%d%d\n->\n", tmp->letter, tmp->coord[0], \
        tmp->coord[1],tmp->coord[2],tmp->coord[3],tmp->coord[4], \
        tmp->coord[5],tmp->coord[6],tmp->coord[7]);
        tmp = tmp->next;
        i++;
    }
}

void	free_list(t_block *block)
{
    t_block	*temp;

    while(block != NULL)
    {
        temp = block;
        block = block->next;
        free(temp);
    }
}

size_t		count_in_list(t_block *head)
{
    size_t count;
    t_block *current;

    current = head;
    count = 0;
    while(current)
    {
        count++;
        current = current->next;
    }
    return(count);
}