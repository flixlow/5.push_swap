
PRINTF := ft_printf.c  ft_putchar.c ft_putnbr_base_upper.c  ft_putnbr_un.c ft_putvoid.c ft_putnbr_base.c  ft_putnbr.c ft_putstr.c s_write.c \

SORT := complex.c  medium.c  medium_utils.c  simple.c

OP := push.c  revrotate.c  rotate.c  swap.c

SRC = $(addprefix ft_printf/,$(PRINTF))\
			$(addprefix sort/,$(SORT))\
			$(addprefix operations/,$(OP))\
			adaptive.c ft_format.c parsing.c utils_print.c ft_atoi.c main.c \

H := push_swap.h


CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

DEP = $(OBJ:.o=:.d)

NAME = push_swap

OBJ = $(SRC:.c=.o)

.PHONY: all re fclean clean

all: $(NAME)

$(NAME): $(OBJ) $(H)
		ar rcs $@ $^

%.o: %.cc
		$(CC) $(CFLAGS) $(H) -MMD -MP -c $< -o $@

clean:
		rm -rf $(OBJ) $(DEP)

fclean: clean
		rm -f $(NAME)

re: fclean all

-include $(DEP)