/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:39:32 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/11 01:21:36 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **pile)
{
	t_list	*first;
	t_list	*second;

	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	first = *pile;
	second = (*pile)->next;
	first->next = second->next;
	second->next = first;
	*pile = second;
}

void	ss(t_list **pile_a, t_list **pile_b)
{
	swap(pile_a);
	swap(pile_b);
}
