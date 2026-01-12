NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -I. -g3

PRINTF := ft_printf.c ft_putchar.c ft_putnbr_base_upper.c ft_putnbr_un.c ft_putvoid.c ft_putnbr_base.c ft_putnbr.c ft_putstr.c s_write.c \

SORT := algo_choice.c adaptive.c complex.c medium.c medium_utils.c simple.c

OP := push.c  revrotate.c  rotate.c  swap.c

UTILS := parsing.c ft_atoi.c  stack_management.c benchmark_mode.c ft_split.c ft_itoa.c error.c

SRC = $(addprefix ft_printf/, $(PRINTF))\
			$(addprefix algo/, $(SORT))\
			$(addprefix operations/, $(OP))\
			$(addprefix utils/, $(UTILS))\
			main.c 

SRC_BONUS = $(addprefix)

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
		make -C ./push_swap_bonus clean

fclean: clean
		rm -f $(NAME)
		rm -f checker
		make -C ./push_swap_bonus fclean

re: fclean all

bonus:
	make -C ./push_swap_bonus
	mv ./push_swap_bonus/checker .

-include $(DEP)