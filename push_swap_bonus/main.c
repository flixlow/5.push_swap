/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:18:45 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/12 11:37:34 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*pile_a;
	t_list	*pile_b;
	char	**tab;
	char	*operation;

	pile_b = NULL;
	tab = NULL;
	if (init(ac, av, &tab, &pile_a))
		return (ft_error(&pile_a, &pile_b, "Error\n"));
	if (is_sorted(pile_a))
		return (ft_error(&pile_a, &pile_b, "Already sorted\n"));
	operation = get_next_line(0);
	while (operation)
	{
		if (operation_on_pile(operation, &pile_a, &pile_b))
			return (ft_error(&pile_a, &pile_b, "Error\n"));
		free(operation);
		operation = get_next_line(0);
	}
	if (is_sorted(pile_a) && pile_b == NULL)
		write(1, "OK\n", 3);
	else
		return (write(1, "KO\n", 3));
	freeall(&pile_a, &pile_b, &tab, av);
}
