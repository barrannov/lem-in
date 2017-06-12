NAME = lem-in

LIB = -L./libft -lft

FLAGS = -Wall -Wextra -Werror

SRC =         src/find_way/find_shortest.c \
              src/find_way/helpers.c \
              src/validation/check_links.c \
              src/validation/check_rooms.c \
              src/validation/helpers_for_val.c \
              src/validation/minor_val_fs.c \
              src/validation/validation.c \
              src/work_with_ants/ants.c \
              src/lem_in.c \
              libft/get_next_line.c \
              libft/is_number.c \
              libft/length.c \

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	make -C libft/
	gcc $(LIB) -o $(NAME) $(BINS)
%.o: %.c
	gcc -c -o $@ $<
clean:
	make -C libft/ clean
	rm -rf $(BINS)
fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)
re: fclean all