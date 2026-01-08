/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:18:45 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/08 17:54:07 by flauweri         ###   ########.fr       */
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
	if (ac <= 2)
		return (write(2, "Error\n", 6));
	a = createpile();
	b = createpile();
	a->stock = &stock;
	b->stock = &stock;
	ft_memset(&stock, 0, sizeof(t_stock));
	if (check_args(av, &stock, &begin) == 1)
		return (ft_error(a, b, &stock));
	if (init_stack(a, &av[begin]) == 1)
		return (ft_error(a, b, &stock));
	if (is_sorted(a))
		return(ft_printf("bon\n"));
	algo_choice(&stock, a, b);
	__builtin_printf("%.2f\n", stock.dissorder * 100);
	if (stock.bench != NULL)
		benchmark_mode(&stock);
	freeall(a, b, &stock);
}
