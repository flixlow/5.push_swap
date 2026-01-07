NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

PRINTF := ft_printf.c ft_putchar.c ft_putnbr_base_upper.c ft_putnbr_un.c ft_putvoid.c ft_putnbr_base.c ft_putnbr.c ft_putstr.c s_write.c \

SORT := adaptive.c complex.c medium.c medium_utils.c simple.c

OP := push.c  revrotate.c  rotate.c  swap.c

SRC = $(addprefix ft_printf/,$(PRINTF))\
			$(addprefix sort/,$(SORT))\
			$(addprefix operations/,$(OP))\
			parsing.c ft_atoi.c main.c stack_management.c benchmark_mode.c ft_split.c

OBJ = $(SRC:.c=.o)

DEP = $(OBJ:.o=.d)

.PHONY: all re fclean clean

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
		$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
		rm -f $(OBJ) $(DEP)

fclean: clean
		rm -f $(NAME)

re: fclean all

-include $(DEP)