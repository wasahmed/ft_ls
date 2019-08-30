/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_perms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:08:59 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/30 15:16:05 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	l_perms(t_diratr *lst, struct stat s)
{
	ft_putchar((s.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((s.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((s.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((s.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((s.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((s.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((s.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((s.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((s.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("   ");
	ft_putnbr(s.st_nlink);
	ft_putstr("   ");
}

void	user_group(struct stat s)
{
	struct passwd	*o;
	struct group	*g;
	char			*group;
	char			*owner;

	if (!(o = getpwuid(s.st_uid)))
		owner = ft_itoa(s.st_uid);
	else
		owner = ft_strdup(o->pw_name);
	if (!(g = getgrgid(s.st_gid)))
		group = ft_itoa(s.st_gid);
	else
		group = ft_strdup(g->gr_name);
	ft_putstr(owner);
	ft_putstr(" ");
	ft_putstr(group);
	ft_putstr(" ");
	free(owner);
	free(group);
}
