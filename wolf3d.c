/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:08:34 by oexall            #+#    #+#             */
/*   Updated: 2016/06/16 10:05:14 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_main	main;

	main.win.win_x = WIN_X;
	main.win.win_y = WIN_Y;
	main.win.mlx = mlx_init();
	main.win.win = 
		mlx_new_window(main.win.mlx, main.win.win_x, main.win.win_y, "Wolf3D");
	mlx_hook(main.win.win, 2, (1L << 0), &keypress, &main);
	mlx_hook(main.win.win, 3, (1L << 1), &keyrelease, &main);
	if (!(argc > 1 && argc < 3) || !(argv[1]))
		ft_puterror("main: Invalid Args");
	main.map = read_map(argv[1]);
	mlx_loop(main.win.mlx);
	return (0);
}
