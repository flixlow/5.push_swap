/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:40:16 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/13 12:18:11 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	revrotate(t_stack *stack)
{
	t_list	*last;
	t_list	*befor_last;

	if (!stack || !stack->first || !stack->first->next)
		return ;
	last = stack->first;
	befor_last = NULL;
	while (last->next)
	{
		befor_last = last;
		last = last->next;
	}
	befor_last->next = NULL;
	last->next = stack->first;
	stack->first = last;
}

void	rra(t_stack *stack_a)
{
	revrotate(stack_a);
	stack_a->stock->reverse_rotate_a += 1;
	stack_a->stock->total += 1;
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	revrotate(stack_b);
	stack_b->stock->reverse_rotate_b += 1;
	stack_b->stock->total += 1;
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	revrotate(stack_a);
	revrotate(stack_b);
	stack_a->stock->reverse_rotate_ab += 1;
	stack_a->stock->total += 1;
	ft_printf("rrr\n");
}
