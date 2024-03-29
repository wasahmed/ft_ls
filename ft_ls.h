/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 07:33:02 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/31 10:12:00 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <time.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <pwd.h>

typedef	struct		s_diratr
{
	char			*fp;
	char			*dir;
	int				checkdir;
	time_t			t;
	struct s_diratr	*next;
}					t_diratr;

typedef	struct		s_flags_env
{
	DIR				*stream;
	struct dirent	*pnd;
	struct stat		stats;
	int				flag_l;
	int				flag_a;
	int				flag_t;
	int				flag_r;
	int				flag_re;
	t_diratr		*lst;
}					t_flags_env;

int					check(t_flags_env *e);
void				display_l(t_diratr *lst);
void				process_ls(char *dir, t_flags_env *env);
void				exec(t_flags_env *entry);
void				file_type(struct stat s);
void				l_perms(struct stat s);
void				user_group(struct stat s);
void				ls_basic(t_flags_env *entry);
void				switch_off();
int					check_flags(t_flags_env *f, char *arg);
void				ls_printer(t_diratr	*lst, t_flags_env *flag, char *p,\
		t_diratr *tmp);
int					cmpstr(t_diratr	dir1, t_diratr dir2);
int					cmptime(t_diratr dir1, t_diratr dir2);
void				ls_sorter(t_diratr **h, int (*cmp)(t_diratr, t_diratr),\
		int done);
void				r_l(t_diratr **head);
void				recurse(t_diratr *list, t_flags_env *e);
char				*mod_time(struct stat s);
void				blocks(t_diratr *list);
void				check_link(t_diratr *name, struct stat s);
t_diratr			*populate(char *dir, t_flags_env *env);
void				free_dir_list(t_diratr **dlist);
char				*join(char *p1, char*time);

#endif
