/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:41:53 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/13 16:24:00 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_lastplane(t_plane plane)
{
	if (plane.a == -255 && plane.b == -255 && plane.c == -255 \
	&& plane.d == -255)
		return (1);
	return (0);
}

int	is_lastsprite(t_sprite sprite)
{
	if (sprite.pos.x == -255 && sprite.pos.y == -255 && sprite.pos.z == -255)
		return (1);
	return (0);
}

t_plane	create_sprite_plane(t_vars *vars, int i)
{
	t_plane	plane;
	double	v_norm;

	v_norm = sqrt(pow((double) vars->pc.view.x, 2) + \
	pow((double) vars->pc.view.y, 2) + pow((double) vars->pc.view.z, 2));
	plane.a = vars->pc.view.x / v_norm;
	plane.b = vars->pc.view.y / v_norm;
	plane.c = vars->pc.view.z / v_norm;
	plane.d = - (plane.a * vars->sprites[i].pos.x) - \
	(plane.b * vars->sprites[i].pos.y) - (plane.c * vars->sprites[i].pos.z);
	return (plane);
}

t_plane	*plane_factory_x(t_vars *vars)
{
	t_plane	*planes;
	int		i;

	planes = malloc((vars->cubinfo->map_size[1] + 2) * sizeof(t_plane));
	if (!planes)
	{
		vars_free(vars);
		freestructs_exit(vars->cubinfo, -1);
	}
	i = 1;
	planes[0] = (t_plane){-255, -255, -255, -255};
	while (i < vars->cubinfo->map_size[1])
	{
		planes[i] = (t_plane){1, 0, 0, -(i)};
		i++;
	}
	planes[i] = (t_plane){-255, -255, -255, -255};
	return (planes);
}

t_plane	*plane_factory_y(t_vars *vars)
{
	t_plane	*planes;
	int		i;

	planes = malloc((vars->cubinfo->map_size[0] + 2) * sizeof(t_plane));
	if (!planes)
	{
		vars_free(vars);
		freestructs_exit(vars->cubinfo, -1);
	}
	i = 1;
	planes[0] = (t_plane){-255, -255, -255, -255};
	while (i < vars->cubinfo->map_size[0])
	{
		planes[i] = (t_plane){0, 1, 0, -(i)};
		i++;
	}
	planes[i] = (t_plane){-255, -255, -255, -255};
	return (planes);
}
