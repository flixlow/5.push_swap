/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:56:55 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/12 16:37:16 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_error(t_stack *a, t_stack *b, t_stock *stock)
{
	freepile(a);
	freepile(b);
	(void)stock;
	write(2, "Error\n", 6);
	return (1);
}

void	freeall(t_stack *a, t_stack *b, t_stock *stock)
{
	freepile(a);
	freepile(b);
	(void)stock;
}

void	freestock(t_stock *stock)
{
	if (stock->bench != NULL)
		free(stock->bench);
	else if (stock->strategy != NULL)
		free(stock->strategy);
	else if (stock->theorical_complexity != NULL)
		free(stock->theorical_complexity);
}

int	has_duplicates(t_stack *pile)
{
	t_list	*i;
	t_list	*j;

	i = pile->first;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->content == j->content)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (i < nb)
	{
		if ((i * i) >= nb)
			return (i);
		i++;
	}
	return (0);
}
