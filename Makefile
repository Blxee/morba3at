CC = cc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -lncurses
NAME = morba3at
INCLUDES = $(wildcard *.h)
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

run: $(NAME)
	./$(NAME)

$(NAME): $(OBJ)
	$(CC) $^ $(LDFLAGS) -o $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@
