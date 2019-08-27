/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_perms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:08:59 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/27 13:16:37 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    l_perms(t_diratr *lst,struct stat s)
{
    ft_putchar( (s.st_mode & S_IRUSR) ? 'r' : '-');
    ft_putchar( (s.st_mode & S_IWUSR) ? 'w' : '-');
    ft_putchar( (s.st_mode & S_IXUSR) ? 'x' : '-');
    ft_putchar( (s.st_mode & S_IRGRP) ? 'r' : '-');
    ft_putchar( (s.st_mode & S_IWGRP) ? 'w' : '-');
    ft_putchar( (s.st_mode & S_IXGRP) ? 'x' : '-');
    ft_putchar( (s.st_mode & S_IROTH) ? 'r' : '-');
    ft_putchar( (s.st_mode & S_IWOTH) ? 'w' : '-');
    ft_putchar( (s.st_mode & S_IXOTH) ? 'x' : '-');
    ft_putstr(" ");
    ft_putnbr(s.st_nlink);
    ft_putstr(" ");
}

void    user_group(struct stat s)
{
    struct  passwd  *o;
    struct  group   *g;
    
    o = getpwuid(s.st_uid);
    g = getgrgid(s.st_gid);
    
    //if (o == NULL)
      //  ft_putendl("Hey");
    ft_putstr(o->pw_name);
    ft_putstr(" ");
    ft_putstr(g->gr_name);
    ft_putstr(" ");
    
}
