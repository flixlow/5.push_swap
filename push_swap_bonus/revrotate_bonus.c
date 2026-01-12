/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:40:16 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/12 11:20:48 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrotate(t_list **pile)
{
	t_list	*last;
	t_list	*before_last;

	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	last = *pile;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *pile;
	*pile = last;
}

void	rrr(t_list **pile_a, t_list **pile_b)
{
	revrotate(pile_a);
	revrotate(pile_b);
}
