/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:52:56 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/25 14:52:56 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

 #include "cube.h"

int	is_lastsprite(t_sprite sprite)
{
	if (sprite.pos.x == -255 && sprite.pos.y == -255 && sprite.pos.z == -255)
		return (1);
	return (0);
}

// sprites
t_plane	create_sprite_plane(t_vars *vars, int i)
{
	//t_coord	tmp;
	t_plane	plane;
	double	v_norm;

	v_norm = sqrt(pow((double) vars->pc.pos.x, 2) + pow((double) vars->pc.pos.y, 2) + pow((double) vars->pc.pos.z, 2));
	plane.a = vars->pc.pos.x / v_norm;
	plane.b = vars->pc.pos.y / v_norm;
	plane.c = vars->pc.pos.z / v_norm;
	plane.d = - (plane.a * vars->sprites[i].pos.x) - (plane.b * vars->sprites[i].pos.y) - (plane.c * vars->sprites[i].pos.z);

	return (plane);
	 //ax + by + cz + d = 0
	 // n = v / |v|
	 // |v| = squareroot(x^2 + y^2 + z^2)
	 // v = vect pc (t_coord pc.view ?)
}