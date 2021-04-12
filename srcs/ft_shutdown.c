/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shutdown.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:54:20 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/12 13:21:20 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	error_exit(int err)
{
	perror("Error");
	exit(err);
}

void	freestructs_exit(t_cubinfo *cubinfo, int err)
{
	if (cubinfo)
		cubinfo_free(cubinfo);
	error_exit(err);
}

void	freestructs_msg(t_cubinfo *cubinfo, char *str)
{
	if (cubinfo)
		cubinfo_free(cubinfo);
	write(1, "Error: ", 7);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(-1);
}

void	free_all_exit(t_vars *vars)
{
	xpm_free(vars);
	vect_free(vars);
	if (vars->img.img)
		free(vars->img.img);
	// if (vars->img.addr)
	// 	free(vars->img.addr);
	vars_free(vars);
	freestructs_exit(vars->cubinfo, -1);
}

void	normal_shutdown(t_vars *vars)
{
	xpm_free(vars);
	vect_free(vars);
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
		//free(vars->img.img);
	// if (vars->img.addr)
	// 	free(vars->img.addr);
	if (vars->cubinfo)
		cubinfo_free(vars->cubinfo);
	vars_free(vars);
	exit(0);
}
