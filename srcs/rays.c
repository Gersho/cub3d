/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:42:22 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/15 14:19:21 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	plane_x_inter(t_vars *vars, t_coord vect, t_closest *closest)
{
	int			i;
	t_tmpkit	tmp;

	i = (int)vars->pc.pos.x;
	tmp.reverse = 0;
	if (vect.x < 0)
		tmp.reverse = 1;
	else
		i++;
	while (!is_lastplane(vars->planes_x[i]))
	{
		tmp.inter = intersection(vect, vars->pc.pos, vars->planes_x[i], &tmp.dist);
		if (tmp.dist > 0 && tmp.dist < closest->dist)
		{
			tmp.a = (int)tmp.inter.y;
			tmp.b = (int)roundf(tmp.inter.x);
			if (vect.x < 0)
				tmp.b = tmp.b - 1;
			protect_ab(vars, &tmp.a, &tmp.b, &tmp.tile);
			if (tmp.tile == '1')
			{
				closest->inter = tmp.inter;
				closest->dist = tmp.dist;
				closest->closest_plane = vars->planes_x[i];
			}
		}
		if(tmp.reverse == 0)
			i++;
		else
			i--;
	}
}

void	plane_y_inter(t_vars *vars, t_coord vect, t_closest *closest)
{
	int			i;
	t_tmpkit	tmp;

	i = (int)vars->pc.pos.y;
	tmp.reverse = 0;
	if (vect.y < 0)
		tmp.reverse = 1;
	else
		i++;
	while (!is_lastplane(vars->planes_y[i]))
	{
		tmp.inter = intersection(vect, vars->pc.pos, vars->planes_y[i], &tmp.dist);
		if (tmp.dist > 0 && tmp.dist < closest->dist)
		{
			tmp.b = (int)tmp.inter.x;
			tmp.a = (int)roundf(tmp.inter.y);	
			if (vect.y < 0)
				tmp.a = tmp.a - 1;
			protect_ab(vars, &tmp.a, &tmp.b, &tmp.tile);
			if (tmp.tile == '1' || vars->planes_y[i].c == 1)
			{
				closest->inter = tmp.inter;
				closest->dist = tmp.dist;
				closest->closest_plane = vars->planes_y[i];
			}
		}
		if(tmp.reverse == 0)
			i++;
		else
			i--;
	}
}


void	plane_sky_ceil_inter(t_vars *vars, t_coord vect, t_closest *closest)
{
	t_tmpkit	tmp;
	
	tmp.inter = intersection(vect, vars->pc.pos, vars->plane_sky, &tmp.dist);
	if (tmp.dist > 0 && tmp.dist < closest->dist)
	{
		closest->inter = tmp.inter;
		closest->dist = tmp.dist;
		closest->closest_plane = vars->plane_sky;
	}
	tmp.inter = intersection(vect, vars->pc.pos, vars->plane_floor, &tmp.dist);
	if (tmp.dist > 0 && tmp.dist < closest->dist)
	{
		closest->inter = tmp.inter;
		closest->dist = tmp.dist;
		closest->closest_plane = vars->plane_floor;
	}


}

t_trgb pick_pixel_color(t_vars *vars, t_coord vect)
{
	t_closest	closest;

	closest.dist = 999999;
	sprites_inter(vars, vect, &closest);
	plane_x_inter(vars, vect, &closest);
	plane_y_inter(vars, vect, &closest);
	plane_sky_ceil_inter(vars, vect, &closest);
	if (closest.closest_plane.b == 1)
	{
		if (vect.y < 0)
			return (get_trgb_from_xpm_n(&vars->n_xpm, closest.inter));
		return (get_trgb_from_xpm_s(&vars->s_xpm, closest.inter));
	}
	if (closest.closest_plane.a == 1)
	{
		if (vect.x < 0)
			return (get_trgb_from_xpm_w(&vars->w_xpm, closest.inter));
		return (get_trgb_from_xpm_e(&vars->e_xpm, closest.inter));
	}
	if (closest.closest_plane.c == 1)
	{
		if (closest.closest_plane.d == 0)
			return (vars->trgb_floor);
		return (vars->trgb_sky);
	}
	return (closest.saved_color);
}
