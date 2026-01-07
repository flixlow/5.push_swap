/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:18:45 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/07 13:51:19 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    t_stock stock;

    if (ac < 2)
        return (0);
    ft_memset(&stock, 0, 12);
    a = createpile();
    b = createpile();
    init_stack(a, &av[0], 1);
    a->stock = &stock;
    b->stock = &stock;
    printpile(a);
    adaptive(a, b);
    printpile(a);
    benchmark_mode(stock);
    //ft_printf("%d", stock.total);
}
