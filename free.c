/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 06:40:34 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/31 08:52:54 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_dir_list(t_diratr **dlist)
{
	t_diratr *ptr;

	ptr = NULL;
	if ((dlist && *dlist))
	{
		ptr = (*dlist);
		while (ptr)
		{
			(*dlist) = (*dlist)->next;
			ptr->next = NULL;
			ft_memdel((void*)&ptr->dir);
			ft_memdel((void*)&ptr->fp);
			ft_memdel((void*)&ptr);
			ptr = (*dlist);
		}
	}
	return ;
}
