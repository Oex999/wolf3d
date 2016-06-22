/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:08:34 by oexall            #+#    #+#             */
/*   Updated: 2016/06/22 07:55:00 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_main	gamestate;

	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_X, WIN_Y, "Wolf3D");
	mlx_hook(WIN, 2, (1L << 0), &keypress, &gamestate);
	mlx_hook(WIN, 3, (1L << 1), &keyrelease, &gamestate);
	if (!(argc > 1 && argc < 3) || !(argv[1]))
		ft_puterror("main: Invalid Args");

	gamestate.map = read_map(argv[1]);
	ft_printf("Reading Array:\n");
	gamestate.array = get_array(&gamestate.map);

	mlx_loop(gamestate.win.mlx);
	return (0);
}
