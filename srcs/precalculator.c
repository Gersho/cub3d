/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precalculator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:49:47 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/08 16:13:30 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"



static t_coord	get_precalc_vect(t_vars *vars, int i, int j)
{
	t_coord	vect;

	vect.x = (i - vars->precalc.res0_2) * vars->precalc.r_h;
	vect.y = -1;
	vect.z = (vars->precalc.res1_2 - j) * vars->precalc.r_v;
	//vect.z = (vars->cubinfo->res[1] * 0.5 - j) * vars->precalc.r_v;
	return (vect);
}

static void	vect_store(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	cubinfo_print(vars->cubinfo);
	while (i <= vars->cubinfo->res[0])
	{
		j = 0;
		while(j <= vars->cubinfo->res[1])
		{
			vars->precalc.vects[i][j] = get_precalc_vect(vars, i, j);
			// printf("-----------------\n");
			// printf("i:%d , j:%d\n", i, j);
			// coord_print(vars->precalc.vects[i][j]);

			j++;
		}
		i++;
	}
	//printf("still alive\n");
}


static void	vect_instantiate(t_vars *vars)
{
	int i;
	t_coord **ptr;

	ptr = malloc((vars->cubinfo->res[0]+ 2) * sizeof(t_coord*));
	if (ptr == NULL)
	{
		//clean exit
	}
	ptr[vars->cubinfo->res[0] + 1] = NULL;
	i = 0;
	while (i <= vars->cubinfo->res[0])
	{
		ptr[i] = malloc( (vars->cubinfo->res[1] + 1) * sizeof(t_coord));
		if (ptr[i] == NULL)
		{
			//clean exit with 2d clear all
		}
		i++;
	}
	vars->precalc.vects = ptr;
}

void	vect_precalc(t_vars *vars)
{
	float	s;
	float	fov;
	float 	s_v;
		
	fov = 1.0471;
	s = 2 * tan(fov / 2);
	s_v = s * vars->cubinfo->res[1] / vars->cubinfo->res[0];
	vars->precalc.r_h = (s / vars->cubinfo->res[0]);
	//vars->precalc.r_v = (s_v / vars->cubinfo->res[1]);
	vars->precalc.r_v = (2 * tan(fov * vars->cubinfo->res[1] / (vars->cubinfo->res[0] * 2)) / vars->cubinfo->res[1]);
	//2 * tan(FOV * H / (W * 2)) / H
	vars->precalc.res0_2 = (vars->cubinfo->res[0] / 2);
	vars->precalc.res1_2 = (vars->cubinfo->res[1] / 2);

	vect_instantiate(vars);
	vect_store(vars);

}
