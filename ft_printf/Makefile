# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 16:38:39 by flauweri          #+#    #+#              #
#    Updated: 2025/12/05 11:10:31 by flauweri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_putvoid.c \
			ft_putnbr_un.c \
			ft_putnbr_base.c \
			ft_putnbr_base_upper.c \
			s_write.c

DEPS = $(OBJ:%.o=%.d)

OBJ = $(SRC:%.c=%.o)

all : $(NAME)
	
$(NAME) : $(OBJ)
	ar cr $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -MD -MP -MF $(patsubst %.o, %.d, $@)

clean :
	rm -f $(OBJ) $(DEPS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

-include $(DEPS)