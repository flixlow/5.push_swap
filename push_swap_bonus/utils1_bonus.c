/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:42:36 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/12 17:37:39 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s2[i] - s1[i]);
		i++;
	}
	return (s2[i] - s1[i]);
}

void	*ft_bzero(char	*line, char *buf)
{
	int	i;

	i = 0;
	if (line != NULL)
		free(line);
	while (i < BUFFER_SIZE)
		buf[i++] = 0;
	return (NULL);
}

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

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}
