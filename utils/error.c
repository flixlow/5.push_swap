/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:56:55 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/08 17:36:32 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_error(t_stack *a, t_stack *b, t_stock *stock)
{
    freepile(a);
    freepile(b);
    //freestock(stock);
    (void)stock;
    write(2, "Error\n", 6);
    return(0);
}

void freeall(t_stack *a, t_stack *b, t_stock *stock)
{
    freepile(a);
    freepile(b);
    (void)stock;
}

void    freestock(t_stock *stock)
{
    if (stock->bench != NULL)
        free(stock->bench);
    else if (stock->strategy != NULL)
        free(stock->strategy);
    else if (stock->theorical_complexity != NULL)
        free(stock->theorical_complexity);
}

int free_str(char *str, int i)
{
    free(str);
    return (i);
}