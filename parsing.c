/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 19:00:44 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/04 19:40:05 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *src)
{
	char	*dest;
	size_t	i;
	size_t j;
	
	j = 0;
	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
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

int	check_strategy(char *arg)
{
	size_t	i;
	size_t	j;
	char	*strategy;

	j = 0;
	i = 2;
	if (arg[0] != '-')
	{
		ft_printf("Error\n");
		return (0);
	}
	if (arg[1] != '-')
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!arg[2])
	{
		ft_printf("Error\n");
		return (0);
	}
	strategy = ft_strcpy(&arg[2]);
	type_stratgy(strategy);
	return (1);
}

void	type_stratgy(const char *str)
{
	if (ft_strcmp(str, "simple") == 0)
		ft_printf("simple");
	else if (ft_strcmp(str, "medium") == 0)
		ft_printf("medium");
	else if (ft_strcmp(str, "complex") == 0)
		ft_printf("complex");
	else if (ft_strcmp(str, "adaptive") == 0)
		ft_printf("adaptive");
	else
		{
			printf("Error\n");
			return ;
		}
}
int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s2[i] - s1[i]);
		i++;
	}
	return (s2[i] - s1[i]);
}