/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:41:53 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/10 13:30:43 by kzennoun         ###   ########lyon.fr   */
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
