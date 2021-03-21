/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:42:22 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/21 11:03:24 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


// t_plane get_closest_plane(t_vars *vars, t_vect vect)

t_trgb pick_pixel_color(t_vars *vars, t_coord vect)
{
	int i;
	int temp_test;
	t_plane closest_plane;
	float	dist;
	float   dist_tmp;
	t_coord inter;
    t_coord inter_tmp;
	int a;
	int b;
	char tile;

	// printf("tested vect\n");
	// coord_print(vect);
	dist = 999999;
	i = 0;
	// color_print(vars->trgb_wall);
	// printf("trgb:%d\n", vars->trgb_wall.trgb);
	//printf("angle: %f\n", vars->pc.angle);
	while (!is_lastplane(vars->planes[i]))
	{
		//printf("-------\n");
		inter_tmp = intersection(vect, vars->pc.pos, vars->planes[i], &dist_tmp);
		// printf("pc coords\n");
		// coord_print(vars->pc.pos);
		// printf("testing plane %d\n", i);
		// printf("dist_tmp: %f\n", dist_tmp);
		// printf("new inter\n");
		// coord_print(inter_tmp);
		if (dist_tmp > 0 && dist_tmp < dist)
		{
			//printf("new inter\n");
			// printf("inter coords for a-b\n");
			// printf("inter.x: %f\n", inter.x);
			// printf("inter.y: %f\n", inter.y);
			// printf("inter.z: %f\n", inter.z);
			a = (int)inter_tmp.y;
			b = (int)inter_tmp.x;

			if (vars->planes[i].b == 1)
			{
				if (vect.y < 0)
				{
					a--;
				}
			}
			// if (vect.y > 0)
			// {
			// 	a--;
			// }
			if (vars->planes[i].a == 1)
			{			
				if (vect.x < 0)
				{
					b--;
				}
			}
			// if (vect.x > 0)
			// {
			// 	b++;
			// }
			// if (a < 0 || a > vars->cubinfo->map_size[0] - 1 || b < 0 || b > vars->cubinfo->map_size[1] -1)
			// {
			// 	i++;
			// 	continue;
			// }
			//printf("a: %d, b: %d\n", a, b);
			if (a <= 0)
				a = 0;
			if (a >= vars->cubinfo->map_size[0])
				a = vars->cubinfo->map_size[0] - 1;
			if (b <= 0)
				b = 0;
			if (b >= vars->cubinfo->map_size[1])
				b = vars->cubinfo->map_size[1] - 1;

			//TODO: modif a-b selon orientation vect
			tile = vars->cubinfo->map[a][b];
			//printf("tile: %c\n", tile);
			if (tile == '1' || vars->planes[i].c == 1)
			{
				//printf("is new closest plane\n");
				inter = inter_tmp;
				dist = dist_tmp;
				closest_plane = vars->planes[i];
				temp_test = i;
			}
		}
		i++;
	}
	// printf("closest plane: %d\n", temp_test);
	// printf("plane{%f, %f, %f, %f}\n",  closest_plane.a, closest_plane.b, closest_plane.c, closest_plane.d);	
	// printf("coord de l'inter\n");
	// coord_print(inter);
	if (closest_plane.c == 1)
	{
		if (closest_plane.d == 0)
			return (vars->trgb_floor);
		return (vars->trgb_sky);
	}

	if (closest_plane.b == 1)
	{
		//en fonction du vect ?

		return (vars->trgb_wall_n);
	}

	if (closest_plane.a == 1)
	{
		//en fonction du vect ?
		return (vars->trgb_wall_w);
	}

	return (vars->trgb_text);
	//return (vars->trgb_wall);
}

/*
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

*/