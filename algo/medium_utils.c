/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:23:25 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/10 18:21:02 by mobenhab         ###   ########.fr       */
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
	int		max;
	t_list	*tmp;

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
	int		pos;
	t_list	*tmp;

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
	int	max;
	int	pos;
	int	size;

	while (b->first)
	{
		size = lstlen(b);
		max = find_max_index(b);
		pos = find_pos_index(b, max);
		if (pos == 0)
			pa(a, b);
		else if (pos <= size / 2)
			rb(b);
		else
			rrb(b);
	}
}

void	push_to_b(t_stack *a, t_stack *b, int chunk)
{
	int	pushed;
	int	limit;

	pushed = 0;
	limit = chunk;
	while (a->first)
	{
		if (a->first->index < limit)
		{
			pb(b, a);
			pushed++;
			if (pushed == limit)
				limit += chunk;
		}
		else
			ra(a);
	}
}
