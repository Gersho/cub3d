/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:42:22 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/15 15:42:51 by kzennoun         ###   ########lyon.fr   */
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
	p2.d = -7;
	//p2 = (t_plane){0, 1, 0, -7};

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

// coord_print(vars->pc.pos);
	//printf("%f %f %f\n");
	inter_tmp = intersection(vect, vars->pc.pos, p1, &dist_tmp);
	dist = dist_tmp;
	inter = inter_tmp;
	if (dist > 0 && inter.z >= 0 && inter.z < 1)
		return (vars->trgb_wall_e);
	// printf("######################\n");
	// printf("after p1\n");
	// printf("dist_tmp: %f\n", dist_tmp);
	// coord_print(inter_tmp);
	

	// inter_tmp = intersection(vect, vars->pc.pos, p2, &dist_tmp);
	// if (fabs((double) dist_tmp) < fabs((double) dist))
	// {
	// 	dist = dist_tmp;
	// 	inter = inter_tmp;
	// }
	// printf("--------------------\n");
	// printf("after p2\n");
	// printf("dist_tmp: %f\n", dist_tmp);
	// coord_print(inter_tmp);

	inter_tmp = intersection(vect, vars->pc.pos, p3, &dist_tmp);
	// if (fabs((double) dist_tmp) < fabs((double) dist))
	// {
		dist = dist_tmp;
		inter = inter_tmp;
	if (dist > 0 && inter.z >= 0 && inter.z < 1)
		return (vars->trgb_wall_e);
	inter_tmp = intersection(vect, vars->pc.pos, p2, &dist_tmp);
		dist = dist_tmp;
		inter = inter_tmp;
	if (dist > 0 && inter.z >= 0 && inter.z < 1)
		return (vars->trgb_wall_e);
	inter_tmp = intersection(vect, vars->pc.pos, p4, &dist_tmp);
		dist = dist_tmp;
		inter = inter_tmp;
	if (dist > 0 && inter.z >= 0 && inter.z < 1)
		return (vars->trgb_wall_e);
	return ((t_trgb){0});
	// }
	// printf("--------------------\n");
	// printf("after p3\n");
	// printf("dist_tmp: %f\n", dist_tmp);
	// coord_print(inter_tmp);

	// inter_tmp = intersection(vect, vars->pc.pos, p4, &dist_tmp);
	// if (fabs((double) dist_tmp) < fabs((double) dist))
	// {
	// 	dist = dist_tmp;
	// 	inter = inter_tmp;
	// }
	// printf("--------------------\n");
	// printf("after p4\n");
	// printf("dist_tmp: %f\n", dist_tmp);
	// coord_print(inter_tmp);

	// inter_tmp = intersection(vect, vars->pc.pos, p_floor, &dist_tmp);
	// if (fabs((double) dist_tmp) < fabs((double) dist))
	// {
	// 	dist = dist_tmp;
	// 	inter = inter_tmp;
	// }
	// printf("--------------------\n");
	// printf("after pfloor\n");
	// printf("dist_tmp: %f\n", dist_tmp);
	// coord_print(inter_tmp);

	// inter_tmp = intersection(vect, vars->pc.pos, p_sky, &dist_tmp);
	// if (fabs((double) dist_tmp) < fabs((double) dist))
	// {
	// 	dist = dist_tmp;
	// 	inter = inter_tmp;
	// }
	// printf("--------------------\n");
	// printf("after psky\n");
	// printf("dist_tmp: %f\n", dist_tmp);
	// coord_print(inter_tmp);

	// printf("--------------------\n");
	// printf("final dist: %f\n", dist);
	// printf("final coord:\n");
	// coord_print(inter);

	if (inter.z >= 1.0)
		trgb = vars->trgb_sky;
	else if (inter.z <= 0.0)
		trgb = vars->trgb_floor;
	else 
	{
		// if ((int)inter.y <=  1 || (int)inter.x <= 1)
		// 	printf("(int)inter.x-y :%d, %d\n",(int)inter.x, (int)inter.y);
		//printf("(int)inter.x :%d\n", ((int)inter.x));
		
		// if ((int)inter.y > vars->cubinfo->map_size[0])
		// {
		// 	inter.y = inter.y - 1.0;
		// }
		// if ((int)inter.y <= 0)
		// {
		// 	inter.y = inter.y + 1.0;
		// }
		
		// if ((int)inter.x > vars->cubinfo->map_size[1])
		// {
		// 	inter.x = inter.x - 1.0;
		// }
		// if ((int)inter.x <= 0)
		// {
		// 	inter.x = inter.x + 1.0;
		// }

		a = (int)inter.y;
		b = (int)inter.x;

		// if (a <= 0 || a >= vars->cubinfo->map_size[0] || b < 0 || b >= vars->cubinfo->map_size[1])
		// {
		// 	trgb = vars->trgb_text;
		// 	return (trgb);
		// }



		if (a <= 0)
			a = 1;
		if (a >= vars->cubinfo->map_size[0])
			a = vars->cubinfo->map_size[0] - 1;
		if (b <= 0)
			b = 1;
		if (b >= vars->cubinfo->map_size[1])
			b = vars->cubinfo->map_size[1] - 1;


		tile = vars->cubinfo->map[a - 1][b - 1];
		// printf("tile: %c\n", tile);
		// printf("a-b :%d, %d\n", a, b);
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