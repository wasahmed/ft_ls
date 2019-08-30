/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:40:04 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/30 18:57:46 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recurse(t_diratr *list, t_flags_env *e)
{
	t_diratr	*temp;
	char		*find;

	temp = list;
	while (temp != NULL)
	{
		find = ft_strrchr(temp->fp, '/');
		if (temp->checkdir == 1 && !(ft_strequ(find, "/."))
		&& !(ft_strequ(find, "/..")))
			process_ls(temp->fp, e);
		temp = temp->next;
	}
}
