/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:29:36 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/14 17:28:58 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ptr_minifree(char **ptr)
{
	int	i;

	i = 0;
	if (ptr != NULL)
	{
		while (ptr[i] != NULL)
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
	}
}

static void	abort_parse_r(char *line, t_cubinfo *cubinfo, char **ptr, char *msg)
{
	ptr_minifree(ptr);
	free(line);
	freestructs_msg(cubinfo, msg);
}


void	ft_parse_r(char *line, t_cubinfo *cubinfo)
{
	char	**ptr;
	int		i;
	int		j;

	ptr = ft_split(line + 1, ' ');
	if (ptr == NULL)
	{
		free(line);
		freestructs_exit(cubinfo, -1);
	}
	i = -1;
	while (ptr[++i])
	{
		j = -1;
		while (++j < (int)ft_strlen(ptr[i]))
			if (!(ft_isdigit(ptr[i][j]) || ptr[i][j] == ' '))
				abort_parse_r(line, cubinfo, ptr, "resolution is invalid.");
	}
	if (i != 2)
		abort_parse_r(line, cubinfo, ptr, "resolution is invalid.");
	if (cubinfo->res[0] != -1)
		abort_parse_r(line, cubinfo, ptr, "resolution set twice.");
	cubinfo->res[0] = ft_atoi(ptr[0]);
	cubinfo->res[1] = ft_atoi(ptr[1]);
	ptr_minifree(ptr);
}
