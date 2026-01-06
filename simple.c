/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:34:09 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/06 13:17:50 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_top(t_stack *pile_a, t_stack *pile_b, int *size)
{
	pb(pile_b, pile_a);
	(*size)++;
}

void	check_last(t_stack *pile_a, t_stack *pile_b, int *size)
{
		pb(pile_b, pile_a);
		rb(pile_b);
		(*size)++;
}

void	rotation_count(t_stack *pile_a, t_stack *pile_b, int index, int *size)
{
	int	rotation;
	
	rotation = 0;
	if (index <= (*size / 2))
	{
		while (rotation++ < index)
			rb(pile_b);
		pb(pile_b, pile_a);
		while (--rotation >= 0)
			rrb(pile_b);
	}
	else
	{
		while (rotation++ < index)
			rrb(pile_b);
		pb(pile_b, pile_a);
		while (rotation-- >= 0)
			rb(pile_b);
	}
}

void	check_middle(t_stack *pile_a, t_stack *pile_b, int *size)
{
	t_list	*mouv;
	int		index;

	mouv = pile_b->first;
	while (mouv->next != NULL)
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

void	ft_insertion(t_stack *pile_a, t_stack *pile_b)
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
			check_top(pile_a, pile_b, &size);
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

//main pour tester
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*pile_a;
	t_stack	*pile_b;

	if (argc < 2)
		return (0);
	pile_a = creatpile();
    pile_b = creatpile();
    if (!pile_a || !pile_b)
        return (1);
	pile_a->first = NULL;	
	init_stack(pile_a, argv, 1);
	pile_b->first = NULL;

	printpile(pile_a);
	printpile(pile_b);

	ft_insertion(pile_a, pile_b);

	printpile(pile_a);
	printpile(pile_b);

	freepile(pile_a);
	freepile(pile_b);
	return (0);
}
