/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:48:00 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/24 17:30:26 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	xpm_load(t_vars *vars)
{

	vars->n_xpm.img = mlx_xpm_file_to_image(vars->mlx, vars->cubinfo->path_N, &vars->n_xpm.img_width, &vars->n_xpm.img_height);
	if (!vars->n_xpm.img)
		exit(0);
	printf("n_xpm ptr:%p\n", vars->n_xpm.img);
		vars->s_xpm.img = mlx_xpm_file_to_image(vars->mlx, vars->cubinfo->path_S, &vars->s_xpm.img_width, &vars->s_xpm.img_height);
	if (!vars->s_xpm.img)
		exit(0);
	printf("s_xpm ptr:%p\n", vars->s_xpm.img);

		vars->e_xpm.img = mlx_xpm_file_to_image(vars->mlx, vars->cubinfo->path_E, &vars->e_xpm.img_width, &vars->e_xpm.img_height);
	if (!vars->e_xpm.img)
		exit(0);
	printf("e_xpm ptr:%p\n", vars->e_xpm.img);

		vars->w_xpm.img = mlx_xpm_file_to_image(vars->mlx, vars->cubinfo->path_W, &vars->w_xpm.img_width, &vars->w_xpm.img_height);
	if (!vars->w_xpm.img)
		exit(0);
	printf("w_xpm ptr:%p\n", vars->w_xpm.img);
}

void	xpm_getaddr(t_vars *vars)
{
	vars->n_xpm.addr = mlx_get_data_addr(vars->n_xpm.img, &vars->n_xpm.bits_per_pixel, &vars->n_xpm.line_length, &vars->n_xpm.endian);
	vars->s_xpm.addr = mlx_get_data_addr(vars->s_xpm.img, &vars->s_xpm.bits_per_pixel, &vars->s_xpm.line_length, &vars->s_xpm.endian);
	vars->e_xpm.addr = mlx_get_data_addr(vars->e_xpm.img, &vars->e_xpm.bits_per_pixel, &vars->e_xpm.line_length, &vars->e_xpm.endian);
	vars->w_xpm.addr = mlx_get_data_addr(vars->w_xpm.img, &vars->w_xpm.bits_per_pixel, &vars->w_xpm.line_length, &vars->w_xpm.endian);
}