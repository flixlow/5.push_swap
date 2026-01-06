/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:13:29 by flauweri          #+#    #+#             */
/*   Updated: 2025/12/05 10:23:44 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		s_write(&count, write(1, "-", 1));
		s_write(&count, ft_putnbr_un(n * (-1)));
	}
	else
		s_write(&count, ft_putnbr_un(n));
	return (count);
}
