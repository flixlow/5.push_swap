/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:18:45 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/11 02:26:25 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_on_pile(char *operation, t_list **pile_a, t_list **pile_b)
{
	if (ft_strcmp(operation, "pa\n") == 0)
		push(pile_a, pile_b);
	else if (ft_strcmp(operation, "pb\n") == 0)
		push(pile_b, pile_a);
	else if (ft_strcmp(operation, "sa\n") == 0)
		swap(pile_a);
	else if (ft_strcmp(operation, "sb\n") == 0)
		swap(pile_b);
	else if (ft_strcmp(operation, "ss\n") == 0)
		ss(pile_a, pile_b);
	else if (ft_strcmp(operation, "ra\n") == 0)
		rotate(pile_a);
	else if (ft_strcmp(operation, "rb\n") == 0)
		rotate(pile_b);
	else if (ft_strcmp(operation, "rr\n") == 0)
		rr(pile_a, pile_b);
	else if (ft_strcmp(operation, "rra\n") == 0)
		revrotate(pile_a);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		revrotate(pile_b);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		rrr(pile_a, pile_b);
	else
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*pile_a;
	t_list	*pile_b;
	char	**tab;
	char	*operation;

	pile_a = NULL;
	pile_b = NULL;
	if (ac <= 1)
		return (0);
	if (av[2] == NULL)
		tab = ft_split(av[1], ' ');
	else
		tab = av + 1;
	if (!tab[1] || check_digits(tab) || init_pile(&pile_a, tab) || has_duplicates(pile_a))
		return (ft_error(&pile_a, &pile_b));
	if (is_sorted(pile_a))
		return (write(1, "already sorted\n", 15));
	operation = get_next_line(0);
	while (operation)
	{
		if (operation_on_pile(operation, &pile_a, &pile_b))
			return (ft_error(&pile_a, &pile_b));
		free(operation);
		operation = get_next_line(0);
	}
	if (!(tab == av + 1))
		ft_free_tab(tab);
	if (is_sorted(pile_a) && pile_b == NULL)
		write(1, "OK\n", 3);
	else
		return (write(1, "KO\n", 3));
	freeall(&pile_a, &pile_b);
}
