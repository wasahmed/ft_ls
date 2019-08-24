/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 10:49:23 by wasahmed          #+#    #+#             */
/*   Updated: 2019/08/24 11:32:05 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*                     #1      */
void     switch_off()
{
    t_flags_env     flag;

    flag.flag_l = 0;
	flag.flag_a = 0;
	flag.flag_t = 0;
	flag.flag_r = 0;
	flag.flag_re = 0;
}

int     check_flags(t_flags_env *f, char *arg)
{
    int     i;
    
    i   = 1;
    while(arg[i])
    {
        if(arg[i] == 'a')
            f->flag_a = 1;
        else if (arg[i] == 'r')
            f->flag_r = 1;
        else if (arg[i] == 't')
            f->flag_t = 1;
        else if (arg[i] == 'l')
            f->flag_l = 1;
        else if (arg[i] == 'R')
            f->flag_re = 1;
        else
        {
            ft_putstr(arg);
            ft_putendl(": Invalid");
            return (0);
        }
        i++;
    }
    return (1);
}