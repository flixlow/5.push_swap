/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:23:11 by mobenhab          #+#    #+#             */
/*   Updated: 2025/12/10 14:28:16 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		i++;
	return (write(1, str, i));
}

int	ft_char(va_list argptr)
{
	int		count;
	char	c;

	count = 0;
	c = va_arg(argptr, int);
	count = ft_putchar(c);
	return (count);
}

int	ft_str(va_list argptr)
{
	int		count;
	char	*str;

	count = 0;
	str = va_arg(argptr, char *);
	count = ft_putstr(str);
	return (count);
}
