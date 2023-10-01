/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:15:04 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/04 16:15:06 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*liste;
	t_list	*elem;

	if (!lst)
		return (0);
	liste = 0;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (elem == 0)
		{
			ft_lstclear(&liste, (del));
			return (0);
		}
		ft_lstadd_back(&liste, elem);
		lst = lst ->next;
	}
	return (liste);
}
