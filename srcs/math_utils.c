/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:09:47 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/13 16:25:04 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_coord	rotate_vect(t_coord vect, float angle)
{
	t_coord	tmp;

	tmp.x = vect.x * cos(angle) + vect.y * (-sin(angle));
	tmp.y = vect.x * sin(angle) + vect.y * cos(angle);
	tmp.z = vect.z;
	return (tmp);
}

t_coord	intersection(t_coord vect, t_coord pos, t_plane plane, float *t)
{
	t_coord	res;

	if ((vect.x * plane.a + vect.y * plane.b + vect.z * plane.c) == 0)
	{
		res.x = -1;
		res.y = -1;
		res.z = -1;
		return (res);
	}
	*t = -(plane.a * pos.x + plane.b * pos.y + plane.c * pos.z + plane.d) / \
		(vect.x * plane.a + vect.y * plane.b + vect.z * plane.c);
	res.x = pos.x + *t * vect.x;
	res.y = pos.y + *t * vect.y;
	res.z = pos.z + *t * vect.z;
	return (res);
}

t_coord	get_vector(t_vars *vars, int i, int j)
{
	t_coord	vect;
	t_coord	tmp;

	vect = vars->precalc.vects[i][j];
//rot x (HEAD UP/DOWN)
	// //tmp.x = vect.x;
	// tmp.y = vect.y * (cos(vars->pc.head_tilt)) + (-vect.z * sin(vars->pc.head_tilt));
	// tmp.z = vect.y * sin(vars->pc.head_tilt) +  vect.z * cos(vars->pc.head_tilt);
	// //vect.x = tmp.x;
	// vect.y = tmp.y;
	// //vect.z = tmp.z;
//rot z (HEAD LEFT/RIGHT)
	tmp.x = vect.x * cos(vars->pc.angle) + vect.y * (-sin(vars->pc.angle));
	tmp.y = vect.x * sin(vars->pc.angle) + vect.y * cos(vars->pc.angle);
	tmp.z = vect.z;
	return (tmp);
}
