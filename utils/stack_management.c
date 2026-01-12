/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:29:40 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/12 18:10:59 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*createpile(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->first = NULL;
	return (stack);
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

float	compute_disorder(t_stack *stack)
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
			if (i->content > j->content)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((float)mistakes / (float)total_pairs);
}

int	check_overflow(int content, char *str)
{
	char	*new_str;

	new_str = ft_itoa(content);
	if (str[0] == '+')
		str++;
	if (ft_strcmp(new_str, str) != 0)
	{
		free(new_str);
		return (1);
	}
	free(new_str);
	return (0);
}

int	init_stack(t_stack *a, char **av)
{
	t_list	*new;
	t_list	*last;
	size_t	i;

	i = 0;
	last = NULL;
	while (av[i])
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (1);
		new->content = ft_atoi(av[i]);
		new->index = 0;
		new->next = NULL;
		if (!a->first)
			a->first = new;
		else
			last->next = new;
		last = new;
		if (check_overflow(new->content, av[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
