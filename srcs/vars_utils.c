/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:11:02 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/06 16:17:37 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	vars_set_trgb(t_vars *vars)
{
	vars->trgb_floor.t = 0;
	vars->trgb_floor.r = vars->cubinfo->color_floor[0];
	vars->trgb_floor.g = vars->cubinfo->color_floor[1];
	vars->trgb_floor.b = vars->cubinfo->color_floor[2];
	vars->trgb_sky.t = 0;
	vars->trgb_sky.r = vars->cubinfo->color_ceil[0];
	vars->trgb_sky.g = vars->cubinfo->color_ceil[1];
	vars->trgb_sky.b = vars->cubinfo->color_ceil[2];
	vars->trgb_text.t = 0;
	vars->trgb_text.r = 255;
	vars->trgb_text.g = 0;
	vars->trgb_text.b = 0;
}

static void	vars_get_sprites(t_vars *vars)
{
	t_sprite	*sprites;
	int			i;
	int			j;
	int			k;

	sprites = malloc((vars->cubinfo->sprite_qt + 1)* sizeof(t_sprite));
	k = 0;
	i = 0;
	while (vars->cubinfo->map[i])
	{
		j = 0;
		while (vars->cubinfo->map[i][j])
		{
			if (vars->cubinfo->map[i][j] == '2')
			{
				sprites[k].pos.y = 0.5 + i;
				sprites[k].pos.x = 0.5 + j;
				sprites[k].pos.z = 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
	sprites[k].pos.y = -255;
	sprites[k].pos.x = -255;
	sprites[k].pos.z = -255;
	vars->sprites = sprites;
}

static void	vars_pc_init(t_vars *vars)
{
	vars->pc.pos.x = 0.5 + vars->cubinfo->spawn[1];
	vars->pc.pos.y = 0.5 + vars->cubinfo->spawn[0];
	vars->pc.pos.z = 0.5;
	vars->pc.view.x = 0;
	vars->pc.view.y = -1;
	vars->pc.view.z = 0;
	vars->pc.head_tilt = 0.0;
	if (vars->cubinfo->facing == 'N')
	{
		vars->pc.angle = 0;
	}
	else if (vars->cubinfo->facing == 'S')
	{
		vars->pc.angle = M_PI;
	}
	else if (vars->cubinfo->facing == 'E')
	{
		vars->pc.angle = M_PI_2;
	}
	else if (vars->cubinfo->facing == 'W')
	{
		vars->pc.angle = - M_PI_2;
	}
	vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
}

static void vars_keys_init(t_vars *vars)
{
	vars->keys.up = 0;
	vars->keys.down = 0;
	vars->keys.left = 0;
	vars->keys.right = 0;
	vars->keys.turn_l = 0;
	vars->keys.turn_r = 0;

}
void	vars_init(t_cubinfo *cubinfo, t_vars *vars)
{
	vars->cubinfo = cubinfo;
	vars_set_trgb(vars);
	vars_get_sprites(vars);
	vars->planes_x = plane_factory_x(vars);
	vars->planes_y = plane_factory_y(vars);
	vars->plane_sky = (t_plane){0, 0, 1, -1};
	vars->plane_floor = (t_plane){0, 0, 1, 0};
	vars_keys_init(vars);
	vars_pc_init(vars);
	vect_precalc(vars);
	vars->pc.angle = vars->pc.angle + 0.0001;
	vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
}