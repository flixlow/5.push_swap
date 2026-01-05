/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:34:09 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/03 19:26:42 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_top(t_stack *pile_a, t_stack *pile_b, int *stack_size)
{
	pb(pile_b, pile_a);
	(*stack_size)++;
}

void	check_last(t_stack *pile_a, t_stack *pile_b, int *stack_size, t_list **last)
{
		*last = pile_a->first;
		pb(pile_b, pile_a);
		rb(pile_b);
		(*stack_size)++;
}

void	check_middle(t_stack *pile_a, t_stack *pile_b, int *stack_size)
{
	t_list	*mouv;
	int		rotation;

	mouv = pile_b->first;
	rotation = 0;
	while (mouv->next != NULL)
	{
		if (pile_a->first->content > mouv->content)
		{
			if (mouv->index <= (*stack_size / 2))
			{
				while (rotation++ <= mouv->index)
					rb(pile_b);
				pb(pile_b, pile_a);
				while (rotation-- > 0)
					rrb(pile_b);
			}
			else
			{
				while (rotation++ <= mouv->index)
					rrb(pile_b);
				pb(pile_b, pile_a);
				while (rotation-- > 0)
					rb(pile_b);
			}
			(*stack_size)++;
			return ;
		}
		mouv = mouv->next;
	}
}

void	ft_insertion(t_stack *pile_a, t_stack *pile_b)
{
    t_list *last;
	int		stack_size;

	if (!pile_a || !pile_a->first || !pile_a->first->next)
    	return ;
	pb(pile_b, pile_a);
	last = pile_b->first;
	stack_size = 1;
	while (pile_a->first)
	{
		if (pile_a->first->content > pile_b->first->content)
			check_top(pile_a, pile_b, &stack_size);
		else if (pile_a->first->content < last->content)
			check_last(pile_a, pile_b, &stack_size, &last);
		else
			check_middle(pile_a, pile_b, &stack_size);
	}
	while (pile_b->first)
		pa(pile_a, pile_b);
}

