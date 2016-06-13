/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:08:34 by oexall            #+#    #+#             */
/*   Updated: 2016/06/13 10:56:25 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main_key_hook(int keycode, void *param)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (param)
		;
	return (0);
}

int		main(int argc, char **argv)
{
	t_win		win;
	t_mapinfo	map;

	win.win_x = WIN_X;
	win.win_y = WIN_Y;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.win_x, win.win_y, "Wolf3D");
	mlx_hook(win.win, 2, (1L << 0), &keypress, &win);
	mlx_hook(win.win, 3, (1L << 1), &keyrelease, &win);
	if (!(argc > 1 && argc < 3) || !(argv[1]))
		ft_puterror("main: Invalid Args");
	map = read_map(argv[1]);
	mlx_loop(win.mlx);
	return (0);
}
