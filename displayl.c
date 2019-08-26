/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:56:28 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/26 14:18:07 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    display_l(t_diratr  *lst)
{
    t_diratr    *list;
    struct stat s;
    char        *b;

    list = lst;
    while (list)
    {
        file_type(list, s);
        l_perms(list, s);
        user_group(s);
        b = ft_itoa(s.st_size);
        ft_putstr(b);
        ft_putstr(" ");
        ft_putstr(ctime(&s.st_mtime));
        ft_putstr(" ");
        ft_putstr(lst->dir->d_name)
        list = list->next;
        if (list)
			ft_putchar('\n');
    }
}
        