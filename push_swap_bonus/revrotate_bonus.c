/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:40:16 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/13 12:25:29 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	revrotate(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	revrotate(stack_a);
	revrotate(stack_b);
}
