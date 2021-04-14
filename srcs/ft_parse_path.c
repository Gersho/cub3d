/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:29:45 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/14 16:24:22 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	abort_parse_path(char *line, t_cubinfo *cubinfo, char *ptr, char *msg)
{
	free(ptr);
	free(line);
	freestructs_msg(cubinfo, msg);
}

static void	more_parse_path(char *line, t_cubinfo *cubinfo, char *ptr)
{
	if (line[0] == 'S' && line[1] == 'O')
	{
		if (cubinfo->path_S != NULL)
			abort_parse_path(line, cubinfo, ptr, "path SO set twice.");
		cubinfo->path_S = ptr;
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		if (cubinfo->path_E != NULL)
			abort_parse_path(line, cubinfo, ptr, "path EA set twice.");
		cubinfo->path_E = ptr;
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		if (cubinfo->path_W != NULL)
			abort_parse_path(line, cubinfo, ptr, "path WE set twice.");
		cubinfo->path_W = ptr;
	}
	else
		abort_parse_path(line, cubinfo, ptr, "invalid option.");
}

void	ft_parse_path(char *line, t_cubinfo *cubinfo)
{
	char	*ptr;

	ptr = ft_strtrim((line + 2), " ");
	if (ptr == NULL)
	{
		free(line);
		freestructs_exit(cubinfo, -1);
	}
	if (line[0] == 'S' && line[1] != 'O')
	{
		if (cubinfo->path_sprite != NULL)
			abort_parse_path(line, cubinfo, ptr, "path sprite set twice.");
		free(ptr);
		ptr = ft_strtrim((line + 1), " ");
		cubinfo->path_sprite = ptr;
	}
	else if (line[0] == 'N' && line[1] == 'O')
	{
		if (cubinfo->path_N != NULL)
			abort_parse_path(line, cubinfo, ptr, "path NO set twice.");
		cubinfo->path_N = ptr;
	}
	else
		more_parse_path(line, cubinfo, ptr);
}
