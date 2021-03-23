/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precalculator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:49:47 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/23 12:58:56 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	vect_precalc(t_vars *vars)
{
	(void)vars;

	float	s;
	float	fov;
	float 	s_v;
		
	fov = 1.0471;
	s = 2 * tan(fov / 2);
	s_v = s * vars->cubinfo->res[1] / vars->cubinfo->res[0];
}