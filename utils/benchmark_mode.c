/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:42:52 by flauweri          #+#    #+#             */
/*   Updated: 2026/01/12 18:06:36 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = (char)c;
	return (s);
}

void	put_str_fd(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i])
		write(2, &str1[i++], 1);
	i = 0;
	while (str2[i])
		write(2, &str2[i++], 1);
}

void	put_nbr_fd(char	*str, int nbr)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	if (str != NULL)
	{
		while (str[i])
			write(2, &str[i++], 1);
	}
	if ((nbr / 10) > 0)
		put_nbr_fd(0, nbr / 10);
	c = nbr % 10 + '0';
	write(2, &c, 1);
}

int	put_float(char *str, float nbr)
{
	int	i;
	int	n;

	i = 0;
	if (str)
	{
		while (str[i])
			write(2, &str[i++], 1);
	}
	if (nbr == 0)
		return (write(2, "00.00", 5));
	if (nbr == 100)
		return (write(2, "100.00", 6));
	n = (int)nbr % 100;
	put_nbr_fd(NULL, n);
	write(2, ".", 1);
	nbr = (nbr - n) * 100;
	if (n < 10)
		write(2, "0", 1);
	put_nbr_fd(NULL, (int)nbr);
	return (0);
}

void	benchmark_mode(t_stock *stock)
{
	put_float("[bench] disorder: ", (stock->dissorder * 100));
	put_str_fd("%\n[bench] strategy: ", stock->strategy);
	put_str_fd(" / ", stock->theorical_complexity);
	put_nbr_fd("\n[bench] total_ops: ", stock->total);
	put_nbr_fd("\n[bench] sa: ", stock->swap_a);
	put_nbr_fd(" sb: ", stock->swap_b);
	put_nbr_fd(" ss: ", stock->swap_ab);
	put_nbr_fd(" pa: ", stock->push_a);
	put_nbr_fd(" pb: ", stock->push_b);
	put_nbr_fd("\n[bench] ra: ", stock->rotate_a);
	put_nbr_fd(" rb: ", stock->rotate_b);
	put_nbr_fd(" rr: ", stock->rotate_ab);
	put_nbr_fd(" rra: ", stock->reverse_rotate_a);
	put_nbr_fd(" rrb: ", stock->reverse_rotate_b);
	put_nbr_fd(" rrr: ", stock->reverse_rotate_ab);
	write(2, "\n", 1);
}
