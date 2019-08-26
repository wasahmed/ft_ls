/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:23:47 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/26 14:08:21 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
int     cmpstr(t_diratr dir1, t_diratr dir2)
{
    return (ft_strcmp(dir1.dir, dir2.dir));
}

int     cmptime(t_diratr dir1, t_diratr dir2)
{
    if (dir1.t < dir2.t)
        return (1);
    else
        return (0);
}

void    ls_sorter(t_diratr  **h, int (*cmp)(t_diratr,t_diratr), int done)
{
    t_diratr    *tmp;
    t_diratr    **src;
    t_diratr    *next;

    while (!done && *h != NULL && ((*h)->next))
    {
        src = head;
        tmp = *h;
        next = (*h)->next;
        done = 1;
        while (next)
        {
            if (cmp(*tmp, *next) > 0)
            {
                tmp->next = next->next;
                next->next = tmp;
                *src = next;
                done = 0;
            }
            src = &tmp->next;
            temp = next;
            next = next->next;
        }
    }
}