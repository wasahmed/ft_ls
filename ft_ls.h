/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 07:33:02 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/24 15:07:02 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <unistd.h>
# include <dirent.h>  // for struct dirent, DIR, opendir, readdir, closedir
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef	struct			s_diratr
{
	char				*fp;
	char				*dir;
	int					checkdir;
	time_t				t;
	struct	s_diratr	*next;
}						t_diratr

typedef	struct	s_flags_env
{
	DIR				*stream;
	struct	dirent	*pnd;
	struct	stat	stats;
	int				flag_l;
	int				flag_a;
	int				flag_t;
	int				flag_r;
	int				flag_re;
	t_diratr		*lst;
}				t_flags_env;




#endif
