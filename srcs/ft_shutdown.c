/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shutdown.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:54:20 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/24 11:12:31 by kzennoun         ###   ########lyon.fr   */
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
	//if (mapinfo)
	//	mapinfo_free(mapinfo);
	if (cubinfo)
		cubinfo_free(cubinfo);
	error_exit(err);
}

void	freestructs_msg(t_cubinfo *cubinfo, char *str)
{
	//if (mapinfo)
	//	mapinfo_free(mapinfo);
	if (cubinfo)
		cubinfo_free(cubinfo);
	write(1, "Error: ", 7);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(-1);
}
/*
void	freecub_exit(t_cubinfo *cubinfo, int err)
{
	cubinfo_free(cubinfo);
	error_exit(err);
}



void	freemap_cub_exit(t_mapinfo *mapinfo, t_cubinfo *cubinfo, int err)
{
	mapinfo_free(mapinfo);
	freecub_exit(cubinfo, err);
}

*/