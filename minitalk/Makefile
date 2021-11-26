SERVER 		=	server
CLIENT 		=	client

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

LIB_DIR		=	libft
LIB			=	$(LIB_DIR)/libft.a


all: $(LIB) $(SERVER) $(CLIENT)

$(LIB) :
	@make -C $(LIB_DIR)

$(SERVER): $(SERVER).o
	@$(CC) $(CFLAGS) $(SERVER).o -o $(SERVER) $(LIB)
	
$(CLIENT): $(CLIENT).o
	@$(CC) $(CFLAGS) $(CLIENT).o -o $(CLIENT) $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIB_DIR) clean
	@rm -rf $(SERVER).o $(CLIENT).o

fclean:
	@make -C $(LIB_DIR) fclean
	@rm -rf $(SERVER) $(CLIENT) $(SERVER).o $(CLIENT).o

re: fclean all

.PHONY: all clean fclean re
