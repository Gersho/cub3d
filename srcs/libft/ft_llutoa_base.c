/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:28:26 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/11 14:36:01 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_digit_count(unsigned long long int nbr, int base_len)
{
	int		i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr > 0)
	{
		i++;
		nbr /= base_len;
	}
	return (i);
}

int	check_base_is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (base[i + j])
		{
			if (base[i] == base[i + j + 1])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_llutoa_base(unsigned long long int nbr, char *base)
{
	int			base_len;
	int			digit_count;
	char		*str;

	base_len = ft_strlen(base);
	digit_count = ft_get_digit_count(nbr, base_len);
	if (!check_base_is_valid(base) || base_len < 2)
		return (NULL);
	str = ft_calloc(digit_count + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (digit_count > 0)
	{
		str[digit_count - 1] = base[nbr % base_len];
		nbr /= base_len;
		digit_count--;
	}
	return (str);
}
