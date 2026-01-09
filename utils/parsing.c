/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 19:00:44 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/09 19:40:54 by mobenhab         ###   ########.fr       */
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
	if (ft_strcmp(str, "--simple") == 0 && stock->strategy == NULL)
		stock->strategy = ft_strcpy(&str[2]);
	else if (ft_strcmp(str, "--medium") == 0 && stock->strategy == NULL)
		stock->strategy = ft_strcpy(&str[2]);
	else if (ft_strcmp(str, "--complex") == 0 && stock->strategy == NULL)
		stock->strategy = ft_strcpy(&str[2]);
	else if (ft_strcmp(str, "--adaptive") == 0 && stock->strategy == NULL)
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
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] == '-' || tab[i][j] == '+') 
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
	int	i;

	i = 1;
	while (av[i] && (i == 1 || i == 2) && av[i][0] == '-' && av[i][1] == '-')
	{
		if (check_strategy(av[i++], stock) == 1)
			return (1);
		*begin += 1;
	}
	if (av[*begin + 1] == NULL)
		stock->tab = ft_split(av[*begin], ' ');
	if (stock->tab != NULL)
	{
		if (check_digits(stock->tab, *begin) == 1)
			return (1);
	}
	else if (check_digits(av, *begin) == 1)
		return (1);
	return (0);
}
