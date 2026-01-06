/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:02:29 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/06 14:29:44 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// int	check_format(const char *str, va_list argptr)
// {
// 	int	count;
// 	int	i;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '%' && str[i + 1])
// 		{
// 			count += format_conversion(str[i + 1], argptr);
// 			i += 2;
// 		}
// 		else
// 		{
// 			count += ft_putchar(str[i]);
// 			i++;
// 		}
// 	}
// 	return (count);
// }

// int	format_conversion(const char c, va_list argptr)
// {
// 	if (c == 'c')
// 		return (ft_char(argptr));
// 	if (c == 's')
// 		return (ft_str(argptr));
// 	if (c == 'd' || c == 'i')
// 		return (ft_digit(argptr));
// 	if (c == '%')
// 		return (ft_putchar('%'));
// 	if (c == 'x')
// 		return (ft_base(argptr));
// 	if (c == 'X')
// 		return (ft_base_lower(argptr));
// 	if (c == 'u')
// 		return (ft_digit_uni(argptr));
// 	if (c == 'p')
// 		return (ft_base_long(argptr));
// 	return (0);
// }
