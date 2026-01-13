/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:56:55 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/13 12:22:23 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	freestack(t_list **stack)
{
	t_list	*current;
	t_list	*next;

	if (*stack == NULL)
		return (1);
	current = (*stack)->next;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(*stack);
	return (1);
}

int	ft_error(t_list **stack_a, t_list **stack_b, char **op)
{
	freestack(stack_a);
	freestack(stack_b);
	if (*op)
		free(*op);
	write(2, "Error\n", 6);
	return (1);
}

int	freeall(t_list **stack_a, t_list **stack_b, char *oko)
{
	int	i;

	i = 0;
	freestack(stack_a);
	freestack(stack_b);
	while (oko && oko[i])
		write(1, &oko[i++], 1);
	return (1);
}

int	has_duplicates(t_list *stack)
{
	t_list	*i;
	t_list	*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->content == j->content)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	is_sorted(t_list *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
