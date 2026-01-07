/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:42:52 by flauweri          #+#    #+#             */
/*   Updated: 2026/01/07 14:55:22 by flauweri         ###   ########.fr       */
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

void	put_str_fd(int title, char *str)
{
	int	i;

	i = 0;
	(void)title;
	while (str[i])
		write(2, &str[i++], 1);
}

void	put_nbr_fd(int title, int nbr)
{
	int	c;

	c = 0;
	(void)title;
	if ((nbr / 10) > 0)
		put_nbr_fd(0 ,nbr / 10);
	c = nbr % 10 + '0';
	write(2, &c, 1);
}

void	put_float(int title, float nbr)
{
	int	n;
	
	(void)title;
	n = (int)nbr % 100;
	put_nbr_fd(0, n);
	nbr = (nbr - n) * 100;
	write(2, ".", 1);
	n = (int)nbr % 100;
	put_nbr_fd(0, n);
}

void	benchmark_mode(t_stock stock)
{
	put_float(write(2, "[bench] disorder: ", 19), stock.dissorder);
	put_str_fd(write(2, "%\n[bench] strategy: ", 21), stock.strategy);
	put_str_fd(write(2, " / ", 3), stock.theorical_complexity);
	put_nbr_fd(write(2, "\n[bench] total_ops: ", 20), stock.total);
	put_nbr_fd(write(2, "\n[bench] sa: ", 13), stock.swap_a);
	put_nbr_fd(write(2, " sb: ", 5), stock.swap_b);
	put_nbr_fd(write(2, " ss: ", 5), stock.swap_ab);
	put_nbr_fd(write(2, " pa: ", 5), stock.push_a);
	put_nbr_fd(write(2, " pb: ", 5), stock.push_b);
	put_nbr_fd(write(2, "\n[bench] ra: ", 9), stock.rotate_a);
	put_nbr_fd(write(2, " rb: ", 5), stock.rotate_b);
	put_nbr_fd(write(2, " rr: ", 5), stock.rotate_ab);
	put_nbr_fd(write(2, " rra: ", 6), stock.reverse_rotate_a);
	put_nbr_fd(write(2, " rrb: ", 6), stock.reverse_rotate_b);
	put_nbr_fd(write(2, " rrr: ", 6), stock.reverse_rotate_ab);
}
