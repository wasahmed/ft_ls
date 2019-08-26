/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:05:12 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/26 13:08:40 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    file_type(t_diratr *list, struct stat s)
{
    if ((s.st_mode & S_IFMT) == S_IFDIR)
        ft_putchar('d');
	else
		ft_putchar('-'); //sym link?
}