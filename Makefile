NAME = factorization

SRCS = factorization.c

BIN_PATH = /usr/local/bin

$(NAME): $(SRCS)
	gcc -Wall -Wextra -Werror $(SRCS) -o $(NAME)
	@sudo cp $(NAME) $(BIN_PATH)

all: $(NAME)

fclean:
	rm -rf $(NAME)
	@sudo rm -rf $(BIN_PATH)/$(NAME)