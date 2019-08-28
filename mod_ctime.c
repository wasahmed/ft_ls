/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_ctime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 07:27:02 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/28 07:58:56 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char    *mod_time(struct stat s)
{
    char    *full;
    char    *month;
    char    *day;
    char    *ret;
    char    *t;
    
    full = ctime(&s.st_mtime);
    month = ft_strsub(full, 4, 3);
    day = ft_strsub(full, 8, 2);
    t = ft_strsub(full,10,6);
    ret = ft_strjoin(ft_strjoin(ft_strjoin(day, " "), month), t);
    return (ret);
}