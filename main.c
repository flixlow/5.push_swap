/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:18:45 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/07 17:40:21 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stock	stock;
	int	begin;	

	begin = 0;
	if (ac <= 2)
		return (write(2, "Error\n", 6));
	a = createpile();
	b = createpile();
	a->stock = &stock;
	b->stock = &stock;
	ft_memset(&stock, 0, 48);
	if (check_args(av, &stock, &begin) == 1)
		return (write(2, "Error\n", 6));
	init_stack(a, &av[begin], 1);
	printpile(a);
	adaptive(a, b);
	printpile(a);
	if (ft_strcmp(stock.bench, "bench") == 0)
		benchmark_mode(stock);
}

// int	main(int ac, char **av)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	// int		size;
// 	// int		chunk;
// 	// int		*arr;

// 	if (ac < 2)
// 		return (0);
// 	a = creatpile();
// 	b = creatpile();
// 	// 1 Initialiser la pile A depuis argv
// 	init_stack(a, av, 1);
// 	// printpile(a);
// 	// 2 Si déjà trié → rien à faire
// 	if (is_sorted(a))
// 	{
// 		ft_printf("Pile déjà triée\n");
// 		freepile(a);
// 		freepile(b);
// 		return (0);
// 	}

// 	ft_printf("pile a\n");
// 	printpile(a);
// 	ft_printf("pile b\n");
// 	printpile(b);
// 	radix_sort(a,b);
// 	ft_printf("Résultat final\n");
// 	printpile(a);
// 	printpile(b);
// 	freepile(b);
// 	freepile(a);
// 	return (0);
// }
