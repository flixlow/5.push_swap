/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:40:11 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/11 00:47:24 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **pile)
{
	t_list	*first;
	t_list	*last;

	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	first = *pile;
	last = *pile;
	while (last->next)
		last = last->next;
	*pile = (*pile)->next;
	last->next = first;
	first->next = NULL;
}

void	rr(t_list **pile_a, t_list **pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
}
