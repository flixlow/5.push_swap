/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:34:09 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/13 12:17:21 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_last(t_stack *stack_a, t_stack *stack_b, int *size)
{
	pb(stack_b, stack_a);
	rb(stack_b);
	(*size)++;
}

static void	rotation_count(t_stack *stack_a, t_stack *stack_b, int i, int *size)
{
	int	rotation;

	rotation = 0;
	if (i < (*size / 2))
	{
		while (rotation++ < i)
			rb(stack_b);
		pb(stack_b, stack_a);
		while (--rotation > 0)
			rrb(stack_b);
	}
	else
	{
		rotation = *size;
		while (rotation-- > i)
			rrb(stack_b);
		pb(stack_b, stack_a);
		while (rotation++ < *size)
			rb(stack_b);
	}
}

static void	check_middle(t_stack *stack_a, t_stack *stack_b, int *size)
{
	t_list	*mouv;
	int		index;

	mouv = stack_b->first;
	index = 0;
	while (index < *size)
	{
		if (stack_a->first->content > mouv->content)
		{
			rotation_count(stack_a, stack_b, index, size);
			(*size)++;
			return ;
		}
		index++;
		mouv = mouv->next;
	}
}

void	insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*last;
	int		size;

	stack_a->stock->theorical_complexity = "O(n^2)";
	pb(stack_b, stack_a);
	last = stack_b->first;
	size = 1;
	while (stack_a->first)
	{
		if (stack_a->first->content >= stack_b->first->content)
		{
			pb(stack_b, stack_a);
			size++;
		}
		else if (stack_a->first->content < last->content)
		{
			last = stack_a->first;
			check_last(stack_a, stack_b, &size);
		}
		else
			check_middle(stack_a, stack_b, &size);
	}
	while (stack_b->first)
		pa(stack_a, stack_b);
}
