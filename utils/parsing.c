/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 19:00:44 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/09 12:08:17 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strcpy(char *src)
{
	char	*dest;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (dest[j])
	{
		src[j] = dest[j];
		j++;
	}
	src[j] = '\0';
	free(dest);
	return (src);
}

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

int	check_strategy(char *str, t_stock *stock)
{
	int	i;

	i = 2;
	if (ft_strcmp(str, "--simple") == 0)
		stock->strategy = ft_strcpy(&str[2]);
	else if (ft_strcmp(str, "--medium") == 0)
		stock->strategy = ft_strcpy(&str[2]);
	else if (ft_strcmp(str, "--complex") == 0)
		stock->strategy = ft_strcpy(&str[2]);
	else if (ft_strcmp(str, "--adaptive") == 0)
		stock->strategy = ft_strcpy(&str[2]);
	else if (ft_strcmp(str, "--bench") == 0)
		stock->bench = ft_strcpy(&str[2]);
	else
		return (1);
	return (0);
}

int	check_digits(char **tab, int begin)
{
	int	i;
	int	j;

	i = begin;
	j = 0;
	while (tab[i])
	{
		if (tab[i][j] == '-')
			j++;
		while (tab[i][j])
		{
			if (!(tab[i][j] >= '0' && tab[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(char **av, t_stock *stock, int *begin)
{
	int		i;
	char	**tab;

	i = 1;
	tab = NULL;
	while (av[i] && (i == 1 || i == 2) && av[i][0] == '-' && av[i][1] == '-')
	{
		if (check_strategy(av[i++], stock) == 1)
			return (1);
		*begin += 1;
	}
	if (av[*begin + 1] == NULL)
		tab = ft_split(av[*begin], ' ');
	if (tab != NULL)
	{
		__builtin_printf("OKO");
		if (check_digits(tab, *begin) == 1)
			return (1);
	}
	else if (check_digits(av, *begin) == 1)
		return (1);
	return (0);
}
