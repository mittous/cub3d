NAME =	cub3D

NAME_BNS = cub3D_bonus

INC =	Mandatory/cub3d.h

# INC_BNS = 

SRC =	Mandatory/main.c \
		Mandatory/struct_init.c\
		Mandatory/check_map_name.c\
		Mandatory/pars1.c\
		Mandatory/errors.c \
		Mandatory/read_from_map.c \
		Utils/gnl/get_next_line.c\
		Mandatory/display/draw_game.c\
		Mandatory/display/utils.c\
		Mandatory/display/p_movment.c\
		Mandatory/display/p_movment2.c\
		Mandatory/display/raycasting.c\
		Mandatory/display/vertical_check.c\
		Mandatory/display/horizontal_check.c\
		Mandatory/display/get_textur.c\
		Utils/gnl/get_next_line_utils.c\

BNC_SRC =	Bonus/draw_game_bonus.c\
			Bonus/main.c \
			Bonus/struct_init.c\
			Bonus/check_map_name.c\
			Bonus/pars1.c\
			Bonus/errors.c \
			Bonus/read_from_map.c \
			Utils/gnl/get_next_line_utils.c\
			Bonus/display/minimap.c\
			Bonus/display/utils.c\
			Bonus/display/p_movment.c\
			Bonus/display/p_movment2.c\
			Bonus/display/raycasting.c\
			Bonus/display/vertical_check.c\
			Bonus/display/horizontal_check.c\
			Bonus/display/get_textur.c\
			Utils/gnl/get_next_line.c\

OBJ = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)

OBJ_BNC = $(BNC_SRC:.c=.o)

DEP_B = $(BNC_SRC:.c=.d)

MLX = -lmlx -framework OpenGL -framework AppKit

CC = cc

CFLAGS = -Wall  -Wextra -Werror -MMD -g -Ofast #-fsanitize=address 

all : $(NAME)

$(NAME) : $(INC) $(OBJ)
	make bonus -C Utils/libft
	$(CC)  $(OBJ)  $(CFLAGS)  Utils/libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : $(OBJ_BNC)
		make bonus -C Utils/libft
		$(CC)  $(OBJ_BNC)  $(CFLAGS)  Utils/libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME_BNS)

$(NAME_BNS) : $(INC) $(OBJ_BNC)
	make bonus -C Utils/libft
	$(CC)  $(OBJ_BNC)  $(CFLAGS)  Utils/libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME_BNS)
	
clean : 
	@-rm -rf $(OBJ) $(OBJ_BNC) $(DEP) $(OBJ_BNC) $(DEP_B)

fclean : clean
	make fclean -C Utils/libft
	@-rm -rf $(NAME) $(NAME_BNS) $(DEP) $(OBJ_BNC) $(DEP_B)

re :fclean all

-include $(DEP) $(DEP_B)
