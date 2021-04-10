/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:31:09 by karim             #+#    #+#             */
/*   Updated: 2021/04/10 13:46:18 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int keydown(int keycode, t_vars *vars)
{
	if (keycode == 53)
		normal_shutdown(vars);
	if (keycode == 12)
		vars->keys.turn_l = 1;
	if (keycode == 13)
		vars->keys.up = 1;
	if (keycode == 14)
		vars->keys.turn_r = 1;
	if (keycode == 0)
		vars->keys.left = 1;
	if (keycode == 1)
		vars->keys.down = 1;
	if (keycode == 2)
		vars->keys.right = 1;
	return (0);
}

int keyup(int keycode, t_vars *vars)
{
	if (keycode == 12)
		vars->keys.turn_l = 0;
	if (keycode == 13)
		vars->keys.up = 0;
	if (keycode == 14)
		vars->keys.turn_r = 0;
	if (keycode == 0)
		vars->keys.left = 0;
	if (keycode == 1)
		vars->keys.down = 0;
	if (keycode == 2)
		vars->keys.right = 0;
	return (0);
}