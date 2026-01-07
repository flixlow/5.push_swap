/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:42:52 by flauweri          #+#    #+#             */
/*   Updated: 2026/01/07 13:06:49 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_str_fd(int title, char *str, int fd)
{
	int	i;
	while (str[i])
		i++;
	write(fd, &str, i);
}

void	put_float(float nbr)
{
	
}

void	put_nbr_fd(int title, int nbr, int fd)
{
	int	c;

	c = 0;
	if ((nbr / 10) > 0)
		put_nbr_fd(0 ,nbr / 10, fd);
	c = nbr % 10 + '0';
	write(fd, &c, 1);
}

void	benchmark_mode(t_stock stock)
{
	put_nbr_fd(write(2, "[bench] disorder: ", 19), stock.dissorder, 2);
	put_str_fd(write(2, "\n[bench] strategy: ", 20), stock.strategy, 2);
	write(2, "/", 1);
	put_str_fd(stock.theorical_complexity, 2);
	write(2, "\n[bench] total_ops: ", 21);
	put_nbr_fd(stock.total, 2);
	write(2, "\n[bench] sa: ", 14);
	write(2, "sb: ", 4);
	write(2, "ss: ", 4);
	write(2, "pa: ", 4);
	write(2, "pb: ", 4);
	write(2, "rb: ", 4);
	write(2, "rr: ", 4);
	write(2, "rra: ", 4);
	write(2, "rrb: ", 4);
	write(2, "rrr: ", 4);
	write(2, "\n[bench] ra: ", 9);
}

int main(void)
{
	t_stock	stock;

	stock.dissorder = 49.33;
	benchmark_mode(stock);
	return (0);
}