CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c \
	  parser.c \
	  shift.c \
	  validator.c \
	  solver.c \
	  solver2.c \
	  str.c
OBJ = $(SRC:.c=.o)
NAME = fillit

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c fillit.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC) fillit.h
