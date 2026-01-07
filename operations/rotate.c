/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:40:11 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/07 10:21:40 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack *stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !stack->first || !stack->first->next)
		return ;
	first = stack->first;
	last = stack->first;
	while (last->next)
		last = last->next;
	stack->first = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	stack_a->stock->rotate_a += 1;
	stack_a->stock->total += 1;
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	stack_b->stock->rotate_b += 1;
	stack_b->stock->total += 1;
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	stack_a->stock->rotate_ab += 1;
	stack_a->stock->total += 1;
	ft_printf("rr\n");
}
