/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:56:28 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/28 08:05:22 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    display_l(t_diratr  *lst)
{
    t_diratr    *list;
    struct stat s;
    char        *b;
    int         i;

    i = 0;
    list = lst;
    while (list != NULL)
    {
        lstat(list->fp, &s);
        file_type(list,s);
        l_perms(list,s);
        user_group(s);
        b = ft_itoa(s.st_size);
        ft_putstr(b);
        if(ft_strlen(b) < 5)
        {
            while (i++ < (5 - ft_strlen(b)))
            {
                ft_putstr(" ");
            }
        }
        ft_putstr(" ");
        ft_putstr(mod_time(s));
        ft_putstr(" ");
        ft_putstr(list->dir);
        list = list->next;
        if (list != NULL)
			ft_putchar('\n');
    }
}
        
