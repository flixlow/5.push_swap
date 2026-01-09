/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:56:55 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/09 17:39:25 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_error(t_stack *a, t_stack *b, t_stock *stock)
{
	freepile(a);
	freepile(b);
	(void)stock;
	write(2, "Error\n", 6);
	return (0);
}

void	freeall(t_stack *a, t_stack *b, t_stock *stock)
{
	freepile(a);
	freepile(b);
	(void)stock;
}

void	freestock(t_stock *stock)
{
	if (stock->bench != NULL)
		free(stock->bench);
	else if (stock->strategy != NULL)
		free(stock->strategy);
	else if (stock->theorical_complexity != NULL)
		free(stock->theorical_complexity);
}

