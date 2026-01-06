/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:09:48 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/06 18:01:10 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_SIZE 500

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_list
{
	struct s_list	*next;
	int				content;
	int				index;

}					t_list;

typedef struct s_stack
{
	t_list			*first;
}					t_stack;

typedef struct s_stock
{
	int	swap_a;
	int swap_b;
	int swap_ab;
	int push_a;
	int push_b;
	int rotate_a;
	int	rotate_b;
	int rotate_ab;
	int reverse_rotate_a;
	int	reverse_rotate_b;
	int reverse_rotate_ab;
	int dissorder;
}					t_stock;

void				swap(t_stack *stack);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				push(t_stack *stack, int new);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_b, t_stack *stack_a);
void				rotate(t_stack *stack);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				revrotate(t_stack *stack);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);

t_stack				*creatpile(void);
void				init_stack(t_stack *a, char **av, size_t len);
void				printpile(t_stack *stack);
void				freepile(t_stack *stack);
double				compute_disorder(t_stack *stack);

void				adaptative(t_stack *a, t_stack *b);
void				insertion_sort(t_stack *pile_a, t_stack *pile_b);
void				chunk_sort(t_stack *pile_a, t_stack *pile_b);
int					lstlen(t_stack *pile);
int					*cpy_chunk(t_list *pile, int size);
void				sort_arr(int *arr, int size);
void				index_arr(t_list *pile, int *arr, int size);
void				push_to_b(t_stack *a, t_stack *b, int chunk);
void				push_chunk(t_stack *a, t_stack *b);
int					find_max_index(t_stack *b);
int					find_pos_index(t_stack *b, int index);
void				radix_sort(t_stack *pile_a, t_stack *pile_b);
void				radix_sort_bits(t_stack *pile_a, t_stack *pile_b, int bit);

void				assign_index(t_stack *pile_a);
int					check_strategy(char *arg);
void				type_stratgy(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *src);

int					check_format(const char *str, va_list argptr);
int					format_conversion(const char c, va_list argptr);

int					is_sorted(t_stack *pile_a);

int					ft_atoi(const char *str);

int					ft_printf(const char *str, ...);
int					ft_putchar(char c);
int					ft_putstr(char *str);
int					ft_putnbr(int n);
int					ft_putnbr_un(unsigned int n);
int					ft_putnbr_base(unsigned long n);
int					ft_putnbr_base_upper(unsigned int n);
int					ft_putvoid(void *n);
void				s_write(int *count, int re);

#endif