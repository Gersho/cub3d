/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:38:08 by kzennoun          #+#    #+#             */
/*   Updated: 2020/11/29 15:15:56 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*ptr;
	t_list		*to_del;

	ptr = *lst;
	while (ptr->next)
	{
		to_del = ptr;
		ptr = ptr->next;
		ft_lstdelone(to_del, (*del));
	}
	ft_lstdelone(ptr, (*del));
	*lst = NULL;
}
