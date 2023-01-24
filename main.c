
#include "cub3d.h"
#include <mlx.h>

void	ft_init(t_cube *cube)
{	
	cube->n = 0;
	cube->one = 0;
	cube->zero = 0;
	cube->player = 0;
	cube->fd = 0;
	cube->map = NULL;
}

int	ft_count_line(char **map)
{
	int	j;

	j = 0;
	while (map[j])
		j++;
	return (j);
}

int	ft_check_up_down_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_count_line(map) - 1;
	while (map[0][i] == '1' || map[0][i] == ' ')
		i++;
	if (i == ft_strlen(map[0]))
	{
		i = 0;
		while (map[j][i] == '1' || map[j][i] == ' ')
			i++;
		if (i == ft_strlen(map[j]))
			return (1);
	}
	ft_putendl_fd("map **is not valid", 2);
	exit (0);
}

void	ft_check_map_close(char **map, t_cube *cube)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (ft_check_up_down_map(map))
	{
		while (map[j])
		{
			i = 0;
			while (map[j][i])
			{
				if (map[j][i] == '0' || map[j][i] == cube->player_char)
				{
					if ((!map[j - 1][i] || map[j - 1][i] == ' ') || (!map[j + 1][i] || map[j + 1][i] == ' ') ||
						(!map[j][i + 1] || map[j][i + 1] == ' ') || (!map[j][i - 1] || map[j][i - 1] == ' '))
					{
						printf ("map is not suround by one");
						exit(0);
					}
				} 

				i++;
			}
			j++;
		}
	}
	printf ("map is-- valid\n");
}

int	ft_atoi_cub(const char *str)
{
	int	i;
	int	sign;
	int	base;

	sign = 1;
	i = 0;
	base = 0;
	while (str[i] && (str[i] == ' '))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		base = (base * 10) + (str[i] - 48);
		i++;
	}
	while (str[i] && (str[i] == ' '))
		i++;
	if (!str[i])
		return (base * sign);
	ft_putendl_fd("this format (1 2 2,) is not valid, fix it to this( 122 ,)", 2);
	exit (EXIT_FAILURE) ;
}


char *ft_count_coma(char	*color /* t_cube *cub */)
{
	int		i;
	int		count;
	char	**rgb;

	i = 0;
	count = 0;
	while (color[i])
	{
		if (ft_isdigit(color[i]))
		{
			if (color[i] == ',')
				count++;
		}
		else
		{
			ft_putendl_fd("Non digit information for colors", 2);
			exit (0);
		}
		i++;
	}
	i = 0;
	// int j = 0;
	if (count == 2)
	{
		rgb = ft_split(color, ',');
		while (rgb[i])
		{
			// int nb = ft_atoi_cub(rgb[i]);
			rgb[i] = ft_strtrim(rgb[i], " ");
			int nb = ft_atoi_cub(rgb[i]);
			if (nb < 0 || nb > 255)
			{
				ft_putendl_fd("color is not valid", 2);
				exit (0);
			}
			rgb[i] = ft_strjoin(rgb[i], ",");
			i++;
		}
		if (rgb[0] && rgb[1] && rgb[2])
		{
			color = ft_strjoin(rgb[0], rgb[1]);
			color = ft_strjoin(color, rgb[2]);
			return (color);
		}
	}
	ft_putendl_fd("color is not valid", 2);
	exit (0);
}

void	ft_check_texture(t_cube *cub)
{
	int		i;
	char	**path;
	int		fd;

	i = 0;
	while (cub->texture[i])
	{
		path = ft_split (cub->texture[i], ' ');
		if (path[1] && !path[2])
		{
			int j = 2;
			while (path[j])
			{
				path[1] = ft_strjoin(path[1], path[j]);
				j++;
			}
			if (!ft_isdigit(path[1][0]))
			{
				fd = open(path[1], O_RDWR);
				if (fd == -1)
				{
					printf ("%s\n", path[0]);
					printf("texture file is not valid");
					exit(0);
				}
			}
			if (!ft_strcmp(path[0], "NO"))
				cub->no = path[1];
			else if (!ft_strcmp(path[0], "SO"))
				cub->so = path[1];
			else if (!ft_strcmp(path[0], "WE"))
				cub->we = path[1];
			else if (!ft_strcmp(path[0], "EA"))
				cub->ea = path[1];
			else if (!ft_strcmp(path[0], "C"))
			{
				
				cub->ceiling = ft_count_coma(path[1]);
			}
			else if (!ft_strcmp(path[0], "F"))
				cub->floor = path[1];
			else
			{
				ft_putendl_fd("Invalide identefire", 2);
				exit (0);
			}
		}
		else
		{
			ft_putendl_fd("An information of more or lesse lement than two", 2);
			exit (0);
		}
		i++;
	}
	if (!cub->no || !cub->so || !cub->we || !cub->ea || !cub->ceiling || !cub->floor)
	{
		ft_putendl_fd("An information of one/more element is messing", 2);
		exit (0);
	}
}





int	main(int ac, char **av)
{
	t_cube	cube;
	t_data	game;
	t_display win;
	t_player	p;

	if (ft_checkber(av[1], ac))
	{
		ft_init(&cube);
		cube.fd = open(av[1], O_RDONLY);
		if (cube.fd < 0)
		{
			printf("file is not valid");
			return 1;
		}
		get_next_line(cube.fd, &cube);
		ft_check_texture(&cube);
		ft_check_map_close (cube.map, &cube);
		game.win = &win;
		p_init(&p);
		game.cube = &cube;
		game.p = &p;
		game.win->mlx_ptr = mlx_init();
    	game.win->window = mlx_new_window(game.win->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
		p_search(&game, &cube);
		mlx_hook(game.win->window, 2, 1L << 1, key_hook, &game);
		mlx_hook(game.win->window, 3, 2L << 0, key_rel, &game);
		mlx_loop_hook(game.win->mlx_ptr, draw_2d_map, &game);
		// printf("##################\n");
		// mlx_hook(game.win, 17, 0, ft_exit, &game);
		// draw_2d_map(&game);
		mlx_loop(game.win->mlx_ptr);
	}
}
