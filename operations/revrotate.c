/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:40:16 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/07 10:21:16 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	revrotate(t_stack *pile)
{
	t_list	*last;
	t_list	*befor_last;

	if (!pile || !pile->first || !pile->first->next)
		return ;
	last = pile->first;
	befor_last = NULL;
	while (last->next)
	{
		befor_last = last;
		last = last->next;
	}
	befor_last->next = NULL;
	last->next = pile->first;
	pile->first = last;
}

void	rra(t_stack *pile_a)
{
	revrotate(pile_a);
	pile_a->stock->reverse_rotate_a += 1;
	pile_a->stock->total += 1;
	ft_printf("rra\n");
}

void	rrb(t_stack *pile_b)
{
	revrotate(pile_b);
	pile_b->stock->reverse_rotate_b += 1;
	pile_b->stock->total += 1;
	ft_printf("rrb\n");
}

void	rrr(t_stack *pile_a, t_stack *pile_b)
{
	revrotate(pile_a);
	revrotate(pile_b);
	pile_a->stock->reverse_rotate_ab += 1;
	pile_a->stock->total += 1;
	ft_printf("rrr\n");
}
