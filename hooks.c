/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 10:36:35 by oexall            #+#    #+#             */
/*   Updated: 2016/06/13 14:24:21 by ghavenga         ###   ########.fr       */
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
	//instantiate while loops to allow for held in keys that continue to functions as long as the keycode is = to the appropriate key
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
