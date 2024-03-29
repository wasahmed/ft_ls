/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:01:15 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/02 11:29:24 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*start off by checking whether the 1st element of argv[i] is a	'-' or not  */
/* if yes ->  check if it is a valid flag by passing the arg to check_flags */
/* if no  -> add arg to list which will later be checked if it is a valid   */
/* file or directory                                                        */
/* if there are no args then add "." to the list, which will be used for the*/
/* listing the current directory (i.e ls with no flags).					*/
/* allocate memory for the node, remember to de-allocate					*/

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