/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_upper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:31:52 by flauweri          #+#    #+#             */
/*   Updated: 2025/12/05 10:26:41 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
