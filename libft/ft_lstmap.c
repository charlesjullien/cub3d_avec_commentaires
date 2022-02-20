/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:33:55 by mabuchar          #+#    #+#             */
/*   Updated: 2021/01/19 14:53:42 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*begin;

	if (!lst || !f)
		return (NULL);
	begin = NULL;
	while (lst)
	{
		newlist = ft_lstnew(f(lst->content));
		if (newlist == NULL)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&begin, newlist);
	}
	return (begin);
}
