/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:42:22 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/15 15:25:07 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	plane_x_inter(t_vars *vars, t_coord vect, t_closest *closest)
{
	t_tmpkit	tmp;

	tmp.i = (int)vars->pc.pos.x;
	tmp.reverse = 0;
	if (vect.x < 0)
		tmp.reverse = 1;
	else
		tmp.i = tmp.i + 1;
	while (!is_lastplane(vars->planes_x[tmp.i]))
	{
		loop_x_inter(vars, vect, &tmp, closest);
		if (tmp.reverse == 0)
			tmp.i = tmp.i + 1;
		else
			tmp.i = tmp.i - 1;
	}
}

void	plane_y_inter(t_vars *vars, t_coord vect, t_closest *closest)
{
	t_tmpkit	tmp;

	tmp.i = (int)vars->pc.pos.y;
	tmp.reverse = 0;
	if (vect.y < 0)
		tmp.reverse = 1;
	else
		tmp.i = tmp.i + 1;
	while (!is_lastplane(vars->planes_y[tmp.i]))
	{
		loop_y_inter(vars, vect, &tmp, closest);
		if (tmp.reverse == 0)
			tmp.i = tmp.i + 1;
		else
			tmp.i = tmp.i - 1;
	}
}

void	plane_sky_ceil_inter(t_vars *vars, t_coord vect, t_closest *closest)
{
	t_tmpkit	tmp;

	tmp.inter = inter(vect, vars->pc.pos, vars->plane_sky, &tmp.dist);
	if (tmp.dist > 0 && tmp.dist < closest->dist)
	{
		closest->inter = tmp.inter;
		closest->dist = tmp.dist;
		closest->closest_plane = vars->plane_sky;
	}
	tmp.inter = inter(vect, vars->pc.pos, vars->plane_floor, &tmp.dist);
	if (tmp.dist > 0 && tmp.dist < closest->dist)
	{
		closest->inter = tmp.inter;
		closest->dist = tmp.dist;
		closest->closest_plane = vars->plane_floor;
	}
}

t_trgb	ret_trgb(t_vars *vars, t_coord vect, t_closest *closest)
{
	if (closest->closest_plane.b == 1)
	{
		if (vect.y < 0)
			return (get_trgb_from_xpm_n(&vars->n_xpm, closest->inter));
		return (get_trgb_from_xpm_s(&vars->s_xpm, closest->inter));
	}
	if (closest->closest_plane.a == 1)
	{
		if (vect.x < 0)
			return (get_trgb_from_xpm_w(&vars->w_xpm, closest->inter));
		return (get_trgb_from_xpm_e(&vars->e_xpm, closest->inter));
	}
	if (closest->closest_plane.c == 1)
	{
		if (closest->closest_plane.d == 0)
			return (vars->trgb_floor);
		return (vars->trgb_sky);
	}
	return (closest->saved_color);
}

t_trgb	pick_pixel_color(t_vars *vars, t_coord vect)
{
	t_closest	closest;

	closest.dist = 999999;
	sprites_inter(vars, vect, &closest);
	plane_x_inter(vars, vect, &closest);
	plane_y_inter(vars, vect, &closest);
	plane_sky_ceil_inter(vars, vect, &closest);
	return (ret_trgb(vars, vect, &closest));
}
