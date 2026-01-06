/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:37:22 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/06 17:37:18 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptative(t_stack *a, t_stack *b)
{
	double	adap;

	adap = compute_disorder(a);
	if (adap < 0.2)
		insertion_sort(a,b);
	else if (adap >= 0.2 && adap < 0.5)
		chunk_sort(a, b);
	else if (adap >= 0.5)
		radix_sort(a, b);
}
