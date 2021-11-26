NAME =	pipex

CC			=	gcc
CFLAGS		=	-w -Wall -Wextra -Werror

INCLUDE = -I ./includes

SRC =	pipex.c pipex_utils.c error_pipex.c 

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	rm -rf $(NAME)
	make all -C ./libft
	$(CC) $(CFLAGS) $(OBJ) ./libft/libft.a -o $(NAME)

clean:
	@$(MAKE) -C ./libft fclean
	rm -rf $(OBJ)
	rm -rf ./a.out

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

	