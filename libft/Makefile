GCC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRC = $(wildcard ft_[^l]*.c)
SRC_B = $(wildcard ft_l*.c)
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -cr $@ $(OBJ)

bonus : $(NAME) $(OBJ_B)
	ar -cr $(NAME) $(OBJ_B)

clean :
	rm -f $(OBJ) $(OBJ_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

.c.o :
	$(GCC) $(CFLAGS) -c -o $@ $<
