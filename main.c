/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:18:45 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/04 17:23:12 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// int main(void)
// {
// 	t_stack *stack_a;
// 	t_stack *stack_b;

// 	// ═══════════════════════════════════════════
// 	// TESTS SWAP (sa, sb, ss)
// 	// ═══════════════════════════════════════════
// 	ft_printf("\n");
// 	ft_printf("═════════════════════════════════════════════\n");
// 	ft_printf("  TESTS SWAP (sa, sb, ss)\n");
// 	ft_printf("═════════════════════════════════════════════\n");

// 	// Test SA
// 	ft_printf("\n=== TEST SA: Swap pile A ===\n");
// 	stack_a = creatpile();
// 	push(stack_a, 1);
// 	push(stack_a, 2);
// 	push(stack_a, 3);
// 	push(stack_a, 4);
// 	ft_printf("Avant sa:\n");
// 	printpile(stack_a);
// 	sa(stack_a);
// 	ft_printf("Après sa (4 et 3 échangés):\n");
// 	printpile(stack_a);
// 	freepile(stack_a);

// 	// Test SB
// 	ft_printf("\n=== TEST SB: Swap pile B ===\n");
// 	stack_b = creatpile();
// 	push(stack_b, 10);
// 	push(stack_b, 20);
// 	push(stack_b, 30);
// 	ft_printf("Avant sb:\n");
// 	printpile(stack_b);
// 	sb(stack_b);
// 	ft_printf("Après sb (30 et 20 échangés):\n");
// 	printpile(stack_b);
// 	freepile(stack_b);

// 	// Test SS
// 	ft_printf("\n=== TEST SS: Swap A et B ensemble ===\n");
// 	stack_a = creatpile();
// 	stack_b = creatpile();
// 	push(stack_a, 1);
// 	push(stack_a, 2);
// 	push(stack_a, 3);
// 	push(stack_b, 10);
// 	push(stack_b, 20);
// 	push(stack_b, 30);
// 	ft_printf("Avant ss:\n");
// 	ft_printf("Pile A:\n");
// 	printpile(stack_a);
// 	ft_printf("Pile B:\n");
// 	printpile(stack_b);
// 	ss(stack_a, stack_b);
// 	ft_printf("Après ss:\n");
// 	ft_printf("Pile A:\n");
// 	printpile(stack_a);
// 	ft_printf("Pile B:\n");
// 	printpile(stack_b);
// 	freepile(stack_a);
// 	freepile(stack_b);

// 	// Test swap avec 1 élément
// 	ft_printf("\n=== TEST SA: Un seul élément (ne change rien) ===\n");
// 	stack_a = creatpile();
// 	push(stack_a, 42);
// 	ft_printf("Avant sa:\n");
// 	printpile(stack_a);
// 	sa(stack_a);
// 	ft_printf("Après sa:\n");
// 	printpile(stack_a);
// 	freepile(stack_a);

// 	// Test swap pile vide
// 	ft_printf("\n=== TEST SA: Pile vide (ne fait rien) ===\n");
// 	stack_a = creatpile();
// 	ft_printf("Avant sa:\n");
// 	printpile(stack_a);
// 	sa(stack_a);
// 	ft_printf("Après sa:\n");
// 	printpile(stack_a);
// 	freepile(stack_a);

// 	// ═══════════════════════════════════════════
// 	// TESTS PUSH (pa, pb)
// 	// ═══════════════════════════════════════════
// 	ft_printf("\n");
// 	ft_printf("═════════════════════════════════════════════\n");
// 	ft_printf("  TESTS PUSH (pa, pb)\n");
// 	ft_printf("═════════════════════════════════════════════\n");

// 	// Test PB basique
// 	ft_printf("\n=== TEST PB: Push de A vers B ===\n");
// 	stack_a = creatpile();
// 	stack_b = creatpile();
// 	push(stack_a, 1);
// 	push(stack_a, 2);
// 	push(stack_a, 3);
// 	push(stack_a, 4);
// 	ft_printf("Avant pb:\n");
// 	ft_printf("Pile A:\n");
// 	printpile(stack_a);
// 	ft_printf("Pile B:\n");
// 	printpile(stack_b);
// 	pb(stack_b, stack_a);
// 	ft_printf("Après pb (4 va dans B):\n");
// 	ft_printf("Pile A:\n");
// 	printpile(stack_a);
// 	ft_printf("Pile B:\n");
// 	printpile(stack_b);

// 	// Test PB multiple
// 	ft_printf("\n=== TEST PB: Plusieurs push ===\n");
// 	pb(stack_b, stack_a);
// 	pb(stack_b, stack_a);
// 	ft_printf("Après 2 pb supplémentaires:\n");
// 	ft_printf("Pile A:\n");
// 	printpile(stack_a);
// 	ft_printf("Pile B:\n");
// 	printpile(stack_b);

