/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:41:53 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/25 14:52:43 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_plane	*plane_factory(t_cubinfo *cubinfo)
{
	int	i;
	int	j;
	t_plane *planes;

	i = 0;
	j = 0;
	planes = malloc((cubinfo->map_size[0] + cubinfo->map_size[1] + 1) * sizeof(t_plane));
	printf("planes:%d\n", (cubinfo->map_size[0] + cubinfo->map_size[1] + 1));
	if (!planes)
		exit(0);
	while (i < cubinfo->map_size[0] - 1)
	{
		planes[i] = (t_plane){0, 1, 0, -(i + 1)};
		i++;
	}
	while (j < cubinfo->map_size[1] - 1)
	{
		planes[i+j] = (t_plane){1, 0, 0, -(j + 1)};
		j++;
	}
	//floor
	planes[i+j] = (t_plane){0, 0, 1, 0};
	//sky
	planes[i+j+1] = (t_plane){0, 0, 1, -1};
	planes[i+j+2] = (t_plane){-255, -255, -255, -255};
	return (planes);
}

int	is_lastplane(t_plane plane)
{
	if (plane.a == -255 && plane.b == -255 && plane.c == -255 \
    && plane.d == -255)
		return (1);
	return (0);
}