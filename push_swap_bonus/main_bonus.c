/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:18:45 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/13 12:24:58 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*operation;

	stack_b = NULL;
	operation = NULL;
	if (ac <= 1)
		return (0);
	if (init(av, &stack_a, &stack_b))
		return (0);
	operation = get_next_line(0);
	while (operation)
	{
		if (operation_on_stack(&operation, &stack_a, &stack_b))
			return (0);
		free(operation);
		operation = get_next_line(0);
	}
	if (is_sorted(stack_a) && stack_b == NULL)
		freeall(&stack_a, &stack_b, "OK\n");
	else
		return (freeall(&stack_a, &stack_b, "KO\n"));
	return (0);
}
