/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:08:34 by oexall            #+#    #+#             */
/*   Updated: 2016/06/20 08:12:28 by ghavenga         ###   ########.fr       */
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
	ft_printf("Reading Array:\n");
	main.array = get_array(&main.map);

	mlx_loop(main.win.mlx);
	return (0);
}
