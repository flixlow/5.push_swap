/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:13:29 by flauweri          #+#    #+#             */
/*   Updated: 2026/01/06 15:00:11 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
