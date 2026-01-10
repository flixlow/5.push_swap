/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 19:36:51 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/10 18:12:01 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lstlen(t_stack *pile)
{
	int			n;
	t_list		*tmp;

	tmp = pile->first;
	n = 0;
	while (tmp)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}

int	*cpy_chunk(t_list *pile, int size)
{
	int			*arr;
	int			i;
	t_list		*tmp;

	i = 0;
	tmp = pile;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (i < size)
	{
		arr[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

void	sort_arr(int *arr, int size)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	index_arr(t_list *pile, int *arr, int size)
{
	t_list		*tmp;
	int			i;

	tmp = pile;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->content == arr[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	chunk_sort(t_stack *pile_a, t_stack *pile_b)
{
	int	size;
	int	*arr;
	int	chunk;

	pile_a->stock->theorical_complexity = "O(n√n)";
	size = lstlen(pile_a);
	arr = cpy_chunk(pile_a->first, size);
	sort_arr(arr, size);
	index_arr(pile_a->first, arr, size);
	free(arr);
	chunk = ft_sqrt(size);
	push_to_b(pile_a, pile_b, chunk);
	push_chunk(pile_a, pile_b);
}
