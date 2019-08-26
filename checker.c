/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:43:04 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/26 14:52:43 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_file(t_flags_env *e)
{
	if ((e->stream = opendir(".")) != NULL)
	{
		while ((e->pnd = readdir(e->stream)) != NULL)
		{
			lstat(e->pnd->d_name, &e->stats);
			if (S_ISREG(e->stats.st_mode) &&
				ft_strcmp(e->pnd->d_name, e->lst->dir) == 0)
			{
				ft_putendl(e->pnd->d_name);
				return (1);
			}
			else if (!ft_strcmp(e->pnd->d_name, e->lst->dir))
			{
				ft_putstr("ft_ls: ");
				ft_putstr(e->lst->dir);
				ft_putendl(": Permission denied");
				return (-1);
			}
		}
		ft_putstr("ft_ls: ");
		ft_putstr(e->lst->dir);
		ft_putendl(": No such file or directory");
		return (-1);
	}
	return (0);
}
