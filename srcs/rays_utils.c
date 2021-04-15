/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:03:55 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/15 13:04:04 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	protect_ab(t_vars *vars, int *a, int *b, char *tile)
{
	if (*a <= 0)
		*a = 0;
	if (*a >= vars->cubinfo->map_size[0])
		*a = vars->cubinfo->map_size[0] - 1;
	if (*b <= 0)
		*b = 0;
	if (*b >= vars->cubinfo->map_size[1])
		*b = vars->cubinfo->map_size[1] - 1;
	*tile = vars->cubinfo->map[*a][*b];
}