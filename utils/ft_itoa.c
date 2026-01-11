/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:16:55 by flauweri          #+#    #+#             */
/*   Updated: 2026/01/11 15:43:23 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_count_div(unsigned int m)
{
	int	i;

	i = 0;
	if (m == 0)
		return (1);
	while (m > 0)
	{
		m = m / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	m;
	char			*tab;

	m = n;
	if (n < 0)
		m *= -1;
	i = ft_count_div(m);
	tab = malloc(sizeof(char) * (i + 1 + (n < 0)));
	if (tab == 0)
		return (0);
	tab[i + (n < 0)] = 0;
	if (n == 0)
		tab[0] = '0';
	while (m > 0 && n != 0)
	{
		tab[--i + (n < 0)] = m % 10 + '0';
		m = m / 10;
	}
	if (n < 0)
		tab[0] = '-';
	return (tab);
}
