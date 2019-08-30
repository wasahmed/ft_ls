/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 12:11:01 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/30 12:09:38 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	blocks(t_diratr *list)
{
	struct stat	s;
	int			total;

	total = 0;
	while (list)
	{
		lstat(list->fp, &s);
		total = total + s.st_blocks;
		list = list->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}
