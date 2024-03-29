/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:40:49 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/14 13:58:46 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	bmp_header(t_vars *vars, int fd)
{
	int	filesize;
	int	offset;

	offset = 58;
	filesize = offset + (vars->cubinfo->res[0] * vars->cubinfo->res[1] * 4);
	write(fd, "BM", 2);
	write(fd, &filesize, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &offset, 4);
}

static void	bmp_infoheader(t_vars *vars, int fd)
{
	int	i;
	int	infoheadsize;
	int	planes;
	int	bpp;

	infoheadsize = 40;
	planes = 1;
	bpp = 32;
	write(fd, &infoheadsize, 4);
	write(fd, &vars->cubinfo->res[0], 4);
	write(fd, &vars->cubinfo->res[1], 4);
	write(fd, &planes, 2);
	write(fd, &bpp, 2);
	i = 0;
	while (i < 28)
	{
		write(fd, "\0", 1);
		i++;
	}
}

static void	bmp_pixeldata(t_vars *vars, int fd)
{
	int	i;
	int	j;
	int	*addr;

	addr = (int *)vars->img.addr;
	j = vars->cubinfo->res[1] - 1;
	while (j >= 0)
	{
		i = -1;
		while (++i < vars->cubinfo->res[0])
		{
			write(fd, &addr[j * vars->cubinfo->res[0] + i], 4);
		}
		j--;
	}
}

void	img_to_bmp(t_vars *vars)
{
	int		fd;
	char	*name;

	name = ft_strdup("image.bmp");
	if (!name)
	{
		free_all_exit(vars);
	}
	fd = open(name, O_CREAT | O_RDWR, 0644);
	if (!fd)
	{
		free(name);
		free_all_exit(vars);
	}
	bmp_header(vars, fd);
	bmp_infoheader(vars, fd);
	bmp_pixeldata(vars, fd);
	close(fd);
	free(name);
	normal_shutdown(vars);
}
