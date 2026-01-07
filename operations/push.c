/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:39:47 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/07 10:20:46 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *stack, int new)
{
	t_list	*newelem;

	if (!stack)
		return ;
	newelem = malloc(sizeof(t_list));
	if (!newelem)
		return ;
	newelem->content = new;
	newelem->next = stack->first;
	stack->first = newelem;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*top;

	if (!stack_a || !stack_b || !stack_b->first)
		return ;
	top = stack_b->first;
	stack_b->first = top->next;
	top->next = stack_a->first;
	stack_a->first = top;
	stack_a->stock->push_a += 1;
	stack_a->stock->total += 1;
	ft_printf("pa\n");
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	t_list	*top;

	if (!stack_a || !stack_a->first)
		return ;
	top = stack_a->first;
	stack_a->first = top->next;
	top->next = stack_b->first;
	stack_b->first = top;
	stack_a->stock->push_b += 1;
	stack_a->stock->total += 1;
	ft_printf("pb\n");
}
