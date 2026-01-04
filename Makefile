SRC = 

CC = cc

CFLAGS = -Wall -werror -Wextra -I.

DEP = $(OBJ:.o=:.d)

NAME = push_swap.a

OBJ = $(SRC:.c=.o)

.PHONY: all re fclean clean

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $@ $^

%.o: %.cc
		$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
		rm -rf $(OBJ) $(DEP)

fclean: clean
		rm -f $(NAME)

re: fclean all

-include $(DEP)