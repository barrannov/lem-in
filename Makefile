NAME = lem-in
LIB = -L./libft -lft

#FLAGS = -Wall -Wextra -Werror

SRC = lem-in.c \

BINS = $(SRC:.c=.o)
O1 = main.o

all: $(NAME)

$(NAME): $(BINS) $(O1)
	make -C libft/
	gcc $(LIB) $(FLAGS) -o $(NAME) $(O1) $(BINS)

%.o: %.c
	gcc  -c -o $@ $< $(FLAGS)
clean:
	make -C libft/ clean
	rm -f $(BINS) $(O1)
fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)
re: fclean all
