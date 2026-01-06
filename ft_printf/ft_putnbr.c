/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:13:29 by flauweri          #+#    #+#             */
/*   Updated: 2026/01/06 15:00:14 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
