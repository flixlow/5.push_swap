/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:06:47 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/05 20:11:12 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	radix_sort(t_stack *pile_a, t_stack *pile_b)
{
	int	max_index;
	int	bits;
	int	i;

	bits = 0;
	i = 0;
	if (!pile_a || !pile_a->first || !pile_a->first->next)
		return ;
	assign_index(pile_a);
	max_index = find_max_index(pile_a);
	while ((max_index >> bits) != 0)
		bits++;
	while (i < bits)
	{
		radix_sort_bits(pile_a, pile_b, i);
		i++;
	}
}

void	radix_sort_bits(t_stack *pile_a, t_stack *pile_b, int bit)
{
	int	i;
	int	num;
	int	size;

	size = lstlen(pile_a); // taille initiale
	i = 0;
	while (i < size)
	{
		num = pile_a->first->index;
		if ((num >> bit) & 1)
		{
			ra(pile_a);
		}
		else
		{
			pb(pile_b, pile_a);
		}
		i++;
	}
	while (pile_b->first)
		pa(pile_a, pile_b); // remettre pile_b dans pile_a
}

void	assign_index(t_stack *pile_a)
{
	t_list	*a;
	int		index;
	t_list	*tmp;

	index = 0;
	a = pile_a->first;
	while (a)
	{
		index = 0;
		tmp = pile_a->first;
		while (tmp)
		{
			if (tmp->content < a->content)
				index++;
			tmp = tmp->next;
		}
		a->index = index;
		a = a->next;
	}
}

// int	main(void)
// {
// 	// création de quelques nœuds
// t_stack pile_a;
// t_stack pile_b;

// // Remplir pile_a avec des valeurs
// push(&pile_a, 5);
// push(&pile_a, 1);
// push(&pile_a, 3);
// push(&pile_a, 2);
// push(&pile_a, 4);

// printf("Avant tri :\n");
// lprint_stack(&pile_a);

// radix_sort(&pile_a, &pile_b);

// printf("Après tri :\n");
// lprint_stack(&pile_a);
// }