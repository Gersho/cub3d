/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:42:22 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/16 15:22:52 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_plane	*plane_factory(t_cubinfo *cubinfo)
{
	int	i;
	int	j;
	t_plane *planes;

	i = 0;
	j = 0;
	planes = malloc((cubinfo->map_size[0] + cubinfo->map_size[1] + 1) * sizeof(t_plane));
	printf("planes:%d\n", (cubinfo->map_size[0] + cubinfo->map_size[1] + 1));
	if (!planes)
		exit(0);
	while (i < cubinfo->map_size[0] - 1)
	{
		planes[i] = (t_plane){0, 1, 0, -(i + 1)};
		i++;
	}
	while (j < cubinfo->map_size[1] - 1)
	{
		planes[i+j] = (t_plane){1, 0, 0, -(j + 1)};
		j++;
	}
	//floor
	planes[i+j] = (t_plane){0, 0, 1, 0};
	//sky
	planes[i+j+1] = (t_plane){0, 0, 1, -1};
	planes[i+j+2] = (t_plane){-255, -255, -255, -255};
	return (planes);
}

// t_trgb pick_pixel_color(t_vars *vars, t_vect vect)
// {

// }

t_trgb	pick_pixel_color(t_vars *vars, t_vect vect)
{
	t_plane p1;
	t_plane p2;
	t_plane p3;
	t_plane p4;
	t_plane p_floor;
	t_plane p_sky;
	float	dist;
	float	dist_tmp;
	t_coord inter;
	t_coord	inter_tmp;
	t_trgb trgb;
	char	tile;
	int a;
	int b;

	dist_tmp = 0;
	dist = 0;

	p1.a = 0;
	p1.b = 1;
	p1.c = 0;
	p1.d = -1;

	p2.a = 0;
	p2.b = 1;
	p2.c = 0;
	p2.d = -4;
	//p2 = (t_plane){0, 1, 0, -7};

	p3.a = 1;
	p3.b = 0;
	p3.c = 0;
	p3.d = -1;

	p4.a = 1;
	p4.b = 0;
	p4.c = 0;
	p4.d = -4;

	p_floor.a = 0;
	p_floor.b = 0;
	p_floor.c = 1;
	p_floor.d = 0;
	
	p_sky.a = 0;
	p_sky.b = 0;
	p_sky.c = 1;
	p_sky.d = -1;


	inter_tmp = intersection(vect, vars->pc.pos, p4, &dist_tmp);
		dist = dist_tmp;
		inter = inter_tmp;
	if (dist > 0 && inter.z >= 0 && inter.z < 1)
		return (vars->trgb_wall_e);

	inter_tmp = intersection(vect, vars->pc.pos, p1, &dist_tmp);
	dist = dist_tmp;
	inter = inter_tmp;
	if (dist > 0 && inter.z >= 0 && inter.z < 1)
		return (vars->trgb_wall_n);

	inter_tmp = intersection(vect, vars->pc.pos, p3, &dist_tmp);
		dist = dist_tmp;
		inter = inter_tmp;
	if (dist > 0 && inter.z >= 0 && inter.z < 1)
		return (vars->trgb_wall_s);

	inter_tmp = intersection(vect, vars->pc.pos, p2, &dist_tmp);
		dist = dist_tmp;
		inter = inter_tmp;
	if (dist > 0 && inter.z >= 0 && inter.z < 1)
		return (vars->trgb_wall_w);

	inter_tmp = intersection(vect, vars->pc.pos, p_floor, &dist_tmp);
	dist = dist_tmp;
	inter = inter_tmp;
	//if (dist > 0 && inter.z >= 0 && inter.z < 1)
	if (dist > 0)
		return (vars->trgb_floor);

	inter_tmp = intersection(vect, vars->pc.pos, p_sky, &dist_tmp);
		dist = dist_tmp;
		inter = inter_tmp;
	//if (dist > 0 && inter.z >= 0 && inter.z < 1)
	if (dist > 0)
		return (vars->trgb_sky);

	

		a = (int)inter.y;
		b = (int)inter.x;

		if (a <= 0)
			a = 1;
		if (a >= vars->cubinfo->map_size[0])
			a = vars->cubinfo->map_size[0] - 1;
		if (b <= 0)
			b = 1;
		if (b >= vars->cubinfo->map_size[1])
			b = vars->cubinfo->map_size[1] - 1;


		tile = vars->cubinfo->map[a - 1][b - 1];
		
		if (tile == '1')
		{
			trgb = vars->trgb_wall;
			//coord_print(inter);
		}
		else
			trgb = vars->trgb_text;
	//}
	return (trgb);
}