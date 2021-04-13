/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:48:00 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/13 16:07:14 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void 	xpm_free(t_vars *vars)
{
	if (vars->n_xpm.img)
		mlx_destroy_image(vars->mlx, vars->n_xpm.img);
	if (vars->s_xpm.img)
		mlx_destroy_image(vars->mlx, vars->s_xpm.img);
	if (vars->e_xpm.img)
		mlx_destroy_image(vars->mlx, vars->e_xpm.img);
	if (vars->w_xpm.img)
		mlx_destroy_image(vars->mlx, vars->w_xpm.img);
	if (vars->sprite_xpm.img)
		mlx_destroy_image(vars->mlx, vars->sprite_xpm.img);
}

void	xpm_load(t_vars *vars)
{
	vars->n_xpm.img = mlx_xpm_file_to_image(vars->mlx, vars->cubinfo->path_N, \
	 &vars->n_xpm.img_width, &vars->n_xpm.img_height);
	vars->s_xpm.img = mlx_xpm_file_to_image(vars->mlx, vars->cubinfo->path_S, \
	 &vars->s_xpm.img_width, &vars->s_xpm.img_height);
	vars->e_xpm.img = mlx_xpm_file_to_image(vars->mlx, vars->cubinfo->path_E, \
	 &vars->e_xpm.img_width, &vars->e_xpm.img_height);
	vars->w_xpm.img = mlx_xpm_file_to_image(vars->mlx, vars->cubinfo->path_W, \
	 &vars->w_xpm.img_width, &vars->w_xpm.img_height);
	vars->sprite_xpm.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->cubinfo->path_sprite, &vars->sprite_xpm.img_width, \
	 &vars->sprite_xpm.img_height);
	if (!vars->n_xpm.img || !vars->s_xpm.img || !vars->e_xpm.img ||\
	 !vars->w_xpm.img || !vars->sprite_xpm.img)
	{
		xpm_free(vars);
		vars_free(vars);
		freestructs_exit(vars->cubinfo, -1);
	}
}

void	xpm_getaddr(t_vars *vars)
{
	vars->n_xpm.addr = mlx_get_data_addr(vars->n_xpm.img, \
	&vars->n_xpm.bits_per_pixel, &vars->n_xpm.line_length, &vars->n_xpm.endian);
	vars->s_xpm.addr = mlx_get_data_addr(vars->s_xpm.img, \
	&vars->s_xpm.bits_per_pixel, &vars->s_xpm.line_length, &vars->s_xpm.endian);
	vars->e_xpm.addr = mlx_get_data_addr(vars->e_xpm.img, \
	&vars->e_xpm.bits_per_pixel, &vars->e_xpm.line_length, &vars->e_xpm.endian);
	vars->w_xpm.addr = mlx_get_data_addr(vars->w_xpm.img, \
	&vars->w_xpm.bits_per_pixel, &vars->w_xpm.line_length, &vars->w_xpm.endian);
	vars->sprite_xpm.addr = mlx_get_data_addr(vars->sprite_xpm.img, \
	&vars->sprite_xpm.bits_per_pixel, &vars->sprite_xpm.line_length, \
	&vars->sprite_xpm.endian);
	if (!vars->n_xpm.addr || !vars->s_xpm.addr || !vars->e_xpm.addr ||\
	 !vars->w_xpm.addr || !vars->sprite_xpm.addr)
	{
		xpm_free(vars);
		vars_free(vars);
		free(vars->mlx);
		freestructs_exit(vars->cubinfo, -1);
	}
}

void	xpm_setup(t_vars *vars)
{
	xpm_load(vars);
	xpm_getaddr(vars);
}
