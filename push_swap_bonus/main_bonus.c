/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:18:45 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/12 17:37:52 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_list	*pile_a;
	t_list	*pile_b;
	char	*operation;

	pile_b = NULL;
	operation = NULL;
	if (ac <= 1)
		return (0);
	if (init(av, &pile_a, &pile_b))
		return (0);
	operation = get_next_line(0);
	while (operation)
	{
		if (operation_on_pile(&operation, &pile_a, &pile_b))
			return (0);
		free(operation);
		operation = get_next_line(0);
	}
	if (is_sorted(pile_a) && pile_b == NULL)
		return (freeall(&pile_a, &pile_b, "OK\n"));
	return (freeall(&pile_a, &pile_b, "KO\n"));
}
