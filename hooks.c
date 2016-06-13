/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 10:36:35 by oexall            #+#    #+#             */
/*   Updated: 2016/06/13 10:54:23 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		keypress(int keycode, void *param)
{
	if (keycode == 53 && (param))
		exit(EXIT_SUCCESS);
	if (keycode == K_UP && (param))
		;
	else if (keycode == K_DOWN && (param))
		;
	else if (keycode == K_LEFT && (param))
		;
	else if (keycode == K_RIGHT && (param))
		;
	return (0);
}

int		keyrelease(int keycode, void *param)
{
	if (keycode == K_UP && (param))
		;
	else if (keycode == K_DOWN && (param))
		;
	else if (keycode == K_LEFT && (param))
		;
	else if (keycode == K_RIGHT && (param))
		;
	return (0);
}
