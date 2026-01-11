/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:29:40 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/11 02:36:33 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(int content, char *str)
{
	char	*new_str;

	new_str = ft_itoa(content);
	if (str[0] == '+')
		str++;
	if (ft_strcmp(new_str, str) != 0)
	{
		free(new_str);
		return (1);
	}
	free(new_str);
	return (0);
}

int	init_pile(t_list **pile_a, char **tab)
{
	t_list	*new;
	t_list	*last;
	size_t	i;

	i = 0;
	last = NULL;
	while (tab[i])
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (1);
		new->content = ft_atoi(tab[i]);
		new->next = NULL;
		if (*pile_a == NULL)
			*pile_a = new;
		else
			last->next = new;
		last = new;
		if (check_overflow(new->content, tab[i]))
			return (1);
		i++;
	}
	return (0);
}
