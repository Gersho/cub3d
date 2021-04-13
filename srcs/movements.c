/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:27:20 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/13 16:14:51 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_coord	move_pc(t_vars *vars, float x)
{
	t_coord	res;
	int		a;
	int		b;

	res.x = vars->pc.pos.x + x * (vars->pc.view.x * 0.1);
	res.y = vars->pc.pos.y + x * (vars->pc.view.y * 0.1);
	res.z = vars->pc.pos.z;
	a = (int)(res.y);
	b = (int)(res.x);
	if (a <= 0)
		a = 0;
	if (a >= vars->cubinfo->map_size[0])
		a = vars->cubinfo->map_size[0] - 1;
	if (b <= 0)
		b = 0;
	if (b >= vars->cubinfo->map_size[1])
		b = vars->cubinfo->map_size[1] - 1;
	if (vars->cubinfo->map[a][b] == '1')
		return (vars->pc.pos);
	return (res);
}

static void	move_strafe(t_vars *vars, float x)
{
	vars->pc.angle = vars->pc.angle - (M_PI_2 * x);
	vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
	vars->pc.pos = move_pc(vars, 1);
	vars->pc.angle = vars->pc.angle + (M_PI_2 * x);
	vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
}

static void	cancel_dualpress(t_vars *vars)
{
	if (vars->keys.left == 1 && vars->keys.right == 1)
	{
		vars->keys.left = 0;
		vars->keys.right = 0;
	}
	if (vars->keys.up == 1 && vars->keys.down == 1)
	{
		vars->keys.up = 0;
		vars->keys.down = 0;
	}
	if (vars->keys.turn_l == 1 && vars->keys.turn_r == 1)
	{
		vars->keys.turn_l = 0;
		vars->keys.turn_r = 0;
	}
}

void	update_pc(t_vars *vars)
{
	cancel_dualpress(vars);
	if (vars->keys.up == 1)
		vars->pc.pos = move_pc(vars, 1.2);
	if (vars->keys.down == 1)
		vars->pc.pos = move_pc(vars, -0.6);
	if (vars->keys.left == 1)
		move_strafe(vars, 1);
	if (vars->keys.right == 1)
		move_strafe(vars, -1);
	if (vars->keys.turn_l == 1)
	{
		vars->pc.angle = vars->pc.angle - 0.08;
		vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
	}
	if (vars->keys.turn_r == 1)
	{
		vars->pc.angle = vars->pc.angle + 0.08;
		vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
	}
}

void	vars_pc_init(t_vars *vars)
{
	vars->pc.pos.x = 0.5 + vars->cubinfo->spawn[1];
	vars->pc.pos.y = 0.5 + vars->cubinfo->spawn[0];
	vars->pc.pos.z = 0.5;
	vars->pc.view.x = 0;
	vars->pc.view.y = -1;
	vars->pc.view.z = 0;
	vars->pc.head_tilt = 0.0;
	if (vars->cubinfo->facing == 'N')
	{
		vars->pc.angle = 0;
	}
	else if (vars->cubinfo->facing == 'S')
	{
		vars->pc.angle = M_PI;
	}
	else if (vars->cubinfo->facing == 'E')
	{
		vars->pc.angle = M_PI_2;
	}
	else if (vars->cubinfo->facing == 'W')
	{
		vars->pc.angle = -M_PI_2;
	}
	vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
}
