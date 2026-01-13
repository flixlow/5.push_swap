/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:09:48 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/13 12:22:42 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define MAX_SIZE 500

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

void	swap(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	push(t_list **receiver, t_list **sender);
void	rotate(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	revrotate(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);

int		init(char **av, t_list **stack_a, t_list **stack_b);
int		init_stack(t_list **stack_a, char **tab);
int		operation_on_stack(char **operation, t_list **stack_a, t_list **stack_b);
int		freestack(t_list **stack);

int		check_digits(char **tab);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *src);
int		is_sorted(t_list *stack);
int		ft_error(t_list **stack_a, t_list **stack_b, char **op);
int		freeall(t_list **stack_a, t_list **stack_b, char *oko);
int		has_duplicates(t_list *stack);

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buf);
char	**ft_free_tab(char **tab);
int		ft_strlen(char	*str, char c);
void	ft_memmove(char *buf);
char	*searching_n(char *line, char *buf, int *i);
void	*ft_bzero(char	*line, char *buf);
int		check_overflow(int content, char *str);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	**ft_split(char const *s, char c);

#endif