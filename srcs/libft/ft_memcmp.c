/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:40:34 by kzennoun          #+#    #+#             */
/*   Updated: 2020/11/25 03:12:39 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*casted_s1;
	unsigned char	*casted_s2;
	size_t			i;

	if (n == 0)
		return (0);
	casted_s1 = (unsigned char*)s1;
	casted_s2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (casted_s1[i] != casted_s2[i])
			return (casted_s1[i] - casted_s2[i]);
		i++;
	}
	return (0);
}
