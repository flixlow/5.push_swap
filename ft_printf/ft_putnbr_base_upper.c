/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_upper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:31:52 by flauweri          #+#    #+#             */
/*   Updated: 2026/01/06 15:00:09 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_putnbr_base_upper(unsigned int n)
{
	int		count;
	char	*str;

	count = 0;
	str = "0123456789ABCDEF";
	if ((n / 16) > 0)
		count = ft_putnbr_base_upper(n / 16);
	s_write(&count, write(1, &str[n % 16], 1));
	return (count);
}
