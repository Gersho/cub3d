/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precalculator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:49:47 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/13 16:23:22 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_coord	get_precalc_vect(t_vars *vars, int i, int j)
{
	t_coord	vect;

	vect.x = (i - vars->precalc.res0_2) * vars->precalc.r_h;
	vect.y = -1;
	vect.z = (vars->precalc.res1_2 - j) * vars->precalc.r_v;
	return (vect);
}

static void	vect_store(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i <= vars->cubinfo->res[0])
	{
		j = 0;
		while (j <= vars->cubinfo->res[1])
		{
			vars->precalc.vects[i][j] = get_precalc_vect(vars, i, j);
			j++;
		}
		i++;
	}
}

static void	vect_instantiate(t_vars *vars)
{
	int		i;
	t_coord	**ptr;

	ptr = malloc((vars->cubinfo->res[0] + 2) * sizeof(t_coord *));
	if (ptr == NULL)
		free_all_exit(vars);
	ptr[vars->cubinfo->res[0] + 1] = NULL;
	i = 0;
	while (i <= vars->cubinfo->res[0])
	{
		ptr[i] = malloc((vars->cubinfo->res[1] + 1) * sizeof(t_coord));
		if (ptr[i] == NULL)
			free_all_exit(vars);
		i++;
	}
	vars->precalc.vects = ptr;
}

void	vect_free(t_vars *vars)
{	
	int	i;

	if (vars->precalc.vects == NULL)
		return ;
	i = 0;
	while (vars->precalc.vects[i] != NULL)
	{
		free(vars->precalc.vects[i]);
		i++;
	}
	free(vars->precalc.vects);
}

void	vect_precalc(t_vars *vars)
{
	float	s;
	float	fov;
	float	s_v;

	fov = 1.0471;
	s = 2 * tan(fov / 2);
	s_v = s * vars->cubinfo->res[1] / vars->cubinfo->res[0];
	vars->precalc.r_h = (s / vars->cubinfo->res[0]);
	vars->precalc.r_v = (s_v / vars->cubinfo->res[1]);
	vars->precalc.res0_2 = (vars->cubinfo->res[0] / 2);
	vars->precalc.res1_2 = (vars->cubinfo->res[1] / 2);
	vect_instantiate(vars);
	vect_store(vars);
}
