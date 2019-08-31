/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:56:28 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/31 10:45:54 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_l(t_diratr *lst)
{
	t_diratr		*list;
	struct stat		s;
	char			*b;
	char			*tmp;

	list = lst;
	while (list != NULL)
	{
		lstat(list->fp, &s);
		file_type(s);
		l_perms(s);
		user_group(s);
		b = ft_itoa(s.st_size);
		ft_putstr(b);
		ft_memdel((void*)&b);
		ft_putstr("   ");
		ft_putstr(tmp = mod_time(s));
		ft_memdel((void*)&tmp);
		ft_putstr("   ");
		ft_putstr(list->dir);
		ft_putstr((S_ISLNK(s.st_mode)) ? "  ->  " : 0);
		check_link(list, s);
		list = list->next;
		list != NULL ? ft_putchar('\n') : exit(0);
	}
}
