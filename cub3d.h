
#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/fcntl.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
// # include "../get_next_line/get_next_line.h"

# define BUFFER_SIZE 1
# define WIN_HEIGHT 450
# define WIN_WIDTH 1920
# define TILE_SIZE 30
# define speed 3.0
# define PLAYER_SQUARE 2
# define WHITE 16777215
# define BLACK 8421504
# define RED 16711680
# define ORANGE 65454456
# define RAD 0.01745329251

typedef struct	s_player {
	int		x;
	int		y;
	double		move_speed;
	double		retation_angle;
	double		angle;
	double		retation_speed;
}				t_player;

typedef struct	draw {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}				t_draw;
typedef struct s_display
{
	void	*mlx_ptr;
	void	*window;
	void	*wall;
	void	*eps;
	void	*image;
} 			t_display;
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

typedef struct	s_data {
	t_player	*p;
	t_draw		*draw;
	t_display	*win;
	t_cube		*cube;
}				t_data;




int		mini_check(char map);
int		ft_checkber(char *s, int ac);
// char	*get_next_line(int fd/* , t_cube *cube, int check */);
void	ft_wrong_character_err(char bufer);
void	ft_messing_character_err(char *message);
void	get_next_line(int fd, t_cube *cube);
char	**ft_split_gnl(char const *s, char c);
void	ft_count_char(char c, t_cube *cube);
void	ft_wrong_character_err(char s);
///////////////////
int draw_2d_map(t_data *sd);
int	key_hook(int key, t_data *sd);
void p_search(t_data *sd, t_cube *cube);
void   p_init(t_player *p);
void ft_draw_line(t_data    *sd , int len);
void	my_mlx_pixel_put(t_draw *data, int y, int x, int color);

#endif