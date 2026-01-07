/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:42:52 by flauweri          #+#    #+#             */
/*   Updated: 2026/01/07 11:16:06 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_float(float nbr)
{
	
}

void	put_nbr_fd(int	nbr)
{
	int	c;

	c = 0;
	if ((nbr / 10) > 0)
		put_nbr_fd(nbr / 10);
	c = nbr % 10 + '0';
	write(2, &c, 1);
}

void	benchmark_mode(t_stock stock)
{
	write(2, "[bench] disorder: ", 19);
	put_nbr_fd(stock.dissorder);
	write(2, "\n[bench] strategy: ", 20);
	
	write(2, "\n[bench] total_ops: ", 21);
	write(2, "\n[bench] sa: ", 14);
	write(2, "\n[bench]", 9);
}

int main(void)
{
	t_stock	stock;

	stock.dissorder = 49.33;
	benchmark_mode(stock);
	return (0);
}