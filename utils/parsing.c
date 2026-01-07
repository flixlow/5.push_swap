/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 19:00:44 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/07 17:26:29 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strcpy(char *src)
{
	char	*dest;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s2[i] - s1[i]);
		i++;
	}
	return (s2[i] - s1[i]);
}

int	check_strategy(char *str, t_stock *stock)
{
	int	i;

	i = 2;
	if (ft_strcmp(str, "--simple") == 0)
		stock->strategy = ft_strcpy(&str[2]);
	else if (ft_strcmp(str, "--medium") == 0)
		stock->strategy = ft_strcpy(&str[2]);
	else if (ft_strcmp(str, "--complex") == 0)
		stock->strategy = ft_strcpy(&str[2]);
	else if (ft_strcmp(str, "--adaptive") == 0)
		stock->strategy = ft_strcpy(&str[2]);
	else if (ft_strcmp(str, "--bench") == 0)
		stock->bench = ft_strcpy(&str[2]);
	else
		return (1);
	return (0);
}

int	check_digits(char *str)
{
	int	i;
	
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);	
}

int	check_args(char **av, t_stock *stock, int *begin)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if ((i == 1 || i == 2) && av[i][0] == '-' && av[i][1] == '-')
		{
			if (check_strategy(av[i], stock) == 1)
				return (1);
			*begin += 1;
		}
		else if (check_digits(av[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stock	stock;
	int	begin;	

	begin = 0;
	if (ac <= 2)
		return (write(2, "Error\n", 6));
	a = createpile();
	b = createpile();
	a->stock = &stock;
	b->stock = &stock;
	ft_memset(&stock, 0, 48);
	if (check_args(av, &stock, &begin) == 1)
		return (write(2, "Error\n", 6));
	init_stack(a, &av[begin], 1);
	printpile(a);
	adaptive(a, b);
	printpile(a);
	__builtin_printf("%s", stock.bench);
	if (ft_strcmp(stock.bench, "bench") == 0)
		benchmark_mode(stock);
}
