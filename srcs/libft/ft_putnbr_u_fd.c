/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:24:56 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/21 12:39:48 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_u_fd(unsigned int nb, int fd)
{
	long unsigned int long_nb;

	long_nb = nb;
	if (long_nb >= 10)
	{
		ft_putnbr_fd(long_nb / 10, fd);
		ft_putnbr_fd(long_nb % 10, fd);
	}
	else
	{
		ft_putchar_fd(('0' + long_nb), fd);
	}
}
