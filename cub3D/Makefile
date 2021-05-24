CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = cub3D
INCLUDE_DIRS =	includes \
				parsing \
				executing 
INCLUDES = $(addprefix -I, $(INCLUDE_DIRS))
SRCS=	./parsing/text_extract.c \
	   	./parsing/ft_parse_cub.c \
	   	./parsing/ft_parse_resolution.c \
	   	./parsing/ft_parse_textures.c \
	   	./parsing/ft_parse_textures2.c \
	   	./parsing/ft_parse_rgbs.c \
		./parsing/ft_parse_map.c \
		./parsing/ft_parse_map2.c \
		./parsing/ft_parse_utils.c \
		./parsing/ft_parse_utils2.c \
		./executing/ft_init.c \
		./executing/ft_init2.c \
		./executing/ft_initdestroyimg.c \
		./executing/update_sprites.c \
		./executing/cast_rays_horizontal.c \
		./executing/cast_rays_vertical.c \
		./executing/horiz_vert_raycomp.c \
		./executing/start_game_utils.c \
		./executing/start_game_utils2.c \
		./executing/start_game_utils3.c \
		./executing/color_utils.c \
		./executing/start_game.c \
		./executing/events.c \
		./executing/update.c \
		./executing/cast_rays.c \
		./executing/ft_prepare_lines.c \
		./executing/lines.c \
		./executing/draw.c \
		./executing/bitmap_offsets.c \
		./executing/bmp_screenshot.c \
		./utils.c \
		./cub3d.c 
OBJS = $(SRCS:.c=.o)


all : libft minilibx $(NAME) 

libft :
	make -C libft/

minilibx :
	make -C minilibx/

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(INCLUDES)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -Lminilibx/ -lmlx -framework OpenGL -framework AppKit -Llibft/ -lft -o $@ $(INCLUDES)

clean :
	rm -f $(OBJS)
	$(MAKE) -C libft/ clean
	$(MAKE) -C minilibx/ clean

fclean : clean
		rm -f $(NAME)
	$(MAKE) -C libft/ fclean

re : fclean all

.PHONY: libft minilibx all bonus clean fclean re
