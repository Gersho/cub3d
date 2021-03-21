/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:27:20 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/21 11:28:19 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_coord move_pc(t_vars *vars, int x)
{
	t_coord res;

	res.x = vars->pc.pos.x + x * (vars->pc.view.x * 0.1);
	res.y = vars->pc.pos.y + x * (vars->pc.view.y * 0.1);
	res.z = vars->pc.pos.z;
	
	return (res);
}