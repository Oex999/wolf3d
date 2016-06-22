/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:09:09 by oexall            #+#    #+#             */
/*   Updated: 2016/06/22 16:49:36 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

/*Header Defines*/
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"

/*Constants Defines*/
	/*window*/
# define WIN_X 640
# define WIN_Y 400
	/*start possition*/
# define S_X 70
# define S_Y 70
# define S_A 0
	/*player details*/
# define FOV 64
# define TILE_SIZE 64
# define VIEW_HEIGHT 32
# define BASE_R_SPD 0.5
# define BASE_T_SPD 0.5

/*Code Defines*/
	/*wolf3d.c*/
# define MLX gamestate.win.mlx
# define WIN gamestate.win.mlx
	/*raycasting.c*/
# define RAYDIRY gamestate->ray.raydiry
# define RAYDIRX gamestate->ray.raydirx
# define DELTADISTX gamestate->ray.deltadistx
# define DELTADISTY gamestate->ray.deltadisty
# define IMG gamestate->img.img

/*Key Defines*/
# define ESC 53
# define K_UP 126
# define K_DOWN 125
# define K_LEFT 123
# define K_RIGHT 124

/*Color Defines*/
# define C_WHITE 0x00FFFFFF
# define C_SKY 0x003399ff
# define C_FLOOR 0x00990000

# define C_NORTH 0x009900cc
# define C_SOUTH 0x00FFFFFF
# define C_EAST 0x00ff6600
# define C_WEST 0x00996633

/*Structs*/
typedef struct	s_ray
{	
	float		deltadistx;
	float		deltadisty;
	float		raydirx;
	float		raydiry;
	float		camera;
	int			wallcontact;
}				t_ray;

typedef struct	s_consts
{
	int			project_dist;
	int			cen_x;
	int			cen_y;
	int			half_fov;
	float		beta_inc;
}				t_consts;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
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

typedef struct	s_playermv
{
	int			traverse;
	int			rotate;
}				t_playermv;

typedef struct	s_img
{
	void		*img;
	char		*d;
	int			bp;
	int			s;
	int			e;
}				t_img;

typedef struct	s_main
{
	int			**array;
	t_win		win;
	t_mapinfo	map;
	t_point		player;
	t_consts	consts;
	t_playermv	playermv;
	t_img		img;
}				t_main;

/*error.c*/
void			ft_puterror(char *error);
/*hooks.c*/
int				keypress(int keycode, t_main *gamestate);
int				keyrelease(int keycode, t_main *gamestate);
/*read_file.c*/
void			free_map(t_mapinfo map);
t_mapinfo		read_map(char *filename);
/*raycasting.c*/
void			draw_collumn(t_win *win, int height, int colour,
					t_point *s_point);
/*draw.c*/
void			draw(t_point *p1, t_point *p2, int color, t_win *win);

/*read_map.c*/
int				**get_array(t_mapinfo *map);

#endif
