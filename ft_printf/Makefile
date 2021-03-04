

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c parse.c print_format.c handle_con.c \
	   handle_flag.c handle_length.c handle_exception.c
OBJS = $(SRCS:.c=.o)

LIB_DIR = ./libft
LIB = libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIB) $@
	ar rc $@ $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
			   
bonus : $(NAME)

clean :
	rm -f $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re : fclean all
