/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:46:27 by flauweri          #+#    #+#             */
/*   Updated: 2026/01/11 01:30:40 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_bzero(char	*line, char *buf)
{
	int	i;

	i = 0;
	if (line != NULL)
		free(line);
	while (i < BUFFER_SIZE)
		buf[i++] = 0;
	return (NULL);
}
