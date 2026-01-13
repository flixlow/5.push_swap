/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 19:36:51 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/13 12:16:59 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lstlen(t_stack *stack)
{
	int		n;
	t_list	*tmp;

	tmp = stack->first;
	n = 0;
	while (tmp)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}

int	*cpy_chunk(t_list *stack, int size)
{
	int		*arr;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack;
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
	int	i;
	int	j;
	int	tmp;

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

void	index_arr(t_list *stack, int *arr, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stack;
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

void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	*arr;
	int	chunk;

	stack_a->stock->theorical_complexity = "O(n√n)";
	size = lstlen(stack_a);
	if (size < 3)
		sa(stack_a);
	else
	{
		arr = cpy_chunk(stack_a->first, size);
		sort_arr(arr, size);
		index_arr(stack_a->first, arr, size);
		free(arr);
		chunk = ft_sqrt(size);
		push_to_b(stack_a, stack_b, chunk);
		push_chunk(stack_a, stack_b);
	}
}
