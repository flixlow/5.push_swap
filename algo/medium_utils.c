/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:23:25 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/07 15:05:32 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *pile_a)
{
	t_list	*tmp;

	if (!pile_a || !pile_a->first)
		return (1);
	tmp = pile_a->first;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	find_max_index(t_stack *b)
{
	int			max;
	t_list		*tmp;

	tmp = b->first;
	max = -1;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	find_pos_index(t_stack *b, int index)
{
	int			pos;
	t_list		*tmp;

	tmp = b->first;
	pos = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

void	push_chunk(t_stack *a, t_stack *b)
{
	int		max;
	int		pos;

	while (b->first)
	{
		max = find_max_index(b);
		pos = find_pos_index(b, max);
		if (pos == 0)
			pa(a, b);
		else if (pos <= lstlen(b) / 2)
			rb(b);
		else
			rrb(b);
	}
}

void	push_to_b(t_stack *a, t_stack *b, int chunk)
{
	int		i;
	int		size;

	i = 0;
	size = lstlen(a);
	while (a->first)
	{
		if (a->first->index <= i)
		{
			pb(b, a);
			rb(b);
			i++;
		}
		else if (a->first->index <= i + chunk)
		{
			pb(b, a);
			i++;
		}
		else
			ra(a);
	}
}
/*
chunk sort en gros c'est de trie par chunk(partie) du coup
on push les 5 plus petit
apres les 5 plus grand
jusqu'a qu'on arrive a la fin
apres dans b on une pile trie par chunk il va reste qu'a trie les chunk
genre trie les 5 plus petit
jusqu'a arrive a la fin
*/