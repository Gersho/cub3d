/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:11:02 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/16 16:13:49 by kzennoun         ###   ########lyon.fr   */
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
}