NAME = lem-in
CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJECTS = 

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all