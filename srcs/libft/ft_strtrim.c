/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:47:22 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/15 11:38:07 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_norme_avoid(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (ft_strchr(set, (int)s1[i]) && s1[i] != '\0')
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = ft_norme_avoid(s1, set);
	if (i == len)
	{
		ptr = malloc(sizeof(char));
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	while (ft_strchr(set, (int)s1[len]))
		len--;
	ptr = malloc((len - i + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, (s1 + i), (len - i + 1));
	ptr[len - i + 1] = '\0';
	return (ptr);
}
