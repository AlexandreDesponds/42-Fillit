/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cread_tris.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:48:16 by adespond          #+#    #+#             */
/*   Updated: 2016/01/11 06:32:56 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_tris		*check_tris(t_tris *tris)
{
	int		i;
	t_point	*coord;

	coord = tris->coord;
	i = -1;
	while (++i < 4)
	{
		if (coord[i].x < 0 || coord[i].x > 4 || coord[i].y < 0
				|| coord[i].y > 4)
			return (0);
	}
	if (check_tris_form(tris) == 0 || (tris = order_tris(tris)) == 0)
		return (NULL);
	return (tris);
}

char		check_tris_form(t_tris *tris)
{
	char	border;
	t_point *coord;
	int		i;
	int		j;

	i = -1;
	coord = tris->coord;
	border = 16;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i != j && ((coord[i].x + 1 == coord[j].x && coord[i].y ==
				coord[j].y) || (coord[i].x - 1 == coord[j].x && coord[i].y ==
				coord[j].y) || (coord[i].x == coord[j].x && coord[i].y + 1 ==
				coord[j].y) || (coord[i].x == coord[j].x && coord[i].y - 1 ==
				coord[j].y)))
				border--;
		}
	}
	if (border <= 10)
		return (1);
	return (0);
}

t_tris		*order_tris(t_tris *tris)
{
	t_point		*coord;
	int			i;
	int			x;
	int			y;

	coord = tris->coord;
	i = -1;
	x = coord[0].x;
	y = coord[0].y;
	while (++i < 4)
	{
		coord[i].x = coord[i].x - x;
		coord[i].y = coord[i].y - y;
	}
	return (tris);
}
