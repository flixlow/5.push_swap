/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:34:09 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/06 15:49:59 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_last(t_stack *pile_a, t_stack *pile_b, int *size)
{
		pb(pile_b, pile_a);
		rb(pile_b);
		(*size)++;
}

static void	rotation_count(t_stack *pile_a, t_stack *pile_b, int index, int *size)
{
	int	rotation;
	
	rotation = 0;
	if (index < (*size / 2))
	{
		while (rotation++ <= index)
			rb(pile_b);
		pb(pile_b, pile_a);
		while (rotation-- >= 0)
			rrb(pile_b);
	}
	else
	{
		while (rotation++ <= index)
			rrb(pile_b);
		pb(pile_b, pile_a);
		while (rotation-- >= 0)
			rb(pile_b);
	}
}

static void	check_middle(t_stack *pile_a, t_stack *pile_b, int *size)
{
	t_list	*mouv;
	int		index;

	mouv = pile_b->first;
	index = 0;
	while (index < *size)
	{
		if (pile_a->first->content > mouv->content)
		{
			rotation_count(pile_a, pile_b, index, size);
			(*size)++;
			return ;
		}
		index++;
		mouv = mouv->next;
	}
}

void	insertion_sort(t_stack *pile_a, t_stack *pile_b)
{
    t_list *last;
	int		size;

	if (!pile_a || !pile_a->first || !pile_a->first->next)
    	return ;
	pb(pile_b, pile_a);
	last = pile_b->first;
	size = 1;
	while (pile_a->first)
	{
		if (pile_a->first->content > pile_b->first->content)
		{
			pb(pile_b, pile_a);
			size++;
		}
		else if (pile_a->first->content < last->content)
		{
			last = pile_a->first;
			check_last(pile_a, pile_b, &size);
		}
		else
			check_middle(pile_a, pile_b, &size);
	}
	while (pile_b->first)
		pa(pile_a, pile_b);
}

