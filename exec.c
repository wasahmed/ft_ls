/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 12:03:45 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/02 11:59:19 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* use opendir to get the directory stream									*/
/* readdir return a dirent pointer which allows us to access the attributes */
/* of the struct dirent. E.g d_name which gives us the name of the file or  */
/* directory that is being pointed to										*/

void	process_ls(char *dir, t_flags_env *env)
{
	t_diratr	*lst;
	t_diratr	*lstp;

	lst = NULL;
	if ((env->stream = opendir(dir)) != NULL)
	{
		while ((env->pnd = readdir(env->stream)) != NULL)
		{
			if (env->pnd->d_name[0] != '.' || env->flag_a == 1)
			{
				lstp = populate(dir, env);
				lstp->next = lst;
				lst = lstp;
			}
		}
		ls_sorter(&lst, cmpstr, 0);
		ls_printer(lst, env, dir, lst);
		free_dir_list(&lst);
		return ;
	}
	check(env);
}

void	exec(t_flags_env *entry)
{
	t_diratr	*lstp;

	lstp = entry->lst;
	while (lstp)
	{
		process_ls(lstp->dir, entry);
		lstp = lstp->next;
	}
}
