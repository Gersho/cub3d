/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_inter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:08:29 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/15 13:59:25 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static double	get_pscale(t_vars *vars, t_coord vect, t_coord inter, int i)
{
	double	v_norm;
	t_coord	vect_tmp;
	t_coord	vect_v1;
	t_coord	vect_v2;

	vect_tmp.x = inter.x - vars->sprites[i].pos.x;
	vect_tmp.y = inter.y - vars->sprites[i].pos.y;
	vect_tmp.z = 0;
	vect_v1.x = vect.y;
	vect_v1.y = -vect.x;
	vect_v1.z = 0;
	v_norm = sqrt(pow((double) vect_v1.x, 2) + pow((double) vect_v1.y, 2)
			+ pow((double) vect_v1.z, 2));
	vect_v2.x = vect_v1.x / v_norm;
	vect_v2.y = vect_v1.y / v_norm;
	vect_v2.z = vect_v1.z / v_norm;
	return ((vect_tmp.x * vect_v2.x) + (vect_tmp.y * vect_v2.y)
		+ (vect_tmp.z * vect_v2.z) + 0.5);
}

void	sprites_inter(t_vars *vars, t_coord vect, t_closest *closest)
{
	int		i;
	t_coord	inter_tmp;
	float	dist_tmp;
	int		a;
	int		b;
	char	tile;
	double	pscale;
	t_trgb	color_temp;

	i = 0;
	while(!is_lastplane(vars->sprites[i].plane))
	{
		inter_tmp = intersection(vect, vars->pc.pos, vars->sprites[i].plane, &dist_tmp);
		if (dist_tmp > 0 && dist_tmp < closest->dist)
		{
			a = (int)inter_tmp.y;
			b = (int)inter_tmp.x;
			protect_ab(vars, &a, &b, &tile);
			pscale = get_pscale(vars, vect, inter_tmp, i);
			if(pscale > 1 || pscale < 0)
			{
				i++;
				continue;
			}
			color_temp = get_trgb_from_xpm_sprite(&vars->sprite_xpm, inter_tmp, pscale);
			if (color_temp.trgb == -16777216 || color_temp.trgb == 0 || isnan(color_temp.trgb))
			{
				i++;
				continue;
			}
			if (tile == '2')
			{
					closest->inter = inter_tmp;
					closest->dist = dist_tmp;
					closest->closest_plane = vars->sprites[i].plane;
					closest->saved_color = color_temp;
					i++;
					continue;
			}
		}
		i++;
	}
}