// 	// Test PA
// 	ft_printf("\n=== TEST PA: Push de B vers A ===\n");
// 	pa(stack_a, stack_b);
// 	ft_printf("Après pa (2 retourne dans A):\n");
// 	ft_printf("Pile A:\n");
// 	printpile(stack_a);
// 	ft_printf("Pile B:\n");
// 	printpile(stack_b);

// 	// Vider complètement A dans B
// 	ft_printf("\n=== TEST PB: Vider A dans B ===\n");
// 	pb(stack_b, stack_a);
// 	pb(stack_b, stack_a);
// 	ft_printf("A est vide, B a tout:\n");
// 	ft_printf("Pile A:\n");
// 	printpile(stack_a);
// 	ft_printf("Pile B:\n");
// 	printpile(stack_b);

// 	// Tout remettre dans A
// 	ft_printf("\n=== TEST PA: Tout remettre dans A ===\n");
// 	pa(stack_a, stack_b);
// 	pa(stack_a, stack_b);
// 	pa(stack_a, stack_b);
//     pa(stack_a, stack_b);
// 	ft_printf("B est vide, A a tout:\n");
// 	ft_printf("Pile A:\n");
// 	printpile(stack_a);
// 	ft_printf("Pile B:\n");
// 	printpile(stack_b);

// 	freepile(stack_a);
// 	freepile(stack_b);

// 	// Test push sur pile vide
// 	ft_printf("\n=== TEST PA/PB: Push depuis pile vide ===\n");
// 	stack_a = creatpile();
// 	stack_b = creatpile();
// 	ft_printf("Les deux piles sont vides:\n");
// 	ft_printf("Pile A:\n");
// 	printpile(stack_a);
// 	ft_printf("Pile B:\n");
// 	printpile(stack_b);
// 	pa(stack_a, stack_b);  // Ne fait rien
// 	pb(stack_a, stack_b);  // Ne fait rien
// 	ft_printf("Après pa et pb (rien ne change):\n");
// 	ft_printf("Pile A:\n");
// 	printpile(stack_a);
// 	ft_printf("Pile B:\n");
// 	printpile(stack_b);
// 	freepile(stack_a);
// 	freepile(stack_b);

// 	// ═══════════════════════════════════════════
// 	// TESTS ROTATE (ra, rb, rr)
// 	// ═══════════════════════════════════════════
// 	ft_printf("\n");
// 	ft_printf("═════════════════════════════════════════════\n");
// 	ft_printf("  TESTS ROTATE (ra, rb, rr)\n");
// 	ft_printf("═════════════════════════════════════════════\n");

// 	// Test RA basique
// 	ft_printf("\n=== TEST RA: Rotation normale ===\n");
// 	stack_a = creatpile();
// 	push(stack_a, 1);
// 	push(stack_a, 2);
// 	push(stack_a, 3);
// 	push(stack_a, 4);
// 	ft_printf("Avant ra:\n");
// 	printpile(stack_a);
// 	ra(stack_a);
// 	ft_printf("Après ra (4 va à la fin):\n");
// 	printpile(stack_a);

// 	// Rotations multiples
// 	ft_printf("\n=== TEST RA: Rotations multiples ===\n");
// 	ra(stack_a);
// 	ft_printf("Après 2ème ra:\n");
// 	printpile(stack_a);
// 	ra(stack_a);
// 	ft_printf("Après 3ème ra:\n");
// 	printpile(stack_a);
// 	ra(stack_a);
// 	ft_printf("Après 4ème ra (retour initial):\n");
// 	printpile(stack_a);
// 	freepile(stack_a);

// 	// Test RB
// 	ft_printf("\n=== TEST RB: Rotation pile B ===\n");
// 	stack_b = creatpile();
// 	push(stack_b, 10);
// 	push(stack_b, 20);
// 	push(stack_b, 30);
// 	push(stack_b, 40);
// 	ft_printf("Avant rb:\n");
// 	printpile(stack_b);
// 	rb(stack_b);
// 	ft_printf("Après rb (40 va à la fin):\n");
// 	printpile(stack_b);
// 	freepile(stack_b);

