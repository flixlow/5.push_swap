/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:40:16 by mobenhab          #+#    #+#             */
/*   Updated: 2025/12/31 14:04:45 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("rra\n");
}

void	rrb(t_stack *pile_b)
{
	revrotate(pile_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *pile_a, t_stack *pile_b)
{
	revrotate(pile_a);
	revrotate(pile_b);
	ft_printf("rrr\n");
}
