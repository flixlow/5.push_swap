NAME = push_swap

NAME_BONUS = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra -I. -g3

PRINTF := ft_printf.c ft_putchar.c ft_putnbr_base_upper.c ft_putnbr_un.c ft_putvoid.c ft_putnbr_base.c ft_putnbr.c ft_putstr.c s_write.c

SORT := algo_choice.c adaptive.c complex.c medium.c medium_utils.c simple.c

OP := push.c  revrotate.c  rotate.c  swap.c

UTILS := parsing.c ft_atoi.c  stack_management.c benchmark_mode.c ft_split.c ft_itoa.c error.c

SRC = $(addprefix ft_printf/, $(PRINTF))\
			$(addprefix algo/, $(SORT))\
			$(addprefix operations/, $(OP))\
			$(addprefix utils/, $(UTILS))\
			main.c 

BONUS = main_bonus.c \
		utils1_bonus.c \
		utils2_bonus.c \
		init_pile_bonus.c \
		error_bonus.c \
		get_next_line_bonus.c \
		push_bonus.c \
		revrotate_bonus.c \
		rotate_bonus.c \
		swap_bonus.c

SRC_BONUS = $(addprefix push_swap_bonus/, $(BONUS))

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

DEP = $(OBJ:.o=.d)

DEP_BONUS = $(OBJ_BONUS:.o=.d)

.PHONY: all re fclean clean bonus

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
		$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
		rm -f $(OBJ) $(DEP)
		rm -f $(OBJ_BONUS) $(DEP_BONUS)

fclean: clean
		rm -f $(NAME)
		rm -f $(NAME_BONUS)

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
		$(CC) $(CFLAGS) $^ -o $@

-include $(DEP) $(DEP_BONUS)