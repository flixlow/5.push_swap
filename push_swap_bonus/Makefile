NAME = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra -I. -g3

OP := push.c  revrotate.c  rotate.c  swap.c

UTILS := parsing.c ft_atoi.c init_pile.c ft_split.c ft_itoa.c error.c get_next_line.c get_next_line_utils.c

SRC = $(addprefix ft_printf/, $(PRINTF))\
			$(addprefix algo/, $(SORT))\
			$(addprefix operations/, $(OP))\
			$(addprefix utils/, $(UTILS))\
			main.c 
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