/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:01:06 by adespond          #+#    #+#             */
/*   Updated: 2016/01/11 12:34:02 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_conf	*open_file(char *file, t_conf *conf)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if ((conf = read_file(&fd, conf)) == 0)
		return (NULL);
	return (conf);
}

t_conf	*read_file(int *fd, t_conf *conf)
{
	char	*buff;
	int		i;
	t_tris	*tris;
	int		last_read;
	int		now_read;

	i = 0;
	last_read = -1;
	buff = ft_strnew(21);
	while ((now_read = read(*fd, buff, 21)))
	{
		last_read = now_read;
		tris = create_tris(buff, i);
		if (tris == NULL)
			return (NULL);
		conf->nbr_piece = i + 1;
		conf->list_tris[i] = *tris;
		i++;
	}
	if (last_read != 20 || now_read != 0)
		return (NULL);
	return (conf);
}
