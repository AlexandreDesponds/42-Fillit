/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:29:16 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/11 06:44:03 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

short			ft_is_putable(char **grid, t_point *start, t_tris *piece)
{
	short	l;

	l = 0;
	while (4 - l)
	{
		if (!(grid[start->y + (piece->coord[l]).y])
			|| !(grid[start->y + (piece->coord[l]).y]
				[start->x + (piece->coord[l]).x]))
			return (0);
		if (((start->y + piece->coord[l].y >= 0)
			|| (start->x + piece->coord[l].x >= 0))
			&& (grid[start->y + (piece->coord[l]).y]
				[start->x + (piece->coord[l]).x] != '.'))
			return (0);
		l++;
	}
	return (1);
}

void			ft_put_piece(char **grid, t_point *start, t_tris *piece)
{
	short	l;

	l = 0;
	while (4 - l)
	{
		grid[start->y + (piece->coord[l]).y]
			[start->x + (piece->coord[l]).x] = piece->name;
		l++;
	}
}

t_point			*ft_new_point(int x, int y)
{
	t_point		*ret;

	ret = (t_point*)malloc(sizeof(t_point));
	ret->x = x;
	ret->y = y;
	return (ret);
}

t_point			*ft_give_next_point(t_point *start, char **grid)
{
	t_point		*ret;
	short		i;
	short		j;

	ret = ft_new_point(-1, -1);
	i = start->y;
	j = start->x + 1;
	while (grid[i])
	{
		while (grid[i][j])
		{
			if (grid[i][j] == '.')
			{
				ret->x = j;
				ret->y = i;
				return (ret);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (ret);
}
