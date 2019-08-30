/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_l.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:36:17 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/30 18:20:42 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	r_l(t_diratr **head)
{
	t_diratr	*prev;
	t_diratr	*current;
	t_diratr	*next;

	current = *head;
	prev = NULL;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}
