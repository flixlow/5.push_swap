/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pile_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:29:40 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/12 18:08:53 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_digits(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] == '-' || tab[i][j] == '+')
			j++;
		while (tab[i][j])
		{
			if (!(tab[i][j] >= '0' && tab[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_overflow(int content, char *str)
{
	char	*new_str;

	new_str = ft_itoa(content);
	if (str[0] == '+')
		str++;
	if (ft_strcmp(new_str, str) != 0)
	{
		free(new_str);
		return (1);
	}
	free(new_str);
	return (0);
}

int	init_pile(t_list **pile_a, char **tab)
{
	t_list	*new;
	t_list	*last;
	size_t	i;

	i = 0;
	last = NULL;
	while (tab[i])
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (1);
		new->content = ft_atoi(tab[i]);
		new->next = NULL;
		if (*pile_a == NULL)
			*pile_a = new;
		else
			last->next = new;
		last = new;
		if (check_overflow(new->content, tab[i]))
			return (1);
		i++;
	}
	return (0);
}

int	operation_on_pile(char **operation, t_list **pile_a, t_list **pile_b)
{
	if (ft_strcmp(*operation, "pa\n") == 0)
		push(pile_a, pile_b);
	else if (ft_strcmp(*operation, "pb\n") == 0)
		push(pile_b, pile_a);
	else if (ft_strcmp(*operation, "sa\n") == 0)
		swap(pile_a);
	else if (ft_strcmp(*operation, "sb\n") == 0)
		swap(pile_b);
	else if (ft_strcmp(*operation, "ss\n") == 0)
		ss(pile_a, pile_b);
	else if (ft_strcmp(*operation, "ra\n") == 0)
		rotate(pile_a);
	else if (ft_strcmp(*operation, "rb\n") == 0)
		rotate(pile_b);
	else if (ft_strcmp(*operation, "rr\n") == 0)
		rr(pile_a, pile_b);
	else if (ft_strcmp(*operation, "rra\n") == 0)
		revrotate(pile_a);
	else if (ft_strcmp(*operation, "rrb\n") == 0)
		revrotate(pile_b);
	else if (ft_strcmp(*operation, "rrr\n") == 0)
		rrr(pile_a, pile_b);
	else
		return (ft_error(pile_a, pile_b, operation));
	return (0);
}

int	init(char **av, t_list **pile_a, t_list **pile_b)
{
	char	**tab;

	tab = NULL;
	*pile_a = NULL;
	if (av[2] == NULL)
		tab = ft_split(av[1], ' ');
	else
		tab = av + 1;
	if (!(tab)[1] || check_digits(tab) || init_pile(pile_a, tab) ||
		has_duplicates(*pile_a))
	{
		if (!(tab == av + 1))
			ft_free_tab(tab);
		return (freeall(pile_a, pile_b, "Error\n"));
	}
	if (!(tab == av + 1))
		ft_free_tab(tab);
	return (0);
}
