/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:39:32 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/07 10:22:06 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !stack->first || !stack->first->next)
		return ;
	first = stack->first;
	second = stack->first->next;
	first->next = second->next;
	second->next = first;
	stack->first = second;
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	stack_a->stock->swap_a += 1;
	stack_a->stock->total += 1;
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	stack_b->stock->swap_b += 1;
	stack_b->stock->total += 1;
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	stack_b->stock->swap_ab += 1;
	stack_b->stock->total += 1;
	ft_printf("ss\n");
}
