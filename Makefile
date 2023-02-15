NAME =	cub3D

# NAME_BNS = cub3D_bonus

INC =	Mandatory/cub3d.h

# INC_BNS = 

SRC =	Mandatory/main.c \
		Mandatory/struct_init.c\
		Mandatory/check_map_name.c\
		Mandatory/pars1.c\
		Mandatory/errors.c \
		Mandatory/read_from_map.c \
		Utils/get_next_line.c \
		Mandatory/display/draw_game.c\
		Mandatory/display/minimap.c\
		Mandatory/display/utils.c\
		Mandatory/display/p_movment.c\
		Mandatory/display/p_movment2.c\
		Mandatory/display/raycasting.c\
		Mandatory/display/vertical_check.c\
		Mandatory/display/horizontal_check.c\
		Mandatory/display/get_textur.c\
		Utils/get_next_line_utils.c\

BNC_SRC =	Bonus/draw_game_bonus.c\
			Mandatory/main.c \
			Mandatory/struct_init.c\
			Mandatory/check_map_name.c\
			Mandatory/pars1.c\
			Mandatory/errors.c \
			Mandatory/read_from_map.c \
			Utils/get_next_line.c \
			Mandatory/display/minimap.c\
			Mandatory/display/utils.c\
			Mandatory/display/p_movment.c\
			Mandatory/display/p_movment2.c\
			Mandatory/display/raycasting.c\
			Mandatory/display/vertical_check.c\
			Mandatory/display/horizontal_check.c\
			Mandatory/display/get_textur.c\
			Utils/get_next_line_utils.c\

OBJ = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)

OBJ_BNC = $(BNC_SRC:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit

CC = cc

CFLAGS = -Wall  -Wextra -Werror -MMD -g -Ofast #-fsanitize=address 

all : $(NAME)

$(NAME) : $(INC) $(OBJ)
	make bonus -C Utils/libft
	$(CC)  $(OBJ)  $(CFLAGS)  Utils/libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#$(NAME): $(OBJ)
	

 bonus : $(OBJ_BNC)
		make bonus -C Utils/libft
		$(CC)  $(OBJ_BNC)  $(CFLAGS)  Utils/libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
	@-rm -rf $(OBJ) $(OBJ_BNC) $(DEP) $(OBJ_BNC)

fclean : clean
	make fclean -C Utils/libft
	@-rm -rf $(NAME) $(NAME_BNS) $(DEP) $(OBJ_BNC)

re :fclean all

-include $(DEP)