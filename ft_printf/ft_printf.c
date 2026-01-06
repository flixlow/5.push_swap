/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:38:53 by flauweri          #+#    #+#             */
/*   Updated: 2026/01/06 15:00:24 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_selector(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putvoid(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_un(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_putnbr_base_upper(va_arg(args, unsigned int)));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start (args, str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] != '%')
			j++;
		s_write(&count, write(1, &str[i], j));
		i += j;
		if (str[i] == '%' && str[i + 1] != 0)
			s_write(&count, ft_selector(args, str[i + 1]));
		if (str[i] && str[i + 1])
			i = i + 2;
	}
	va_end(args);
	return (count);
}

/*int main(void)
{
    int             count;
    //void	        *a;
	char	        c = 'f';
	char	        *str = "World";
	int	            n = 42;
	//unsigned int	n = 4294967295;

	//count = ft_printf("Station %c", c);
	//count = ft_printf("Hello %s", str);
	count = ft_printf("Station %c ,Hello %s, Ecole %d", c, str, n);
	//count = ft_printf("Ecole %d", n);
	//count = ft_printf("Ecole %i", n);
	//count = ft_printf("Nombre positif : %u", n);
	//count = ft_printf("%x", 4294967295);
	//count = ft_printf("%X", 4294967295);
	//count = ft_printf("100%% sur le projet %s", str);
	//count = ft_printf("adress : %p", a);
	//count += ft_printf("%c", '0');
	//count += ft_printf(" NULL %s NULL ", (char *)0);
	//__builtin_printf("%d\n", __builtin_printf(" %p %p ", (void*)0, (void*)0));
	//ft_printf("%d\n", ft_printf(" %p %p ", (void*)0, (void*)0));
    //__builtin(printf("%d"))
    ft_printf("\n%d", count);
	return (0);
}*/