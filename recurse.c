/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:40:04 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/26 14:26:56 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recurse(t_diratr *list, t_flags_env *e)
{
	t_diratr *temp;

	temp = list;
	while (temp != NULL)
	{
		if (temp->checkdir == 1 && temp->dir[0] != '.')
			process_ls(temp->fp, e);
		temp = temp->next;
	}
}
