/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:06:47 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/13 12:16:06 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix_sort_bits(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int	i;
	int	num;
	int	size;

	size = lstlen(stack_a);
	i = 0;
	while (i < size)
	{
		num = stack_a->first->index;
		if ((num >> bit) & 1)
		{
			ra(stack_a);
		}
		else
		{
			pb(stack_b, stack_a);
		}
		i++;
	}
	while (stack_b->first)
		pa(stack_a, stack_b);
}

void	assign_index(t_stack *stack_a)
{
	t_list	*a;
	int		index;
	t_list	*tmp;

	index = 0;
	a = stack_a->first;
	while (a)
	{
		index = 0;
		tmp = stack_a->first;
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

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_index;
	int	bits;
	int	i;

	bits = 0;
	i = 0;
	stack_a->stock->theorical_complexity = "O(n log n)";
	if (!stack_a || !stack_a->first || !stack_a->first->next)
		return ;
	assign_index(stack_a);
	max_index = find_max_index(stack_a);
	while ((max_index >> bits) != 0)
		bits++;
	while (i < bits)
	{
		radix_sort_bits(stack_a, stack_b, i);
		i++;
	}
}
