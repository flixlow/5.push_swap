/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:37:32 by flauweri          #+#    #+#             */
/*   Updated: 2026/01/11 02:14:29 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

static char	**ft_count_word(char const *s, char c, int *a, int *b)
{
	int		i;
	int		count;
	char	**tab;

	i = 0;
	*a = 0;
	*b = 0;
	count = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			count++;
		else if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	tab = malloc(sizeof(char *) * (count + 1));
	if (tab == 0)
		return (0);
	tab[count] = 0;
	return (tab);
}

char	**ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		x;
	char	**tab;

	if (s == 0)
		return (0);
	tab = ft_count_word(s, c, &i, &x);
	while (s[i] && tab != 0)
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			j = i;
			while (s[j] != c && s[j])
				j++;
			tab[x] = malloc(sizeof(char) * (j - i + 1));
			if (tab[x] == 0)
				return (ft_free_tab(tab));
			ft_strlcpy(tab[x++], &s[i], (j - i + 1));
			i = j;
		}
		if (s[i])
			i++;
	}
	return (tab);
}
