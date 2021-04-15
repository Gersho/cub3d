/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_inter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:08:29 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/15 15:07:37 by kzennoun         ###   ########lyon.fr   */
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

void	sprites_inter(t_vars *v, t_coord vect, t_closest *closest)
{
	int			i;
	t_tmpkit	tmp;
	double		pscale;

	i = -1;
	while (!is_lastplane(v->sprites[++i].plane))
	{
		tmp.inter = inter(vect, v->pc.pos, v->sprites[i].plane, &tmp.dist);
		if (tmp.dist > 0 && tmp.dist < closest->dist)
		{
			tmp.a = (int)tmp.inter.y;
			tmp.b = (int)tmp.inter.x;
			protect_ab(v, &tmp.a, &tmp.b, &tmp.tile);
			pscale = get_pscale(v, vect, tmp.inter, i);
			tmp.color = get_trgb_from_xpm_sprite(&v->sprite_xpm,
					tmp.inter, pscale);
			if (tmp.tile == '2' && tmp.color.trgb != 0)
			{
				closest->inter = tmp.inter;
				closest->dist = tmp.dist;
				closest->closest_plane = v->sprites[i].plane;
				closest->saved_color = tmp.color;
			}
		}
	}
}
