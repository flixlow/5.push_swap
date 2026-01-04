/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:46:34 by mobenhab          #+#    #+#             */
/*   Updated: 2025/12/10 14:28:09 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putnbr(int n)
{
	int		count;
	long	nb;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_putnbrbase(unsigned int nbr)
{
	unsigned long	nb;
	int				count;
	char			*hex;

	hex = "0123456789abcdef";
	count = 0;
	nb = nbr;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 16)
		count += ft_putnbrbase(nb / 16);
	count += ft_putchar(hex[nb % 16]);
	return (count);
}

int	ft_putnbrbase_lower(unsigned int nbr)
{
	unsigned long	nb;
	int				count;
	char			*hex;

	hex = "0123456789ABCDEF";
	count = 0;
	nb = nbr;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 16)
		count += ft_putnbrbase_lower(nb / 16);
	count += ft_putchar(hex[nb % 16]);
	return (count);
}

int	ft_putnbr_uni(unsigned int n)
{
	int				count;
	unsigned long	nb;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_putnbrbase_long(unsigned long nbr)
{
	unsigned long	nb;
	int				count;
	char			*hex;

	hex = "0123456789abcdef";
	count = 0;
	nb = nbr;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 16)
		count += ft_putnbrbase_long(nb / 16);
	count += ft_putchar(hex[nb % 16]);
	return (count);
}
