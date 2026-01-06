/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:56:58 by flauweri          #+#    #+#             */
/*   Updated: 2026/01/06 15:00:18 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_putvoid(void *n)
{
	unsigned long	a;
	int				count;

	count = 0;
	a = (unsigned long)n;
	if (n == NULL)
	{
		s_write(&count, write(1, "(nil)", 5));
		return (count);
	}
	s_write(&count, write(1, "0x", 2));
	s_write(&count, ft_putnbr_base(a));
	return (count);
}
