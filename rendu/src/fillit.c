/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:51:02 by adespond          #+#    #+#             */
/*   Updated: 2016/01/11 06:32:23 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	fillit(int *argc, char **argv)
{
	t_conf	*conf;

	conf = init_conf();
	if (*argc == 2)
	{
		if ((conf = open_file(argv[1], conf)) != NULL)
		{
			algo(conf);
			ft_print_grid(conf->grid);
			return ;
		}
	}
	ft_putstr("error\n");
}
