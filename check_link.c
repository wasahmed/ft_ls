/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:25:24 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/29 13:46:33 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    check_link(t_diratr *name, struct stat s)
{
    int     i;
    char    buff[1000];

    i = 0;
    if (S_ISLNK(s.st_mode))
    {
        if (readlink(name->fp, buff, sizeof(buff)) != -1)
        ft_putstr(buff);    
    }
}