/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karim <karim@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:31:09 by karim             #+#    #+#             */
/*   Updated: 2021/03/30 16:54:43 by karim            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int keydown(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(1);
	// if (keycode == 82)
	// {
	// 	vars->pc.angle = 0.0;
	// 	vars->pc.pos.x = 0.5 + vars->cubinfo->spawn[1];
	// 	vars->pc.pos.y = 0.5 + vars->cubinfo->spawn[0];
	// 	vars->pc.pos.z = 0.5;
	// }
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