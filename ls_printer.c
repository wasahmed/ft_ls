/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:55:26 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/30 18:42:18 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_printer(t_diratr *lst, t_flags_env *flag, char *p, t_diratr *tmp)
{
	if (flag->flag_t)
		ls_sorter(&lst, cmptime, 0);
	if (flag->flag_re)
		ft_putendl(ft_strjoin(p, ":"));
	if (flag->flag_r)
		r_l(&lst);
	if (flag->flag_l)
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
	ft_putchar('\n');
	if (flag->flag_re)
		recurse(lst, flag);
}
