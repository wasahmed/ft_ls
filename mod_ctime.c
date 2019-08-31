/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_ctime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 07:27:02 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/31 10:37:31 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*join(char *p1, char *time)
{
	char	*p2;

	p2 = ft_strjoin(p1, time);
	ft_memdel((void*)&time);
	ft_memdel((void*)&p1);
	return (p2);
}

char	*mod_time(struct stat s)
{
	char *full;
	char *month;
	char *day;
	char *t;
	char *p1;

	full = ft_strdup(ctime(&s.st_mtime));
	month = ft_strsub(full, 3, 4);
	day = ft_strsub(full, 8, 2);
	t = ft_strsub(full, 10, 6);
	p1 = ft_strjoin(day, month);
	ft_memdel((void*)&full);
	ft_memdel((void*)&month);
	ft_memdel((void*)&day);
	return (join(p1, t));
}
