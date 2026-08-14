CC = cc
NAME = morba3at
SRC = main.c

run:
	$(CC) $(SRC) -o $(NAME)
	./$(NAME)

# %.o: %.c $(INCLUDES)
# 	$(CC)
