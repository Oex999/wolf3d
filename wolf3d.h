/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:09:09 by oexall            #+#    #+#             */
/*   Updated: 2016/06/16 10:03:20 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

# define WIN_X 640
# define WIN_Y 400
# define S_X 15
# define S_Y 15
# define S_A 0
# define FOV 64

# define ESC 53
# define K_UP 126
# define K_DOWN 125
# define K_LEFT 123
# define K_RIGHT 124

# define C_WHITE 0x00FFFFFF

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	int			win_x;
	int			win_y;
}				t_win;

typedef struct	s_mapinfo
{
	char		**map;
	long int	lines;
	long int	width;
}				t_mapinfo;

typedef struct	s_point
{
	int			x;
	int			y;
	int			a;
}				t_point;

typedef struct	s_main
{
	t_win		win;
	t_mapinfo	map;
	t_point		player;
}				t_main;

/*error.c*/
void			ft_puterror(char *error);
/*hooks.c*/
int				keypress(int keycode, void *param);
int				keyrelease(int keycode, void *param);
/*read_file.c*/
void			free_map(t_mapinfo map);
t_mapinfo		read_map(char *filename);
/*raycasting.c*/
void			draw_collumn(t_win *win, int height, int colour,
					t_point *s_point);

#endif
