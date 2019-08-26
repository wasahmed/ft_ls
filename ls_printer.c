/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:55:26 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/26 13:39:39 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ls_printer(t_diratr *lst, t_flags_env flag, char *p)
{
    t_diratr *tmp;

    if (flag->l == 1)
        display_l(lst);
    if (flag->re == 1)
        ft_putendl(ft_strjoin(p, ":"));
    if (flag->r == 1)
        r_l(&lst);
    if (flag->t)
        ls_sorter(&lst, cmptime, 0);
    else
    {
        tmp = lst;
        while (tmp)
        {
            ft_putstr(tmp->dir);
            tmp = tmp->next;
            if (tmp)
                ft_putchar('\n');
        }
    }
    if (flag->re == 1)
        recurse(lst, flag);
}