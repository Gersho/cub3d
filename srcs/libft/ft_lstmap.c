/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:24:23 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/02 14:51:45 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*first;
	t_list		*last;

	if (!lst)
		return (NULL);
	first = NULL;
	while (lst)
	{
		if (!(last = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, last);
		lst = lst->next;
	}
	return (first);
}
