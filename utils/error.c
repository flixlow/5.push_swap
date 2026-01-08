/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:56:55 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/08 17:05:59 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_error(t_stack *a, t_stack *b, t_stock stock)
{
    freepile(a);
    freepile(b);
    freestock(&stock);
    write(2, "Error\n", 6);
    return(0);
}

void freeall(t_stack *a, t_stack *b, t_stock stock)
{
    freepile(a);
    freepile(b);
    freestock(&stock);
}

void    freestock(t_stock *stock)
{
    if (stock->bench != NULL)
        free(stock->bench);
    if (stock->bench != NULL)
        free(stock->strategy);
    if (stock->bench != NULL)
        free(stock->theorical_complexity);
}

int free_str(char *str, int i)
{
    free(str);
    return (i);
}