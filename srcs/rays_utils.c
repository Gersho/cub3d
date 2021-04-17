/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:03:55 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/17 10:22:22 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	protect_ab(t_vars *vars, int *a, int *b, char *tile)
{
	if (*a <= 0)
		*a = 0;
	if (*a >= vars->cubinfo->map_size[0])
		*a = vars->cubinfo->map_size[0] - 1;
	if (*b <= 0)
		*b = 0;
	if (*b >= vars->cubinfo->map_size[1])
		*b = vars->cubinfo->map_size[1] - 1;
	*tile = vars->cubinfo->map[*a][*b];
}

void	loop_x_inter(t_vars *vars, t_coord vect, t_tmpkit *tmp,
	t_closest *closest)
{
	tmp->inter = inter(vect, vars->pc.pos, vars->planes_x[tmp->i], &tmp->dist);
	if (tmp->dist > 0 && tmp->dist < closest->dist)
	{
		tmp->a = (int)tmp->inter.y;
		tmp->b = (int)roundf(tmp->inter.x);
		if (vect.x < 0)
			tmp->b = tmp->b - 1;
		protect_ab(vars, &tmp->a, &tmp->b, &tmp->tile);
		if (tmp->tile == '1')
		{
			closest->inter = tmp->inter;
			closest->dist = tmp->dist;
			closest->closest_plane = vars->planes_x[tmp->i];
		}
	}
}

void	loop_y_inter(t_vars *vars, t_coord vect, t_tmpkit *tmp,
	t_closest *closest)
{
	tmp->inter = inter(vect, vars->pc.pos, vars->planes_y[tmp->i], &tmp->dist);
	if (tmp->dist > 0 && tmp->dist < closest->dist)
	{
		tmp->b = (int)tmp->inter.x;
		tmp->a = (int)roundf(tmp->inter.y);
		if (vect.y < 0)
			tmp->a = tmp->a - 1;
		protect_ab(vars, &tmp->a, &tmp->b, &tmp->tile);
		if (tmp->tile == '1' || vars->planes_y[tmp->i].c == 1)
		{
			closest->inter = tmp->inter;
			closest->dist = tmp->dist;
			closest->closest_plane = vars->planes_y[tmp->i];
		}
	}
}
