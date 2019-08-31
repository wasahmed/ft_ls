/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:01:15 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/31 10:40:49 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_flags_env		entry;
	t_diratr		*new;
	int				i;

	i = 1;
	entry.lst = NULL;
	switch_off();
	while (i < argc)
	{
		if (argv[i][0] != '-' && (new = (t_diratr*)malloc(sizeof(t_diratr))))
		{
			new->dir = argv[i];
			new->next = NULL;
			entry.lst = new;
		}
		else if (!check_flags(&entry, argv[i]))
			return (0);
		i++;
	}
	if (!entry.lst)
		ls_basic(&entry);
	exec(&entry);
	return (0);
}
