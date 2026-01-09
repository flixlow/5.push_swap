/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:18:45 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/09 17:15:41 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stock	stock;
	int		begin;

	begin = 1;
	if (ac <= 1)
		return (0);
	a = createpile();
	b = createpile();
	a->stock = &stock;
	b->stock = &stock;
	ft_memset(&stock, 0, sizeof(t_stock));
	if (check_args(av, &stock, &begin) == 1)
		return (ft_error(a, b, &stock));
	if (stock.tab != NULL)
	{
		if (init_stack(a, stock.tab) == 1)
			return (ft_error(a, b, &stock));
	}
	else if (stock.tab == NULL)
	{
		if (init_stack(a, &av[begin]) == 1)
			return (ft_error(a, b, &stock));
	}
	if (is_sorted(a))
		return (ft_printf("already sorted\n"));
	algo_choice(&stock, a, b);
	if (stock.bench != NULL)
		benchmark_mode(&stock);
	freeall(a, b, &stock);
}
