/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:42:22 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/23 15:39:30 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
		if (vect.y < 0)
			return (vars->trgb_wall_n);
		return (vars->trgb_wall_s);
	}

	if (closest_plane.a == 1)
	{
		//en fonction du vect ?
		if (vect.x < 0)
			return (vars->trgb_wall_w);
		return (vars->trgb_wall_e);
	}

	return (vars->trgb_text);
	//return (vars->trgb_wall);
}
