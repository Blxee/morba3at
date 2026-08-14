CC = cc
NAME = morba3at
INCLUDES = $(wildcard *.h)
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

run: $(NAME)
	./$(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) -c $< -o $@
