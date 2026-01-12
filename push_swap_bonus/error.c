/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:56:55 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/12 12:04:56 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freepile(t_list **pile)
{
	t_list	*current;
	t_list	*next;

	if (*pile == NULL)
		return ;
	current = (*pile)->next;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(*pile);
}

int	ft_error(t_list **pile_a, t_list **pile_b, char *str)
{
	int	i;

	i = 0;
	freepile(pile_a);
	freepile(pile_b);
	while (str[i])
		i++;
	write(2, &str[0], i);
	write(2, "\n", 1);
	return (0);
}

void	freeall(t_list **pile_a, t_list **pile_b, char ***tab, char **av)
{
	if (!(*tab == av + 1))
		ft_free_tab(*tab);
	freepile(pile_a);
	freepile(pile_b);
}

int	has_duplicates(t_list *pile)
{
	t_list	*i;
	t_list	*j;

	i = pile;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->content == j->content)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	is_sorted(t_list *pile)
{
	if (pile == NULL || pile->next == NULL)
		return (1);
	while (pile->next)
	{
		if (pile->content > pile->next->content)
			return (0);
		pile = pile->next;
	}
	return (1);
}
