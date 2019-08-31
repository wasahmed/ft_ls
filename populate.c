/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:37:15 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/31 10:06:03 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_diratr	*populate(char *dir, t_flags_env *env)
{
	t_diratr	*pop;
	char		*str;

	pop = (t_diratr*)malloc(sizeof(t_diratr));
	pop->dir = ft_strdup(env->pnd->d_name);
	str = ft_strjoin(dir, "/");
	pop->fp = ft_strjoin(str, pop->dir);
	lstat(pop->fp, &env->stats);
	pop->t = env->stats.st_mtime;
	(S_ISDIR(env->stats.st_mode) == 1) ? pop->checkdir = 1 : 0;
	free(str);
	str = NULL;
	//free(pop->dir);
	return (pop);
}
