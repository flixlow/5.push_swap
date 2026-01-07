/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:29:40 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/07 10:05:41 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*createpile(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->first = NULL;
	return (stack);
}

void	printpile(t_stack *stack)
{
	t_list	*element;

	if (!stack)
		return ;
	element = stack->first;
	while (element)
	{
		ft_printf("%d", element->content);
		ft_printf("\n");
		element = element->next;
	}
}

void	freepile(t_stack *stack)
{
	t_list	*current;
	t_list	*next;

	if (!stack)
		return ;
	current = stack->first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

double	compute_disorder(t_stack *stack)
{
	t_list	*i;
	t_list	*j;
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	if (!stack || !stack->first)
		return (0.0);
	i = stack->first;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			total_pairs++;
			if (i->content < j->content)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

void	init_stack(t_stack *a, char **av, size_t len)
{
	t_list	*new;
	t_list	*last;

	last = NULL;
	while (av[len])
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return ;
		new->content = ft_atoi(av[len]);
		new->index = 0;
		new->next = NULL;
		if (!a->first)
			a->first = new;
		else
			last->next = new;
		last = new;
		len++;
	}
}
