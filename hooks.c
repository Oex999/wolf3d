/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 10:36:35 by oexall            #+#    #+#             */
/*   Updated: 2016/06/22 07:56:41 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		keypress(int keycode, t_main *gamestate)
{
	if (keycode == K_UP)
		gamestate->playermv.traverse = 1;
	else if (keycode == K_DOWN)
		gamestate->playermv.traverse = -1;
	else if (keycode == K_LEFT)
		gamestate->playermv.rotate = -1;
	else if (keycode == K_RIGHT)
		gamestate->playermv.rotate = 1;
	return (0);
}

int		keyrelease(int keycode, t_main *gamestate)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == K_UP)
		gamestate->playermv.traverse = 0;
	else if (keycode == K_DOWN)
		gamestate->playermv.traverse = 0;
	else if (keycode == K_LEFT)
		gamestate->playermv.rotate = 0;
	else if (keycode == K_RIGHT)
		gamestate->playermv.rotate = 0;
	return (0);
}

void	move()//t_main *gamestate)
{
	//insert sin/cos functionality to create consistent movement across squares
	//at angles
	BASE_T_SPD;
}

void	rotate(t_main *gamestate)
{
	if (gamestate->playermv.rotate == 1)
		gamestate->player.a == (gamestate->player.a + BASE_R_SPD) % (int)360;	
	else if (gamestate->playermv.rotate == -1)
		gamestate->player.a == (gamestate->player.a - BASE_R_SPD) % (int)360;
}
