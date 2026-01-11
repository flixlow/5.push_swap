/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:39:47 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/11 01:44:50 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **receiver, t_list **sender)
{
	t_list	*pushed;

	if (*sender == NULL)
		return ;
	pushed = *sender;
	*sender = (*sender)->next;
	pushed->next = *receiver;
	*receiver = pushed;
}
