/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shutdown.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:54:20 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/16 11:03:09 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	clean_exit(int err)
{
	perror("Error");
	exit(err);
}

void	freecub_exit(t_cubinfo *cubinfo, int err)
{
	cubinfo_free(cubinfo);
	clean_exit(err);
}
