/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:55:26 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/29 13:48:48 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ls_printer(t_diratr *lst, t_flags_env *flag, char *p)
{
    t_diratr *tmp;
    if (flag->flag_t)
        ls_sorter(&lst, cmptime, 0);
    if (flag->flag_re == 1)
        ft_putendl(ft_strjoin(p, ":"));
    if (flag->flag_r == 1)
        r_l(&lst);
    if (flag->flag_l == 1)
    {
        blocks(lst);
        display_l(lst);
    }
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
    if (flag->flag_re == 1)
        recurse(lst, flag);
    ft_putchar('\n');
}