// 	// Test RR
// 	ft_printf("\n=== TEST RR: Rotation des deux piles ===\n");
// 	stack_a = creatpile();
// 	stack_b = creatpile();
// 	push(stack_a, 1);
// 	push(stack_a, 2);
// 	push(stack_a, 3);
// 	push(stack_a, 4);
// 	push(stack_b, 10);
// 	push(stack_b, 20);
// 	push(stack_b, 30);
// 	ft_printf("Avant rr:\n");
// 	ft_printf("Pile A:\n");
// 	printpile(stack_a);
// 	ft_printf("Pile B:\n");
// 	printpile(stack_b);
// 	rr(stack_a, stack_b);
// 	ft_printf("Après rr:\n");
// 	ft_printf("Pile A:\n");
// 	printpile(stack_a);
// 	ft_printf("Pile B:\n");
// 	printpile(stack_b);
// 	freepile(stack_a);
// 	freepile(stack_b);

// 	// Test rotate pile vide
// 	ft_printf("\n=== TEST RA: Pile vide ===\n");
// 	stack_a = creatpile();
// 	ft_printf("Avant ra:\n");
// 	printpile(stack_a);
// 	ra(stack_a);
// 	ft_printf("Après ra (ne fait rien):\n");
// 	printpile(stack_a);
// 	freepile(stack_a);

// 	// Test rotate 1 élément
// 	ft_printf("\n=== TEST RA: Un seul élément ===\n");
// 	stack_a = creatpile();
// 	push(stack_a, 42);
// 	ft_printf("Avant ra:\n");
// 	printpile(stack_a);
// 	ra(stack_a);
// 	ft_printf("Après ra (ne change rien):\n");
// 	printpile(stack_a);
// 	freepile(stack_a);

// 	// Test rotate 2 éléments
// 	ft_printf("\n=== TEST RA: Deux éléments ===\n");
// 	stack_a = creatpile();
// 	push(stack_a, 1);
// 	push(stack_a, 2);
// 	ft_printf("Avant ra:\n");
// 	printpile(stack_a);
// 	ra(stack_a);
// 	ft_printf("Après ra (1 et 2 échangent):\n");
// 	printpile(stack_a);
// 	freepile(stack_a);

// 	// ═══════════════════════════════════════════
// 	// TESTS REVERSE ROTATE (rra, rrb, rrr)
// 	// ═══════════════════════════════════════════
// 	ft_printf("\n");
// 	ft_printf("═════════════════════════════════════════════\n");
// 	ft_printf("  TESTS REVERSE ROTATE (rra, rrb, rrr)\n");
// 	ft_printf("═════════════════════════════════════════════\n");

// 	// Test RRA basique
// 	ft_printf("\n=== TEST RRA: Reverse rotation normale ===\n");
// 	stack_a = creatpile();
// 	push(stack_a, 1);
// 	push(stack_a, 2);
// 	push(stack_a, 3);
// 	push(stack_a, 4);
// 	ft_printf("Avant rra:\n");
// 	printpile(stack_a);
// 	rra(stack_a);
// 	ft_printf("Après rra (1 va au début):\n");
// 	printpile(stack_a);

// 	// Reverse rotations multiples
// 	ft_printf("\n=== TEST RRA: Reverse rotations multiples ===\n");
// 	rra(stack_a);
// 	ft_printf("Après 2ème rra:\n");
// 	printpile(stack_a);
// 	rra(stack_a);
// 	ft_printf("Après 3ème rra:\n");
// 	printpile(stack_a);
// 	rra(stack_a);
// 	ft_printf("Après 4ème rra (retour initial):\n");
// 	printpile(stack_a);
// 	freepile(stack_a);

// 	// Test RRB
// 	ft_printf("\n=== TEST RRB: Reverse rotation pile B ===\n");
// 	stack_b = creatpile();
// 	push(stack_b, 10);
// 	push(stack_b, 20);
// 	push(stack_b, 30);
// 	push(stack_b, 40);
// 	ft_printf("Avant rrb:\n");
// 	printpile(stack_b);
// 	rrb(stack_b);
// 	ft_printf("Après rrb (40 va au début):\n");
// 	printpile(stack_b);
// 	freepile(stack_b);

// 	// Test RRR
// 	ft_printf("\n=== TEST RRR: Reverse rotation des deux piles ===\n");
// 	stack_a = creatpile();
// 	stack_b = creatpile();
// 	push(stack_a, 1);
// 	push(stack_a, 2);
// 	push(stack_a, 3);
// 	push(stack_a, 4);
// 	push(stack_b, 10);
// 	push(stack_b, 20);
// 	push(stack_b, 30);
// 	ft_printf("Avant rrr:\n");
// 	ft_printf("Pile A:\n");
// 	printpile(stack_a);
// 	ft_printf("Pile B:\n");
// 	printpile(stack_b);
// 	rrr(stack_a, stack_b);
// 	ft_printf("Après rrr:\n");
// 	ft_printf("Pile A:\n");
// 	printpile(stack_a);
// 	ft_printf("Pile B:\n");
// 	printpile(stack_b);
// 	freepile(stack_a);
// 	freepile(stack_b);

