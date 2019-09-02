/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 11:44:48 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/02 11:31:04 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* for current directory */

void	ls_basic(t_flags_env *entry)
{
	entry->lst = (t_diratr*)malloc(sizeof(t_diratr));
	entry->lst->dir = ".";
	entry->lst->next = NULL;
}
