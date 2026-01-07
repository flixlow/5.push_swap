/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:37:22 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/07 10:56:42 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptive(t_stack *a, t_stack *b)
{
	a->stock->dissorder = compute_disorder(a);
	if (a->stock->dissorder < 0.2)
		insertion_sort(a, b);
	else if (a->stock->dissorder >= 0.2 && a->stock->dissorder < 0.5)
		chunk_sort(a, b);
	else if (a->stock->dissorder >= 0.5)
		radix_sort(a, b);
}
