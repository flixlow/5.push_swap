/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:56:58 by flauweri          #+#    #+#             */
/*   Updated: 2025/12/05 10:24:21 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
