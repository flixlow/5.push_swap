/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:37:22 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/05 16:41:28 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptative(t_stack *a, t_stack *b)
{
	double adap;

	adap = compute_disorder(a);
	if (adap < 0.2)
		printpile(a);
	else if (adap <= 0.5)
		chunk_sort(a, b);
	else
		radix_sort(a, b);
}