/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:29:40 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/04 13:26:06 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*creatpile(void)
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
	ft_printf("\n");
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

void	init_stack(t_stack *a, char **av)
{
	int		i;
	t_list	*new;
	t_list	*last;

	i = 1;
	last = NULL;
	while (av[i])
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return ;
		new->content = ft_atoi(av[i]);
		new->index = 0;
		new->next = NULL;
		if (!a->first)
			a->first = new;
		else
			last->next = new;
		last = new;
		i++;
	}
}
