/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:44:18 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/03 17:44:32 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long int nb)
{
	int	cpt;

	cpt = 0;
	while (nb / 10)
	{
		cpt++;
		nb = nb / 10;
	}
	return (cpt);
}

char	*ft_itoa(int n)
{
	char		*tab;
	int			cpt;
	long int	nb;
	int			signe;

	nb = n;
	signe = 0;
	if (nb < 0)
	{
		signe = 1;
		nb = nb * -1;
	}
	cpt = ft_count(nb) + signe + 1;
	tab = malloc(sizeof(char) * cpt + 1);
	if (tab == 0)
		return (0);
	tab[cpt--] = '\0';
	while (cpt >= 0)
	{
		tab[cpt--] = nb % 10 + 48;
		nb = nb / 10;
	}
	if (signe)
		tab[0] = '-';
	return (tab);
}
