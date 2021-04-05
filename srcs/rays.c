/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:42:22 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/05 16:26:36 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


t_trgb pick_pixel_color(t_vars *vars, t_coord vect)
{
	int i;
	t_plane closest_plane;
	float	dist;
	float   dist_tmp;
	t_coord inter;
    t_coord inter_tmp;
	int a;
	int b;
	char tile;
	int	reverse;
	t_trgb	color_temp;
	t_coord	p_tmp;
	t_coord vect_tmp;
	t_coord vect_v1;
	t_coord vect_v2;
	double v_norm;
	double pscale;

	dist = 999999;

	i = 0;
	while(!is_lastplane(vars->sprites[i].plane))
	{
		inter_tmp = intersection(vect, vars->pc.pos, vars->sprites[i].plane, &dist_tmp);
		if (dist_tmp > 0 && dist_tmp < dist)
		{
			a = (int)inter_tmp.y;
			b = (int)inter_tmp.x;

			if (a <= 0)
				a = 0;
			if (a >= vars->cubinfo->map_size[0])
				a = vars->cubinfo->map_size[0] - 1;
			if (b <= 0)
				b = 0;
			if (b >= vars->cubinfo->map_size[1])
				b = vars->cubinfo->map_size[1] - 1;
			tile = vars->cubinfo->map[a][b];

			// //if (fabsf(vect.x) < 0.75 && fabsf(vect.y) < 0.75)
			// if (   fabsf(fabsf(vect.x) - fabsf(vect.y))  < 0.7)
			// {
			// 	if (inter_tmp.x > vars->sprites[i].pos.x + 0.4 || inter_tmp.x < vars->sprites[i].pos.x -0.4 || inter_tmp.y > vars->sprites[i].pos.y + 0.4 || inter_tmp.y < vars->sprites[i].pos.y - 0.4)
			// 	{
			// 		printf("test\n");
			// 		i++;
			// 		continue;
			// 	}

			// }

			/* test sprite diag */

			// P coord
			p_tmp.x = vars->sprites[i].pos.x;
			p_tmp.y = vars->sprites[i].pos.y;
			p_tmp.z = inter_tmp.z;

			// PI vect (u)
			vect_tmp.x = inter_tmp.x - p_tmp.x;
			vect_tmp.y = inter_tmp.y - p_tmp.y;
			vect_tmp.z = inter_tmp.z - p_tmp.z;

			// V' vect
			vect_v1.x = vect.y;
			vect_v1.y = -vect.x;
			vect_v1.z = 0;
			
			// V2 vect
			v_norm = sqrt(pow((double) vect_v1.x, 2) + pow((double) vect_v1.y, 2) + pow((double) vect_v1.z, 2));
			vect_v2.x = vect_v1.x / v_norm;
			vect_v2.y = vect_v1.y / v_norm;
			vect_v2.z = vect_v1.z / v_norm;

			// produit scalaire u.v2
			pscale = (vect_tmp.x * vect_v2.x) + (vect_tmp.y * vect_v2.y) + (vect_tmp.z * vect_v2.z) + 0.5;
			if(pscale > 1 || pscale < 0)
			{
				i++;
				continue;
			}


			/* fin test sprite diag */

			//changer a/b pour faire avec les coords

			// if (a<= 0 || a >= vars->cubinfo->map_size[0] || b <= 0 || b >= vars->cubinfo->map_size[1])
			// 	tile = '*';
			// else 
				// tile = vars->cubinfo->map[a][b];


			 color_temp = get_trgb_from_xpm_sprite(&vars->sprite_xpm, inter_tmp, vect);
			// if (color_temp.trgb == -16777216 || color_temp.trgb == 0 || isnan(color_temp.trgb))
			// {
			// 	i++;
			// 	continue;
			// }
			// else 
			
			if (tile == '2')
			{
					inter = inter_tmp;
					dist = dist_tmp;
					closest_plane = vars->sprites[i].plane;
					i++;
					continue;
			}



			//color_print(color_temp);
			//if (tile == '2' && color_temp.r != 0 && color_temp.g != 0 && color_temp.b != 0)
			//if (tile == '2' /*&& color_temp.t == 0*/)

			//if (tile == '2' /*&& color_temp.trgb != 0 *//*&& (color_temp.r != 0 || color_temp.g != 0 || color_temp.b != 0)*/)
			// if (tile == '2'  /* && !isnan(color_temp.trgb)*/)
			// {
			// 		//color_print(color_temp);
			// 		//printf("%d\n", color_temp.trgb);
			// 		//printf("trgb.t: %d\n", color_temp.t);
			// 		//printf("is new closest plane\n");
			// 		inter = inter_tmp;
			// 		dist = dist_tmp;
			// 		closest_plane = vars->sprites[i].plane;
			// 		//temp_test = i;
			// 		//return color_temp;
			// }
		}
		i++;
	}


//change i depending on pos (& i--  || i < 0)

	i = (int)vars->pc.pos.x;
	reverse = 0;
	if (vect.x < 0)
		reverse = 1;
	else
		i++;

	//i = 1;
		// 		printf("pc coords\n");
		// coord_print(vars->pc.pos);
	// printf("planes_x   i: %d, reverse: %d\n", i, reverse);
	while (!is_lastplane(vars->planes_x[i]))
	{
		//  printf("-------\n");
		inter_tmp = intersection(vect, vars->pc.pos, vars->planes_x[i], &dist_tmp);
		// printf("testing plane %d\n", i);
		// printf("dist_tmp: %f\n", dist_tmp);
		// printf("new inter\n");
		// coord_print(inter_tmp);
		if (dist_tmp > 0 && dist_tmp < dist)
		{
			 a = (int)inter_tmp.y;
			// b = (int)inter_tmp.x;

			//a = (int)roundf(inter_tmp.y);
			b = (int)roundf(inter_tmp.x);

			// printf("inter tmp x: %f\n", inter_tmp.x);
			// printf("(int) inter tmp x: %d\n", (int)inter_tmp.x);
			// printf("ROUNDF inter tmp x: %f\n", roundf(inter_tmp.x));
			// printf("(int)ROUNDF inter tmp x: %d\n", (int)roundf(inter_tmp.x));
			// printf("inter tmp x .10: %.10f\n", inter_tmp.x);
			// printf("ROUNDF inter tmp x .10: %.10f\n", roundf(inter_tmp.x));

			// printf("BEFORE a: %d, b:%d\n", a, b);

			
			// a = round(inter_tmp.y);
			// b = round(inter_tmp.x);			
			if (vect.x < 0)
			{
				b--;
			}
			// 		printf("new inter\n");
			// printf("inter_tmp coords for a-b\n");
			// printf("inter_tmp.x: %f\n", inter_tmp.x);
			// printf("inter_tmp.y: %f\n", inter_tmp.y);
			// printf("inter_tmp.z: %f\n", inter_tmp.z);
			// if (a < 0 || (a > vars->cubinfo->map_size[1] - 1) || b < 0 || (b > vars->cubinfo->map_size[0] - 1))
			// 	tile = '*';
			// else 
			// 	tile = vars->cubinfo->map[a][b];

			if (a <= 0)
				a = 0;
			if (a >= vars->cubinfo->map_size[0])
				a = vars->cubinfo->map_size[0] - 1;
			if (b <= 0)
				b = 0;
			if (b >= vars->cubinfo->map_size[1])
				b = vars->cubinfo->map_size[1] - 1;
			tile = vars->cubinfo->map[a][b];
			// printf("AFTER a: %d, b:%d\n", a, b);
			// printf("tile: %c\n", tile);
			if (tile == '1')
			{
				// printf("is new closest plane\n");
				inter = inter_tmp;
				dist = dist_tmp;
				closest_plane = vars->planes_x[i];
			}
		}
		if(reverse == 0)
			i++;
		else
			i--;
		// i++;
	}


	// printf("X done, starting Y;\n");
	i = (int)vars->pc.pos.y;
	reverse = 0;
	if (vect.y < 0)
		reverse = 1;
	else
		i++;
//change i depending on pos (& i--  || i < 0)
	//i = 1;
	// printf("planes_y   i: %d, reverse: %d\n", i, reverse);
	while (!is_lastplane(vars->planes_y[i]))
	{
		// printf("-------\n");

		inter_tmp = intersection(vect, vars->pc.pos, vars->planes_y[i], &dist_tmp);
		// printf("testing plane %d\n", i);
		// printf("dist_tmp: %f\n", dist_tmp);
		// printf("new inter\n");
		// coord_print(inter_tmp);
		if (dist_tmp > 0 && dist_tmp < dist)
		{
			// a = (int)inter_tmp.y;
			b = (int)inter_tmp.x;

			a = (int)roundf(inter_tmp.y);
			//b = (int)roundf(inter_tmp.x);
			
			// printf("inter tmp y: %f\n", inter_tmp.y);
			// printf("(int) inter tmp y: %d\n", (int)inter_tmp.y);
			// printf("ROUNDF inter tmp y: %f\n", roundf(inter_tmp.y));
			// printf("(int)ROUNDF inter tmp y: %d\n", (int)roundf(inter_tmp.y));
			// printf("inter tmp y .10: %.10f\n", inter_tmp.y);
			// printf("ROUNDF inter tmp y .10: %.10f\n", roundf(inter_tmp.y));

			
			// printf("BEFORE a: %d, b:%d\n", a, b);
			// 	a = round(inter_tmp.y);
			// b = round(inter_tmp.x);		
			if (vect.y < 0)
			{
				a--;
			}
			// 	printf("new inter\n");
			// printf("inter_tmp coords for a-b\n");
			// printf("inter_tmp.x: %f\n", inter_tmp.x);
			// printf("inter_tmp.y: %f\n", inter_tmp.y);
			// printf("inter_tmp.z: %f\n", inter_tmp.z);
			// if (a < 0 || a > vars->cubinfo->map_size[1] - 1|| b < 0 || b > vars->cubinfo->map_size[0] -1)
			// 	tile = '*';
			// else 
			// 	tile = vars->cubinfo->map[a][b];

			if (a <= 0)
				a = 0;
			if (a >= vars->cubinfo->map_size[0])
				a = vars->cubinfo->map_size[0] - 1;
			if (b <= 0)
				b = 0;
			if (b >= vars->cubinfo->map_size[1])
				b = vars->cubinfo->map_size[1] - 1;
			tile = vars->cubinfo->map[a][b];
			// printf("AFTER a: %d, b:%d\n", a, b);
			// printf("tile: %c\n", tile);
			if (tile == '1' || vars->planes_y[i].c == 1)
			{
				// printf("is new closest plane\n");
				inter = inter_tmp;
				dist = dist_tmp;
				closest_plane = vars->planes_y[i];
			}
		}
		if(reverse == 0)
			i++;
		else
			i--;
		//i++;
	}

//sky/floor
inter_tmp = intersection(vect, vars->pc.pos, vars->plane_sky, &dist_tmp);
if (dist_tmp > 0 && dist_tmp < dist)
{
	inter = inter_tmp;
	dist = dist_tmp;
	closest_plane = vars->plane_sky;
}
inter_tmp = intersection(vect, vars->pc.pos, vars->plane_floor, &dist_tmp);
if (dist_tmp > 0 && dist_tmp < dist)
{
	inter = inter_tmp;
	dist = dist_tmp;
	closest_plane = vars->plane_floor;
}

// printf("closest plane{%f, %f, %f, %f}\n",  closest_plane.a, closest_plane.b, closest_plane.c, closest_plane.d);

	if (closest_plane.b == 1)
	{
		if (vect.y < 0)
			return get_trgb_from_xpm_n(&vars->n_xpm, inter);
		return get_trgb_from_xpm_s(&vars->s_xpm, inter);
	}

	if (closest_plane.a == 1)
	{
		if (vect.x < 0)
			return get_trgb_from_xpm_w(&vars->w_xpm, inter);
		return get_trgb_from_xpm_e(&vars->e_xpm, inter);
	}
	if (closest_plane.c == 1)
	{
		if (closest_plane.d == 0)
			return (vars->trgb_floor);
		return (vars->trgb_sky);
	}


	return get_trgb_from_xpm_sprite(&vars->sprite_xpm, inter, vect);
	return (vars->trgb_text);
}



