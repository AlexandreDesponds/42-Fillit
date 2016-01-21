/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:16:46 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/11 12:10:43 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_point
{
	short			x;
	short			y;
}					t_point;

typedef struct		s_tris
{
	char			name;
	t_point			coord[4];
}					t_tris;

typedef struct		s_conf
{
	char			**grid;
	short			min_size;
	char			nbr_piece;
	struct s_tris	list_tris[26];
}					t_conf;

t_conf				*open_file(char *file, t_conf *conf);
t_conf				*read_file(int *fd, t_conf *conf);
void				fillit(int *argc, char **argv);
t_tris				*create_tris(char *str, char name);
void				create_tris_coord(t_tris *tris, int nbr, int i);
t_tris				*check_tris(t_tris *tris);
char				check_tris_form(t_tris *tris);
t_tris				*init_tris(char name);
t_tris				*order_tris(t_tris *tris);
t_conf				*init_conf();
void				ft_print_grid(char **tab);
char				**ft_new_grid(short nb_piece);
void				ft_del_grid(char ***grid);
void				ft_clean_grid(char **grid, char letter);
void				ft_put_piece(char **grid, t_point *start, t_tris *piece);
t_point				*ft_new_point(int x, int y);
short				ft_is_putable(char **grid, t_point *start, t_tris *piece);
char				**ft_copy_grid(char **grid, short len);
t_point				*ft_give_next_point(t_point *start, char **grid);
char				ft_grid_isfull(char **grid);
int					brain_rec(t_conf *conf, t_point *pos,
					char **grid, int iter);
void				algo(t_conf *config);

#endif
