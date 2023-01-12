
#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
// # include  <mlx.h>
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
	char	**texture;
	int		fd;
	int		one;
	int		zero;
	int		player;
	char	player_char;
	int		n;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*floor;
	char	*ceiling;
}				t_cube;

int		mini_check(char map);
int		ft_checkber(char *s, int ac);
char	*get_next_line(int fd, t_cube *cube, int check);
void	ft_wrong_character_err(char bufer);
void	ft_messing_character_err(char *message);

#endif