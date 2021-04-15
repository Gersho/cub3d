/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb_from_xpm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:53:35 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/15 14:38:45 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_trgb	get_trgb_from_xpm_e(t_data *xpm, t_coord inter)
{
	t_coord	tmp;
	int		tex_x;
	int		tex_y;
	t_trgb	trgb;

	tmp.y = inter.y - (int)inter.y;
	tmp.z = inter.z - (int)inter.z;
	tex_x = (xpm->img_width * tmp.y);
	tex_y = xpm->img_height - (xpm->img_height * tmp.z);
	trgb.b = (uint8_t)xpm->addr[tex_y * xpm->line_length + tex_x * 4];
	trgb.g = (uint8_t)xpm->addr[tex_y * xpm->line_length + tex_x * 4 + 1];
	trgb.r = (uint8_t)xpm->addr[tex_y * xpm->line_length + tex_x * 4 + 2];
	trgb.t = (uint8_t)xpm->addr[tex_y * xpm->line_length + tex_x * 4 + 3];
	return (trgb);
}

t_trgb	get_trgb_from_xpm_w(t_data *xpm, t_coord inter)
{
	t_coord	tmp;
	int		tex_x;
	int		tex_y;
	t_trgb	trgb;

	tmp.y = inter.y - (int)inter.y;
	tmp.z = inter.z - (int)inter.z;
	tex_x = xpm->img_width - (xpm->img_width * tmp.y);
	tex_y = xpm->img_height - (xpm->img_height * tmp.z);
	trgb.b = (uint8_t)xpm->addr[tex_y * xpm->line_length + tex_x * 4];
	trgb.g = (uint8_t)xpm->addr[tex_y * xpm->line_length + tex_x * 4 + 1];
	trgb.r = (uint8_t)xpm->addr[tex_y * xpm->line_length + tex_x * 4 + 2];
	trgb.t = (uint8_t)xpm->addr[tex_y * xpm->line_length + tex_x * 4 + 3];
	return (trgb);
}

t_trgb	get_trgb_from_xpm_n(t_data *xpm, t_coord inter)
{
	t_coord	tmp;
	int		tex_x;
	int		tex_y;
	t_trgb	trgb;

	tmp.x = inter.x - (int)inter.x;
	tmp.z = inter.z - (int)inter.z;
	tex_x = (xpm->img_width * tmp.x);
	tex_y = xpm->img_height - (xpm->img_height * tmp.z);
	trgb.b = (uint8_t)xpm->addr[(tex_y * xpm->line_length + tex_x * 4)];
	trgb.g = (uint8_t)xpm->addr[(tex_y * xpm->line_length + tex_x * 4 + 1)];
	trgb.r = (uint8_t)xpm->addr[(tex_y * xpm->line_length + tex_x * 4 + 2)];
	trgb.t = (uint8_t)xpm->addr[(tex_y * xpm->line_length + tex_x * 4 + 3)];
	return (trgb);
}

t_trgb	get_trgb_from_xpm_s(t_data *xpm, t_coord inter)
{
	t_coord	tmp;
	int		tex_x;
	int		tex_y;
	t_trgb	trgb;

	tmp.x = inter.x - (int)inter.x;
	tmp.z = inter.z - (int)inter.z;
	tex_x = xpm->img_width - (xpm->img_width * tmp.x);
	tex_y = xpm->img_height - (xpm->img_height * tmp.z);
	trgb.b = (uint8_t)xpm->addr[(tex_y * xpm->line_length + tex_x * 4)];
	trgb.g = (uint8_t)xpm->addr[(tex_y * xpm->line_length + tex_x * 4 + 1)];
	trgb.r = (uint8_t)xpm->addr[(tex_y * xpm->line_length + tex_x * 4 + 2)];
	trgb.t = (uint8_t)xpm->addr[(tex_y * xpm->line_length + tex_x * 4 + 3)];
	return (trgb);
}

t_trgb	get_trgb_from_xpm_sprite(t_data *xpm, t_coord inter, double pscale)
{
	t_coord	tmp;
	int		tex_x;
	int		tex_y;
	t_trgb	trgb;

	if (pscale > 1 || pscale < 0)
	{
		trgb.trgb = 0;
		return (trgb);
	}
	tmp.z = inter.z - (int)inter.z;
	tex_y = xpm->img_height - (xpm->img_height * tmp.z);
	tex_x = xpm->img_width * pscale;
	trgb.b = (uint8_t)xpm->addr[(tex_y * xpm->line_length + tex_x * 4)];
	trgb.g = (uint8_t)xpm->addr[(tex_y * xpm->line_length + tex_x * 4 + 1)];
	trgb.r = (uint8_t)xpm->addr[(tex_y * xpm->line_length + tex_x * 4 + 2)];
	trgb.t = (uint8_t)xpm->addr[(tex_y * xpm->line_length + tex_x * 4 + 3)];
	return (trgb);
}
