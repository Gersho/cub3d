/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxchary_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:21:59 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/15 11:28:36 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putxchary_fd(int x, char y, int fd)
{
	while (x > 0)
	{
		ft_putchar_fd(y, fd);
		x--;
	}
}
