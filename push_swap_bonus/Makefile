NAME = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra -I. -g3

SRC = main.c \
		utils1.c \
		utils2.c \
		init_pile.c \
		error.c \
		get_next_line.c \
		push.c \
		revrotate.c \
		rotate.c \
		swap.c
 
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