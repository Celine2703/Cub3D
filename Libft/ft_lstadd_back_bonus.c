/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:46:22 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/04 14:46:24 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*av;

	if (!new || !lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	av = *lst;
	while (av ->next)
		av = av ->next;
	av ->next = new;
}
