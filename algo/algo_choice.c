/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_choice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:58:03 by flauweri          #+#    #+#             */
/*   Updated: 2026/01/09 17:18:20 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_choice(t_stock *stock, t_stack *a, t_stack *b)
{
	stock->dissorder = compute_disorder(a);
	if (stock->strategy != NULL
		&& ft_strcmp(stock->strategy, "simple") == 0)
		insertion_sort(a, b);
	else if (stock->strategy != NULL
		&& ft_strcmp(stock->strategy, "medium") == 0)
		chunk_sort(a, b);
	else if (stock->strategy != NULL
		&& ft_strcmp(stock->strategy, "complex") == 0)
		radix_sort(a, b);
	else
		adaptive(a, b);
}
