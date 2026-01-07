/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:42:52 by flauweri          #+#    #+#             */
/*   Updated: 2026/01/07 13:43:33 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = (char)c;
	return (s);
}

void	put_str_fd(int title, char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
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
	put_str_fd(write(2, " / ", 3), stock.theorical_complexity, 2);
	put_nbr_fd(write(2, "\n[bench] total_ops: ", 20), stock.total, 2);
	put_nbr_fd(write(2, "\n[bench] sa: ", 13), stock.swap_a, 2);
	put_nbr_fd(write(2, " sb: ", 5), stock.swap_b, 2);
	put_nbr_fd(write(2, " ss: ", 5), stock.swap_ab, 2);
	put_nbr_fd(write(2, " pa: ", 5), stock.push_a, 2);
	put_nbr_fd(write(2, " pb: ", 5), stock.push_b, 2);
	put_nbr_fd(write(2, "\n[bench] ra: ", 9), stock.rotate_a, 2);
	put_nbr_fd(write(2, " rb: ", 5), stock.rotate_b, 2);
	put_nbr_fd(write(2, " rr: ", 5), stock.rotate_ab, 2);
	put_nbr_fd(write(2, " rra: ", 6), stock.reverse_rotate_a, 2);
	put_nbr_fd(write(2, " rrb: ", 6), stock.reverse_rotate_b, 2);
	put_nbr_fd(write(2, " rrr: ", 6), stock.reverse_rotate_ab, 2);
}

int main(void)
{
	t_stock	stock;

	stock.dissorder = 49.33;
	ft_memset(&stock, 0, 48);
	stock.strategy = "adaptive";
	stock.theorical_complexity = "O(nlogn)";
	benchmark_mode(stock);
	return (0);
}