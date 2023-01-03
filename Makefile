NAME =	cub3D

# NAME_BNS = cub3D_bonus

INC =	cub3d.h

# INC_BNS = 

SRC =	main.c \
		check_map_name.c \
		errors.c \
		read_from_map.c \

# BNC_SRC =

OBJ = $(SRC:.c=.o)

OBJ_BNC = $(BNC_SRC:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit

CC = cc

CFLAGS = -Wall  -Wextra -g -fsanitize=address #-Werror

all : $(NAME)

$(NAME) : $(INC) $(OBJ)
	make bonus -C libft/
	$(CC) $(CFLAGS) $(SRC) libft/libft.a $(MLX) -o $(NAME)

# bonus : $(NAME_BNS)

clean : 
	@-rm -rf $(OBJ) $(OBJ_BNC)

fclean : clean
	make fclean -C libft
	@-rm -rf $(NAME) $(NAME_BNS)

re :fclean all