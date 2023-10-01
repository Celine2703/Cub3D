/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:40:52 by cmartin-          #+#    #+#             */
/*   Updated: 2022/02/08 21:52:55 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check(char c)
{
	if ((c == ' ') || (c == '\f') || (c == '\n') || (c == '\r'))
		return (1);
	else if ((c == '\v') || (c == '\t'))
		return (1);
	return (0);
}

static int	signe(char *str, int *i, int sign)
{
	if ((str[*i] == '-') || (str[*i] == '+'))
	{
		if (str[*i] == '-')
			sign = -1;
		*i = (*i) + 1;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	nb = 0;
	i = 0;
	while (check(str[i]))
		i++;
	while (str[i] != 0)
	{
		sign = signe((char *)str, &i, 1);
		while (str[i] >= '0' && str[i] <= '9')
		{
			nb *= 10;
			nb += (str[i] - '0');
			i++;
		}
		return (sign * nb);
	}
	return (0);
}
