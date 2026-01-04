/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:34:09 by mobenhab          #+#    #+#             */
/*   Updated: 2025/12/31 20:53:55 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_top(t_stack *pile_a, t_stack *pile_b)
{

}

void	check_last(t_stack *pile_a, t_stack *pile_b)
{

}

void insertion(t_stack *pile_a, t_stack *pile_b)
{
    t_list *last;//connaitre le content du dernier noeud
	t_list *mouv;//pouvoir se deplacer dans la liste b
	int		index;//connaitre le nombre d'element dans b pour savoir dans quel sens decaler(permet de diminuer le nombre d'operation)
	int		stack_size;

	if (!pile_a || !pile_a->first || !pile_a->first->next)
    	return ;
	pb(pile_a, pile_b);//mettre un premier element dans b
	last = pile_b->first;// le definir comme le dernier pour avoir un repère
	index = 1;//index qui va permettre de savoir dans quel sens rotate pour empiler
	while (pile_a->first)//parcours la chaine a jusqu'à que tout soit trier puis mettre tout b dans a
	{
		if (pile_a->first->content > pile_b->first->content)//si top(a) > top(b), on empile
		{
			last = pile_b->first;
			pb(pile_b, pile_a);//mettre au dessus de b
			stack_size++;
		}
		else if (pile_a->first->content < last->content)
		{
			last = pile_a->first;
			pb(pile_b, pile_a);//mettre au dessus de b
			rb(pile_b);//passer le top en bas de la pile
			stack_size++;
		}
		else
		{
			mouv = pile_b->first;//premier element de la liste b
			while (mouv->next != NULL)
			{
				if (pile_a->first->content > mouv->content)
				{
					if (index <= (stack_size/2))//savoir si on se situe a plus de la moitié ou non
						// while ()
							rb(pile_b);
				}
				mouv = mouv->next;
				index++;
			}
		}	
	}
}

// int main(void)
// {
	
// }