/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 10:36:35 by oexall            #+#    #+#             */
/*   Updated: 2016/06/20 08:47:52 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		keypress(int keycode, t_main *gamestate)
{
	if (keycode == K_UP && (param))
		gamestate->playermv.traverse = 1;
	else if (keycode == K_DOWN && (param))
		gamestate->playermv.traverse = -1;
	else if (keycode == K_LEFT && (param))
		gamestate->playermv.rotate = -1;
	else if (keycode == K_RIGHT && (param))
		gamestate->playermv.rotate = 1;
	return (0);
}

int		keyrelease(int keycode, t_main *gamestate)
{
	if (keycode == 53 && (param))
		exit(EXIT_SUCCESS);
	else if (keycode == K_UP && (param))
		gamestate->playermv.traverse = 0;
	else if (keycode == K_DOWN && (param))
		gamestate->playermv.traverse = 0;
	else if (keycode == K_LEFT && (param))
		gamestate->playermv.rotate = 0;
	else if (keycode == K_RIGHT && (param))
		gamestate->playermv.rotate = 0;
	return (0);
}

void	move(t_main *gamestate)
{
	
}

void	rotate(t_main *gamestate)
{
	
}
