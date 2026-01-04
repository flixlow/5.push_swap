/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:09:48 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/04 19:30:48 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_SIZE 500

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

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

t_stack				*creatpile(void);

int					ft_putchar(char c);
int					ft_putstr(char *str);
int					check_format(const char *str, va_list argptr);
int					format_conversion(const char c, va_list argptr);
int					ft_printf(const char *format, ...);
int					ft_char(va_list argptr);
int					ft_str(va_list argptr);
int					ft_digit(va_list argptr);
int					ft_putnbr(int n);
int					ft_putnbr_uni(unsigned int n);
int					ft_putnbrbase(unsigned int nbr);
int					ft_base(va_list argptr);
int					ft_putnbrbase_lower(unsigned int nbr);
int					ft_base_lower(va_list argptr);
int					ft_digit_uni(va_list argptr);
int					ft_base_long(va_list argptr);
int					ft_putnbrbase_long(unsigned long nbr);

void				push(t_stack *stack, int new);
void				printpile(t_stack *stack);
void				swap(t_stack *stack);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_b, t_stack *stack_a);
void				freepile(t_stack *stack);
void				rotate(t_stack *stack);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				revrotate(t_stack *stack);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);

double				compute_disorder(t_stack *stack);

int					lstlen(t_stack *pile);
int					*cpy_chunk(t_list *pile, int size);
void				sort_arr(int *arr, int size);
void				index_arr(t_list *pile, int *arr, int size);
void				print_stack(t_stack *stack, char *name);
int					is_sorted(t_stack *pile_a);
int					find_max_index(t_stack *b);
int					find_pos_index(t_stack *b, int index);
void				push_chunk(t_stack *a, t_stack *b);
void				push_to_b(t_stack *a, t_stack *b, int chunk);
void				init_stack(t_stack *a, char **av);
int					ft_atoi(const char *str);
void				chunk_sort(t_stack *pile_a, t_stack *pile_b);
void				radix_sort(t_stack *pile_a, t_stack *pile_b);
void				radix_sort_bits(t_stack *pile_a, t_stack *pile_b, int bit);
void				assign_index(t_stack *pile_a);
int					check_strategy(char *arg);
void				type_stratgy(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *src);

#endif