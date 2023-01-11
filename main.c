
#include "cub3d.h"

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
	ft_putendl_fd("map is not valid", 2);
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
	printf ("map is valid");
}

void	ft_check_texture(t_cube *cub)
{
	int		i;
	char	**path;

	i = 0;
	while (cub->texture[i])
	{
		path = ft_split (cub->texture[i], ' ');
		if (ft_isalpha(path[1][0]))
		{
			cub->fd = open(path[1], O_RDONLY);
			if (cub->fd == -1)
			{
				printf("texture file is not valid");
				exit(0);
			}
		}
		if (path[0][0] == 'N' && path[0][1] == 'O')
		{
			// puts("dkhlna hna");
			cub->no = path[1];
		}
		else if (path[0][0] == 'S' && path[0][1] == 'O')
			cub->so = path[1];
		else if (path[0][0] == 'W' && path[0][1] == 'E')
			cub->we = path[1];
		else if (path[0][0] == 'E' && path[0][1] == 'A')
			cub->ea = path[1];
		else if (path[0][0] == 'C' && path[0][1] == '\0')
		{
			puts ("dkhlna hna");
			cub->ceiling = path[1];
		}
		else if (path[0][0] == 'F' && path[0][1] == '\0')
			cub->floor = path[1];
		else
		{
			ft_putendl_fd("Invalide identefire", 2);
			exit (0);
		}
		// free path here/
		i++;
	}
}

int	main(int ac, char **av)
{
	t_cube	cube;

	if (ft_checkber(av[1], ac))
	{
		ft_init(&cube);
		cube.fd = open(av[1], O_RDONLY);
		if (cube.fd == -1)
		{
			printf("file is not valid");
		}
			// printf ("%s", get_next_line(cube.fd, &cube));
			// printf ("%s", get_next_line(cube.fd, &cube));
			// cube.map = ft_split(get_next_line(cube.fd, &cube) , '\n');
			cube.texture = ft_split(get_next_line(cube.fd, &cube) , '\n');
			// 	printf ("--*-%s\n", cube.map[0]);
			// int i = 0, j = 0;
			// while (cube.map[j])
			// {
			// 	printf ("%s\n", cube.map[j]);
			// 	j++;
			// }
			ft_check_texture(&cube);
		// ft_check_map_close (cube.map, &cube);
	}
}

