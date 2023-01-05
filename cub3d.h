
#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include  <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/fcntl.h>
# include "libft/libft.h"
// # include "../get_next_line/get_next_line.h"

# define WIN_HEIGHT 720
# define WIN_WIDTH 1080
# define TILE_SIZE 10
# define PLAYER_SQUARE 2
# define WHITE 16777215
# define BLACK 8421504
# define RED 16711680
# define ORANGE 65454456
# define RAD 0.01745329251



typedef struct s_cube
{
	char	**map;
	int		fd;
}				t_cube;

typedef struct s_char_map
{
	int		one;
	int		zero;
	int		player;
	int		n;
	int 	read_ret;
}				t_char_map;

int		mini_check(char map);
int		ft_checkber(char *s, int ac);
char	*get_next_line(int fd, t_char_map char_map);
void	ft_wrong_character(char bufer);
void	ft_messing_character(char *message);

#endif