/*
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
	//int temp_trgb;

	// printf("tested vect\n");
	// coord_print(vect);
	dist = 999999;
	i = 0;
	// color_print(vars->trgb_wall);
	// printf("trgb:%d\n", vars->trgb_wall.trgb);
	//printf("angle: %f\n", vars->pc.angle);

	while(!is_lastplane(vars->sprites[i].plane))
	{
		inter_tmp = intersection(vect, vars->pc.pos, vars->sprites[i].plane, &dist_tmp);
		if (dist_tmp > 0 && dist_tmp < dist)
		{
			a = (int)inter_tmp.y;
			b = (int)inter_tmp.x;
			// if (a <= 0)
			// 	a = 0;
			// if (a >= vars->cubinfo->map_size[0])
			// 	a = vars->cubinfo->map_size[0] - 1;
			// if (b <= 0)
			// 	b = 0;
			// if (b >= vars->cubinfo->map_size[1])
			// 	b = vars->cubinfo->map_size[1] - 1;

			if (a<= 0 || a >= vars->cubinfo->map_size[0] || b <= 0 || b >= vars->cubinfo->map_size[1])
				tile = '*';
			else 
				tile = vars->cubinfo->map[a][b];

			if (tile == '2')
				{
					//printf("is new closest plane\n");
					inter = inter_tmp;
					dist = dist_tmp;
					closest_plane = vars->sprites[i].plane;
					//temp_test = i;
			}
	}
		i++;
	}
	// inter_tmp = intersection(vect, vars->pc.pos, vars->sprites.plane, &dist_tmp);
	// if (dist_tmp > 0 && dist_tmp < dist)
	// {
	// 	a = (int)inter_tmp.y;
	// 	b = (int)inter_tmp.x;
	// 	if (a <= 0)
	// 		a = 0;
	// 	if (a >= vars->cubinfo->map_size[0])
	// 		a = vars->cubinfo->map_size[0] - 1;
	// 	if (b <= 0)
	// 		b = 0;
	// 	if (b >= vars->cubinfo->map_size[1])
	// 		b = vars->cubinfo->map_size[1] - 1;

	// 	tile = vars->cubinfo->map[a][b];

	// 	if (tile == '2')
	// 		{
	// 			//printf("is new closest plane\n");
	// 			inter = inter_tmp;
	// 			dist = dist_tmp;
	// 			closest_plane = vars->sprites.plane;
	// 			//temp_test = i;
	// 		}
	// }


	i = 0;
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
		//walls N/S (old)
		// if (vect.y < 0)
		// 	return (vars->trgb_wall_n);
		// return (vars->trgb_wall_s);
		//walls N/S (new)
		if (vect.y < 0)
		{
			return get_trgb_from_xpm_n(&vars->n_xpm, inter);
		}
		return get_trgb_from_xpm_s(&vars->s_xpm, inter);
	}

	if (closest_plane.a == 1)
	{
		//walls E/W (old)
		// if (vect.x < 0)
		// 	return (vars->trgb_wall_w);
		// return (vars->trgb_wall_e);
		//walls E/W (new)
		if (vect.x < 0)
			return get_trgb_from_xpm_w(&vars->w_xpm, inter);
		return get_trgb_from_xpm_e(&vars->e_xpm, inter);
	}


	return get_trgb_from_xpm_n(&vars->sprite_xpm, inter);
	return (vars->trgb_text);
	//return (vars->trgb_wall);
}
*/