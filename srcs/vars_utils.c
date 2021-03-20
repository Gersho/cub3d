/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:11:02 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/20 12:49:41 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	vars_set_trgb(t_vars *vars)
{
	vars->trgb_floor.t = 0;
	vars->trgb_floor.r = 0;
	vars->trgb_floor.g = 255;
	vars->trgb_floor.b = 0;

	vars->trgb_sky.t = 0;
	vars->trgb_sky.r = 0;
	vars->trgb_sky.g = 0;
	vars->trgb_sky.b = 255;

	vars->trgb_wall_e.t = 0;
	vars->trgb_wall_e.r = 255;
	vars->trgb_wall_e.g = 255;
	vars->trgb_wall_e.b = 255;

	vars->trgb_wall_n.t = 0;
	vars->trgb_wall_n.r = 255;
	vars->trgb_wall_n.g = 255;
	vars->trgb_wall_n.b = 0;

	vars->trgb_wall_s.t = 0;
	vars->trgb_wall_s.r = 255;
	vars->trgb_wall_s.g = 0;
	vars->trgb_wall_s.b = 255;

	vars->trgb_wall_w.t = 0;
	vars->trgb_wall_w.r = 255;
	vars->trgb_wall_w.g = 0;
	vars->trgb_wall_w.b = 0;

	vars->trgb_wall.t = 0;
	vars->trgb_wall.r = 255;
	vars->trgb_wall.g = 255;
	vars->trgb_wall.b = 255;

	vars->trgb_text.t = 0;
	vars->trgb_text.r = 0;
	vars->trgb_text.g = 0;
	vars->trgb_text.b = 0;

	vars->img.trgb.t = 0;
	vars->img.trgb.r = vars->img.trgb.g = vars->img.trgb.b = 255;
	//printf("coucou\n");
	//color_print(vars->trgb_wall);
}

void	vars_init(t_cubinfo *cubinfo, t_vars *vars)
{
	vars->planes = plane_factory(cubinfo);
	plane_print(vars->planes);
	vars->cubinfo = cubinfo;
	vars_set_trgb(vars);

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
		vars->pc.angle =   - M_PI_2;
	}
	vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
}