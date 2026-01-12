/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:06:47 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/12 19:41:20 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix_sort_bits(t_stack *pile_a, t_stack *pile_b, int bit)
{
	int	i;
	int	num;
	int	size;

	size = lstlen(pile_a);
	i = 0;
	while (i < size)
	{
		num = pile_a->first->index;
		if ((num >> bit) & 1)
		{
			ra(pile_a);
		}
		else
		{
			pb(pile_b, pile_a);
		}
		i++;
	}
	while (pile_b->first)
		pa(pile_a, pile_b);
}

void	assign_index(t_stack *pile_a)
{
	t_list	*a;
	int		index;
	t_list	*tmp;

	index = 0;
	a = pile_a->first;
	while (a)
	{
		index = 0;
		tmp = pile_a->first;
		while (tmp)
		{
			if (tmp->content < a->content)
				index++;
			tmp = tmp->next;
		}
		a->index = index;
		a = a->next;
	}
}

void	radix_sort(t_stack *pile_a, t_stack *pile_b)
{
	int	max_index;
	int	bits;
	int	i;

	bits = 0;
	i = 0;
	pile_a->stock->theorical_complexity = "O(n log n)";
	if (!pile_a || !pile_a->first || !pile_a->first->next)
		return ;
	assign_index(pile_a);
	max_index = find_max_index(pile_a);
	while ((max_index >> bits) != 0)
		bits++;
	while (i < bits)
	{
		radix_sort_bits(pile_a, pile_b, i);
		i++;
	}
}
