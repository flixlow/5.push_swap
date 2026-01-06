/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:34:09 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/06 10:11:19 by flauweri         ###   ########.fr       */
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

void	rotation_count(t_stack *pile_a, t_stack *pile_b, void *f, void *g)
{
	int	rotation;
	
	rotation = 0;
	while (rotation++ <= mouv->index)
		f(pile_b);
	pb(pile_b, pile_a);
	while (rotation-- > 0)
		g(pile_b);
}

void	check_middle(t_stack *pile_a, t_stack *pile_b, int *stack_size)
{
	t_list	*mouv;

	mouv = pile_b->first;
	while (mouv->next != NULL)
	{
		if (pile_a->first->content > mouv->content)
		{
			if (mouv->index <= (*stack_size / 2))
				rotation_count(pile_a, pile_b, rb, rrb);
			else
				rotation_count(pile_a, pile_b, rrb, rb);
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

//main pour tester
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*pile_a;
	t_stack	*pile_b;

	if (argc < 2)
		return (0);

	init_stack(pile_a, argv, 1);
	pile_b->first = NULL;

	printpile(pile_a);
	printpile(pile_b);

	ft_insertion(pile_a, pile_b);

	printpile(pile_a);
	printpile(pile_b);

	return (0);
}
