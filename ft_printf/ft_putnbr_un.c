/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:13:29 by flauweri          #+#    #+#             */
/*   Updated: 2025/12/05 10:20:11 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_un(unsigned int n)
{
	int	count;
	int	m;

	count = 0;
	if ((n / 10) > 0)
		count = ft_putnbr_un(n / 10);
	m = n % 10 + '0';
	s_write(&count, write(1, &(m), 1));
	return (count);
}