// 	// Test reverse rotate pile vide
// 	ft_printf("\n=== TEST RRA: Pile vide ===\n");
// 	stack_a = creatpile();
// 	ft_printf("Avant rra:\n");
// 	printpile(stack_a);
// 	rra(stack_a);
// 	ft_printf("Après rra (ne fait rien):\n");
// 	printpile(stack_a);
// 	freepile(stack_a);

// 	// Test reverse rotate 1 élément
// 	ft_printf("\n=== TEST RRA: Un seul élément ===\n");
// 	stack_a = creatpile();
// 	push(stack_a, 42);
// 	ft_printf("Avant rra:\n");
// 	printpile(stack_a);
// 	rra(stack_a);
// 	ft_printf("Après rra (ne change rien):\n");
// 	printpile(stack_a);
// 	freepile(stack_a);

// 	// Test reverse rotate 2 éléments
// 	ft_printf("\n=== TEST RRA: Deux éléments ===\n");
// 	stack_a = creatpile();
// 	push(stack_a, 1);
// 	push(stack_a, 2);
// 	ft_printf("Avant rra:\n");
// 	printpile(stack_a);
// 	rra(stack_a);
// 	ft_printf("Après rra (1 et 2 échangent):\n");
// 	printpile(stack_a);
// 	freepile(stack_a);

// 	// ═══════════════════════════════════════════
// 	// TEST COMBINÉ: RA vs RRA
// 	// ═══════════════════════════════════════════
// 	ft_printf("\n");
// 	ft_printf("═════════════════════════════════════════════\n");
// 	ft_printf("  TEST COMBINÉ: RA vs RRA\n");
// 	ft_printf("═════════════════════════════════════════════\n");

// 	ft_printf("\n=== TEST: RA puis RRA = retour initial ===\n");
// 	stack_a = creatpile();
// 	push(stack_a, 1);
// 	push(stack_a, 2);
// 	push(stack_a, 3);
// 	push(stack_a, 4);
// 	ft_printf("Initial:\n");
// 	printpile(stack_a);
// 	ra(stack_a);
// 	ft_printf("Après ra:\n");
// 	printpile(stack_a);
// 	rra(stack_a);
// 	ft_printf("Après rra (retour initial):\n");
// 	printpile(stack_a);
// 	freepile(stack_a);
// 	// ═══════════════════════════════════════════
// 	// FIN DES TESTS
// 	// ═══════════════════════════════════════════
// 	ft_printf("\n");
// 	ft_printf("═════════════════════════════════════════════\n");
// 	ft_printf("  ✅ TOUS LES TESTS TERMINÉS\n");
// 	ft_printf("═════════════════════════════════════════════\n");
// 	ft_printf("\n");

// 	return (0);
// }

// int main()
// {
//     t_stack *pile1 = creatpile();
//     push(pile1, 1);
//     push(pile1, 2);
//     push(pile1, 3);
//     push(pile1, 4);
//     push(pile1, 5);
//     printf("Pile triée croissante : %f\n", compute_disorder(pile1)); // 0.0
//     freepile(pile1);

//     t_stack *pile2 = creatpile();
//     push(pile2, 5);
//     push(pile2, 4);
//     push(pile2, 3);
//     push(pile2, 2);
//     push(pile2, 1);
//     printf("Pile triée décroissante : %f\n", compute_disorder(pile2)); // 1.0
//     freepile(pile2);

//     t_stack *pile3 = creatpile();
//     push(pile3, 1);
//     push(pile3, 3);
//     push(pile3, 2);
//     push(pile3, 5);
//     push(pile3, 4);
//     printf("Pile désordonnée : %f\n", compute_disorder(pile3));
// entre 0 et 1
//     freepile(pile3);

//     t_stack *pile4 = creatpile(); // pile vide
//     printf("Pile vide : %f\n", compute_disorder(pile4)); // 0.0
//     freepile(pile4);

//     return (0);
// }
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	int		chunk;
	int		*arr;

	if (ac < 2)
		return (0);
	a = creatpile();
	b = creatpile();
	// 1 Initialiser la pile A depuis argv
	init_stack(a, av);
	// printpile(a);
	// 2 Si déjà trié → rien à faire
	if (is_sorted(a))
	{
		ft_printf("Pile déjà triée\n");
		freepile(a);
		freepile(b);
		return (0);
	}

	ft_printf("pile a\n");
	printpile(a);
	ft_printf("pile b\n");
	printpile(b);
	radix_sort(a,b);
	ft_printf("Résultat final\n");
	printpile(a);
	printpile(b);
	freepile(b);
	freepile(a);
	return (0);
}

