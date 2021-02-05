/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:35:22 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/23 12:36:57 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_digit_count(long int n)
{
	int		i;

	if (n < 0)
		n *= -1;
	i = 1;
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_ltoa(long int long_n)
{
	char			*str;
	int				digit_count;

	digit_count = ft_get_digit_count(long_n);
	if (long_n < 0)
		digit_count++;
	if (!(str = malloc((digit_count + 1) * sizeof(char))))
		return (NULL);
	str[0] = '0';
	if (long_n < 0)
	{
		str[0] = '-';
		long_n *= -1;
	}
	str[digit_count] = '\0';
	while (((digit_count >= 0 && str[0] != '-')
		|| (digit_count > 0 && str[0] == '-')) && long_n != 0)
	{
		str[digit_count - 1] = (long_n % 10) + '0';
		long_n /= 10;
		digit_count--;
	}
	return (str);
}
