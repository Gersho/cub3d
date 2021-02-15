/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:48:51 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/11 14:06:43 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long int	long_nb;

	long_nb = nb;
	if (long_nb < 0)
	{
		write(fd, "-", 1);
		long_nb *= -1;
	}
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
