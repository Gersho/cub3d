/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:27:20 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/31 14:08:51 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_coord move_pc(t_vars *vars, float x)
{
	t_coord res;

	res.x = vars->pc.pos.x + x * (vars->pc.view.x * 0.1);
	res.y = vars->pc.pos.y + x * (vars->pc.view.y * 0.1);
	res.z = vars->pc.pos.z;
	
	return (res);
}

void	update_pc(t_vars *vars)
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
	if (vars->keys.up == 1)
		vars->pc.pos = move_pc(vars, 1);
	if (vars->keys.down == 1)
		vars->pc.pos = move_pc(vars, -0.5);
	if (vars->keys.left == 1)
	{
		vars->pc.angle = vars->pc.angle - M_PI_2;
		vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
		vars->pc.pos = move_pc(vars, 1);
		vars->pc.angle = vars->pc.angle + M_PI_2;
		vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
	}
	if (vars->keys.right == 1)
	{
		vars->pc.angle = vars->pc.angle + M_PI_2;
		vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
		vars->pc.pos = move_pc(vars, 1);
		vars->pc.angle = vars->pc.angle - M_PI_2;
		vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
	}

	if (vars->keys.turn_l == 1)
	{
		vars->pc.angle = vars->pc.angle - 0.05;
		vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
	}
	if (vars->keys.turn_r == 1)
	{
		vars->pc.angle = vars->pc.angle + 0.05;
		vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
	}
}