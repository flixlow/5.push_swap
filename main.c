/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:18:45 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/06 15:03:38 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	// int		size;
	// int		chunk;
	// int		*arr;

	if (ac < 2)
		return (0);
	a = creatpile();
	b = creatpile();
	// 1 Initialiser la pile A depuis argv
	init_stack(a, av, 1);
	// printpile(a);
	// 2 Si déjà trié → rien à faire
	if (is_sorted(a))
	{
		ft_printf("Pile déjà triée\n");
		freepile(a);
		freepile(b);
		return (0);
	}

	ft_printf("pile a\n");
	printpile(a);
	ft_printf("pile b\n");
	printpile(b);
	radix_sort(a,b);
	ft_printf("Résultat final\n");
	printpile(a);
	printpile(b);
	freepile(b);
	freepile(a);
	return (0);
}