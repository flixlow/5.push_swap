/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:18:45 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/12 18:09:11 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile(t_stack *pile)
{
	t_list	*tmp;

	tmp = pile->first;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}

int	sorted_free(t_stack *a, t_stack *b)
{
	freepile(a);
	freepile(b);
	return (0);
}

int	init(t_stack *a, t_stack *b, char **av)
{
	int	begin;

	begin = 1;
	ft_memset(a->stock, 0, sizeof(t_stock));
	if (check_args(av, a->stock, &begin) == 1)
		return (ft_error(a, b, a->stock));
	if (a->stock->tab != NULL && init_stack(a, a->stock->tab) == 1)
	{
		ft_free(a->stock->tab);
		return (ft_error(a, b, a->stock));
	}
	if ((a->stock->tab == NULL && init_stack(a, &av[begin]) == 1))
		return (ft_error(a, b, a->stock));
	if (has_duplicates(a) || lstlen(a) < 2)
		return (ft_error(a, b, a->stock));
	if (a->stock->tab)
		ft_free(a->stock->tab);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stock	stock;

	if (ac <= 1)
		return (0);
	a = createpile();
	b = createpile();
	a->stock = &stock;
	b->stock = &stock;
	if (init(a, b, av))
		return (0);
	if (is_sorted(a))
		return (sorted_free(a, b));
	algo_choice(&stock, a, b);
	if (stock.bench != NULL)
		benchmark_mode(&stock);
	freeall(a, b, &stock);
	return (0);
}
