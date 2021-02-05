/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:33:23 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/21 12:43:18 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_udigit_count(long unsigned int n)
{
	int		i;

	i = 1;
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	char					*str;
	int						digit_count;
	long unsigned int		long_n;

	long_n = n;
	digit_count = ft_get_udigit_count(long_n);
	if (!(str = malloc((digit_count + 1) * sizeof(char))))
		return (NULL);
	str[0] = '0';
	str[digit_count] = '\0';
	while (digit_count >= 0 && long_n != 0)
	{
		str[digit_count - 1] = (long_n % 10) + '0';
		long_n /= 10;
		digit_count--;
	}
	return (str);
}
