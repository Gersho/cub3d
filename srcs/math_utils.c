/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:09:47 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/07 15:10:08 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_coord	rotate_vect(t_coord vect, float angle)
{
	t_coord tmp;

	tmp.x = vect.x * cos(angle) + vect.y * (-sin(angle));
	tmp.y = vect.x * sin(angle) + vect.y * cos(angle);
	tmp.z = vect.z;

	return (tmp);
}

t_coord	intersection(t_coord vect, t_coord pos, t_plane plane, float *t)
{
	t_coord     res;
	
	if ((vect.x * plane.a + vect.y * plane.b + vect.z * plane.c) == 0)
	{
		res.x = -1;
		res.y = -1;
		res.z = -1;
		return (res);
	}
	*t = -(plane.a * pos.x + plane.b * pos.y + plane.c * pos.z + plane.d) /
	(vect.x * plane.a + vect.y * plane.b + vect.z * plane.c);
	res.x = pos.x + *t * vect.x;
	res.y = pos.y + *t * vect.y;
	res.z = pos.z + *t * vect.z;
	return (res);
}
