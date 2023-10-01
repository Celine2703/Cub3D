/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:06:43 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/04 15:06:45 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = temp;
	}
}
