/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filetype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:05:12 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/30 18:54:21 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	file_type(struct stat s)
{
	if ((s.st_mode & S_IFMT) == S_IFDIR)
		ft_putchar('d');
	else if (S_ISCHR(s.st_mode))
		ft_putchar('c');
	else
		ft_putchar((S_ISLNK(s.st_mode)) ? 'l' : '-');
}
