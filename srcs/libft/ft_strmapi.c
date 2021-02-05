/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:15:46 by kzennoun          #+#    #+#             */
/*   Updated: 2020/11/28 13:31:57 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	int					len_s;
	char				*ptr;

	if (!s || !(*f))
		return (NULL);
	len_s = ft_strlen(s);
	if (!(ptr = malloc((len_s + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
