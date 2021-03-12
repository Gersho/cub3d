/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:42:22 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/12 16:31:38 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

	dist_tmp = 0;
	dist = 0;

	p1.a = 0;
	p1.b = 1;
	p1.c = 0;
	p1.d = -1;

	p2.a = 0;
	p2.b = 1;
	p2.c = 0;
	p2.d = -7;

	p3.a = 1;
	p3.b = 0;
	p3.c = 0;
	p3.d = -1;

	p4.a = 1;
	p4.b = 0;
	p4.c = 0;
	p4.d = -10;

	p_floor.a = 0;
	p_floor.b = 0;
	p_floor.c = 1;
	p_floor.d = 0;
	
	p_sky.a = 0;
	p_sky.b = 0;
	p_sky.c = 1;
	p_sky.d = 1;


	inter_tmp = intersection(vect, vars->pc.pos, p1, &dist_tmp);
	dist = dist_tmp;
	inter = inter_tmp;
	printf("######################\n");
	printf("after p1\n");
	printf("dist_tmp: %f\n", dist_tmp);
	coord_print(inter_tmp);
	

	inter_tmp = intersection(vect, vars->pc.pos, p2, &dist_tmp);
	printf("--------------------\n");
	printf("after p2\n");
	printf("dist_tmp: %f\n", dist_tmp);
	coord_print(inter_tmp);
	if (fabs((double) dist_tmp) < fabs((double) dist))
	{
		dist = dist_tmp;
		inter = inter_tmp;
	}

	inter_tmp = intersection(vect, vars->pc.pos, p3, &dist_tmp);
	printf("--------------------\n");
	printf("after p3\n");
	printf("dist_tmp: %f\n", dist_tmp);
	coord_print(inter_tmp);
	if (fabs((double) dist_tmp) < fabs((double) dist))
	{
		dist = dist_tmp;
		inter = inter_tmp;
	}

	inter_tmp = intersection(vect, vars->pc.pos, p4, &dist_tmp);
	printf("--------------------\n");
	printf("after p4\n");
	printf("dist_tmp: %f\n", dist_tmp);
	coord_print(inter_tmp);
	if (fabs((double) dist_tmp) < fabs((double) dist))
	{
		dist = dist_tmp;
		inter = inter_tmp;
	}

	inter_tmp = intersection(vect, vars->pc.pos, p_floor, &dist_tmp);
	printf("--------------------\n");
	printf("after pfloor\n");
	printf("dist_tmp: %f\n", dist_tmp);
	coord_print(inter_tmp);
	if (fabs((double) dist_tmp) < fabs((double) dist))
	{
		dist = dist_tmp;
		inter = inter_tmp;
	}

	inter_tmp = intersection(vect, vars->pc.pos, p_sky, &dist_tmp);
	printf("--------------------\n");
	printf("after psky\n");
	printf("dist_tmp: %f\n", dist_tmp);
	coord_print(inter_tmp);
	if (fabs((double) dist_tmp) < fabs((double) dist))
	{
		dist = dist_tmp;
		inter = inter_tmp;
	}
	printf("--------------------\n");
	printf("final dist: %f\n", dist);
	printf("final coord:\n");
	coord_print(inter);

	if (inter.z >= 1.0)
		trgb = vars->trgb_sky;
	else if (inter.z <= 0.0)
		trgb = vars->trgb_floor;
	else 
	{
		tile = vars->cubinfo->map[(int)inter.y - 1][(int)inter.x];
		if (tile == '1')
			{
				trgb = vars->trgb_wall;
				//coord_print(inter);
			}
		else
			trgb = vars->trgb_text;
	}
	return (trgb);
}