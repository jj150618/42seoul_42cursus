CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRCS	= ./ft_memset.c \
		  ./ft_bzero.c \
		  ./ft_memcpy.c \
		  ./ft_memccpy.c \
		  ./ft_memmove.c \
		  ./ft_memchr.c \
		  ./ft_memcmp.c \
		  ./ft_strlen.c \
		  ./ft_strlcpy.c \
		  ./ft_strlcat.c \
		  ./ft_strchr.c \
		  ./ft_strrchr.c \
		  ./ft_strnstr.c \
		  ./ft_strncmp.c \
		  ./ft_atoi.c \
		  ./ft_isalpha.c \
		  ./ft_isdigit.c \
		  ./ft_isalnum.c \
		  ./ft_isascii.c \
		  ./ft_isprint.c \
		  ./ft_tolower.c \
		  ./ft_toupper.c \
		  ./ft_calloc.c \
		  ./ft_strdup.c \
		  ./ft_substr.c \
		  ./ft_strjoin.c \
		  ./ft_strtrim.c \
		  ./ft_split.c \
		  ./ft_itoa.c \
		  ./ft_strmapi.c \
		  ./ft_putchar_fd.c \
		  ./ft_putstr_fd.c \
		  ./ft_putendl_fd.c \
		  ./ft_putnbr_fd.c \
		  ./ft_strcmp.c \
		  ./ft_strcpy.c \
		  ./ft_ulltoa.c \
		  ./ft_ulltoa_base.c\
		  ./ft_floor.c \
		  ./ft_pow.c \
		  ./ft_round.c \
		  ./ft_size_count_base.c \
		  ./ft_size_count.c \
		  ./ft_size_ucount.c
SRCS_B = ./ft_lstnew.c \
		 ./ft_lstadd_front.c \
		 ./ft_lstsize.c \
		 ./ft_lstlast.c \
		 ./ft_lstadd_back.c \
		 ./ft_lstdelone.c \
		 ./ft_lstclear.c \
		 ./ft_lstiter.c \
		 ./ft_lstmap.c
OBJ = $(SRCS:.c=.o)
OBJ_B = $(SRCS_B:.c=.o)

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
	$(CC) $(CFLAGS) -c -o $@ $<
