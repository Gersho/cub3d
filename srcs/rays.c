/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:42:22 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/15 12:38:25 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	protect_ab(t_vars *vars, int *a, int *b, char *tile)
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
	double saved_pscale;
	t_trgb saved_color;

	dist = 999999;
	i = 0;
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
			// tile = vars->cubinfo->map[a][b];
			protect_ab(vars, &a, &b, &tile);

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

			color_temp = get_trgb_from_xpm_sprite(&vars->sprite_xpm, inter_tmp, pscale);

			if (color_temp.trgb == -16777216 || color_temp.trgb == 0 || isnan(color_temp.trgb))
			{
				i++;
				continue;
			}
		
			if (tile == '2')
			{
					inter = inter_tmp;
					dist = dist_tmp;
					closest_plane = vars->sprites[i].plane;
					saved_pscale = pscale;
					saved_color = color_temp;
					i++;
					continue;
			}
		}
		i++;
	}


	i = (int)vars->pc.pos.x;
	reverse = 0;
	if (vect.x < 0)
		reverse = 1;
	else
		i++;

	while (!is_lastplane(vars->planes_x[i]))
	{
		inter_tmp = intersection(vect, vars->pc.pos, vars->planes_x[i], &dist_tmp);
		if (dist_tmp > 0 && dist_tmp < dist)
		{
			a = (int)inter_tmp.y;
			b = (int)roundf(inter_tmp.x);
		
			if (vect.x < 0)
			{
				b--;
			}
			// if (a <= 0)
			// 	a = 0;
			// if (a >= vars->cubinfo->map_size[0])
			// 	a = vars->cubinfo->map_size[0] - 1;
			// if (b <= 0)
			// 	b = 0;
			// if (b >= vars->cubinfo->map_size[1])
			// 	b = vars->cubinfo->map_size[1] - 1;
			// tile = vars->cubinfo->map[a][b];
			protect_ab(vars, &a, &b, &tile);
			if (tile == '1')
			{
				inter = inter_tmp;
				dist = dist_tmp;
				closest_plane = vars->planes_x[i];
			}
		}
		if(reverse == 0)
			i++;
		else
			i--;
	}

	i = (int)vars->pc.pos.y;
	reverse = 0;
	if (vect.y < 0)
		reverse = 1;
	else
		i++;
	while (!is_lastplane(vars->planes_y[i]))
	{
		inter_tmp = intersection(vect, vars->pc.pos, vars->planes_y[i], &dist_tmp);
		if (dist_tmp > 0 && dist_tmp < dist)
		{
			b = (int)inter_tmp.x;
			a = (int)roundf(inter_tmp.y);	
			if (vect.y < 0)
			{
				a--;
			}
			// if (a <= 0)
			// 	a = 0;
			// if (a >= vars->cubinfo->map_size[0])
			// 	a = vars->cubinfo->map_size[0] - 1;
			// if (b <= 0)
			// 	b = 0;
			// if (b >= vars->cubinfo->map_size[1])
			// 	b = vars->cubinfo->map_size[1] - 1;
			// tile = vars->cubinfo->map[a][b];
			protect_ab(vars, &a, &b, &tile);
			if (tile == '1' || vars->planes_y[i].c == 1)
			{
				inter = inter_tmp;
				dist = dist_tmp;
				closest_plane = vars->planes_y[i];
			}
		}
		if(reverse == 0)
			i++;
		else
			i--;
	}
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
	return saved_color;
}
