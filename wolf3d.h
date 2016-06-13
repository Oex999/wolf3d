/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:09:09 by oexall            #+#    #+#             */
/*   Updated: 2016/06/13 10:51:15 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

# define WIN_X 320
# define WIN_Y 200

# define ESC 53
# define K_UP 126
# define K_DOWN 125
# define K_LEFT 123
# define K_RIGHT 124

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

void		ft_puterror(char *error);

int			keypress(int keycode, void *param);
int			keyrelease(int keycode, void *param);

void		free_map(t_mapinfo map);
t_mapinfo	read_map(char *filename);

#endif
