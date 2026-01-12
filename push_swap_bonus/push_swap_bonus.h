/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:09:48 by mobenhab          #+#    #+#             */
/*   Updated: 2026/01/12 15:59:59 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

void	swap(t_list **pile);
void	ss(t_list **pile_a, t_list **pile_b);
void	push(t_list **receiver, t_list **sender);
void	rotate(t_list **pile);
void	rr(t_list **pile_a, t_list **pile_b);
void	revrotate(t_list **pile);
void	rrr(t_list **pile_a, t_list **pile_b);

int		init(char **av, t_list **pile_a, t_list **pile_b);
int		init_pile(t_list **pile_a, char **tab);
int		operation_on_pile(char **operation, t_list **pile_a, t_list **pile_b);
int		freepile(t_list **pile);

int		check_digits(char **tab);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *src);
int		is_sorted(t_list *pile);
int		ft_error(t_list **pile_a, t_list **pile_b, char **op);
int		freeall(t_list **pile_a, t_list **pile_b, char *oko);
int		has_duplicates(t_list *pile);

char	*get_next_line(int fd);
char	*ft_substr(char *line);
char	*ft_strjoin(char *line, char *buf);
int		ft_free(char *s1, char *s2);
char	**ft_free_tab(char **tab);
int		ft_strlen(char	*str, char c);
void	ft_memmove(char *buf);
void	*ft_bzero(char	*line, char *buf);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);

#endif