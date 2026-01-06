/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:37:22 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/06 18:51:49 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptative(t_stack *a, t_stack *b, t_stock *stock)
{
	stock->dissorder = compute_disorder(a);
	if (stock->dissorder < 0.2)
		insertion_sort(a, b, stock);
	else if (stock->dissorder >= 0.2 && stock->dissorder < 0.5)
		chunk_sort(a, b);
	else if (stock->dissorder >= 0.5)
		radix_sort(a, b);
}
