/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:48:00 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/27 16:22:03 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	xpm_load(t_vars *vars)
{

	vars->n_xpm.img = mlx_xpm_file_to_image(vars->mlx, vars->cubinfo->path_N, &vars->n_xpm.img_width, &vars->n_xpm.img_height);
	if (!vars->n_xpm.img)
		exit(0);
	vars->s_xpm.img = mlx_xpm_file_to_image(vars->mlx, vars->cubinfo->path_S, &vars->s_xpm.img_width, &vars->s_xpm.img_height);
	if (!vars->s_xpm.img)
		exit(0);
	vars->e_xpm.img = mlx_xpm_file_to_image(vars->mlx, vars->cubinfo->path_E, &vars->e_xpm.img_width, &vars->e_xpm.img_height);
	if (!vars->e_xpm.img)
		exit(0);
	vars->w_xpm.img = mlx_xpm_file_to_image(vars->mlx, vars->cubinfo->path_W, &vars->w_xpm.img_width, &vars->w_xpm.img_height);
	if (!vars->w_xpm.img)
		exit(0);

	vars->sprite_xpm.img = mlx_xpm_file_to_image(vars->mlx, vars->cubinfo->path_sprite, &vars->sprite_xpm.img_width, &vars->sprite_xpm.img_height);
	if (!vars->sprite_xpm.img)
		exit(0);
}

void	xpm_getaddr(t_vars *vars)
{
	vars->n_xpm.addr = mlx_get_data_addr(vars->n_xpm.img, &vars->n_xpm.bits_per_pixel, &vars->n_xpm.line_length, &vars->n_xpm.endian);
	vars->s_xpm.addr = mlx_get_data_addr(vars->s_xpm.img, &vars->s_xpm.bits_per_pixel, &vars->s_xpm.line_length, &vars->s_xpm.endian);
	vars->e_xpm.addr = mlx_get_data_addr(vars->e_xpm.img, &vars->e_xpm.bits_per_pixel, &vars->e_xpm.line_length, &vars->e_xpm.endian);
	vars->w_xpm.addr = mlx_get_data_addr(vars->w_xpm.img, &vars->w_xpm.bits_per_pixel, &vars->w_xpm.line_length, &vars->w_xpm.endian);
	vars->sprite_xpm.addr = mlx_get_data_addr(vars->sprite_xpm.img, &vars->sprite_xpm.bits_per_pixel, &vars->sprite_xpm.line_length, &vars->sprite_xpm.endian);
	// printf("n_xpm ptr:%p\n", vars->n_xpm.img);
	// printf("n_xpm img width: %d\n", vars->n_xpm.img_width);
	// printf("n_xpm img height: %d\n", vars->n_xpm.img_height);
	// printf("n_xpm line length: %d\n", vars->n_xpm.line_length);
	// printf("n_xpm bits per pix: %d\n", vars->n_xpm.bits_per_pixel);

	// 	printf("s_xpm ptr:%p\n", vars->s_xpm.img);
	// 	printf("s_xpm img width: %d\n", vars->s_xpm.img_width);
	// printf("s_xpm img height: %d\n", vars->s_xpm.img_height);
	// printf("s_xpm line length: %d\n", vars->s_xpm.line_length);
	// printf("s_xpm bits per pix: %d\n", vars->s_xpm.bits_per_pixel);

	// printf("e_xpm ptr:%p\n", vars->e_xpm.img);
	// 	printf("e_xpm img width: %d\n", vars->e_xpm.img_width);
	// printf("e_xpm img height: %d\n", vars->e_xpm.img_height);
	// printf("e_xpm line length: %d\n", vars->e_xpm.line_length);
	// printf("e_xpm bits per pix: %d\n", vars->e_xpm.bits_per_pixel);

	// 	printf("w_xpm ptr:%p\n", vars->w_xpm.img);
	// 	printf("w_xpm img width: %d\n", vars->w_xpm.img_width);
	// printf("w_xpm img height: %d\n", vars->w_xpm.img_height);
	// printf("w_xpm line length: %d\n", vars->w_xpm.line_length);
	// printf("w_xpm bits per pix: %d\n", vars->w_xpm.bits_per_pixel);

	printf("sprite xpm ptr:%p\n", vars->sprite_xpm.img);
}