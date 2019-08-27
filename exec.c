/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 12:03:45 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/27 11:56:59 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    process_ls(char *dir, t_flags_env *env)
{
    t_diratr    *lst;
    t_diratr    *p;

    lst = NULL;
    if ((env->stream = opendir(dir)))
    {
        while ((env->pnd = readdir(env->stream)) != NULL)
        {
            if (env->pnd->d_name[0] != '.' || env->flag_a == 1)
            {
                p = (t_diratr*)malloc(sizeof(t_diratr));
                p->dir = env->pnd->d_name;
                p->fp = ft_strjoin(ft_strjoin(dir, "/"), env->pnd->d_name);
                lstat(p->fp, &env->stats);
                p->t = env->stats.st_mtime;
                if ((S_ISDIR(env->stats.st_mode)) == 1)
                    p->checkdir = 1;
                else
                    p->checkdir = 0;
                p->next = lst;
                lst = p;
            }
        }
        ls_sorter(&lst, cmpstr, 0);
        ls_printer(lst, env, dir);
    }
    //check_file(env);
}

void    exec(t_flags_env *entry)
{
    t_diratr    *ls;

    ls = entry->lst;
    while (ls)
    {
        process_ls(ls->dir, entry);
        ls = ls ->next;
    }
}
