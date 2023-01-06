
#include "cub3d.h"

void	ft_init(t_cube *cube, t_char_map *char_map)
{	
	char_map->n = 0;
	char_map->one = 0;
	char_map->zero = 0;
	char_map->player = 0;
	cube->fd = 0;
	cube->map = NULL;
}

void	ft_check_map_close(char **map)
{
	int	i;
	int j;

	i = 1;
	j = 1;
	printf ("--*-%c\n", map[0][0]);
	while (map[j + 1])
	{
		puts ("dkhlna hna");
		while (map[j][i + 1])
		{
			if (!map[j - 1][i] || !map[j + 1][i] || !map[j][i + 1] || !map[j][i - 1])
			{
				printf ("map is not suround by one ");
				exit(0);
			}
			i++;
		}
		j++;
	}
	printf ("map is valid");
}

int	main(int ac, char **av)
{
	t_cube	cube;
	t_char_map	char_map;

	if (ft_checkber(av[1], ac))
	{
		ft_init(&cube, &char_map);
		cube.fd = open(av[1], O_RDONLY);
		if (cube.fd == -1)
			printf("file is not valid");
			// printf ("%s", get_next_line(cube.fd, &char_map));
			cube.map = ft_split(get_next_line(cube.fd, &char_map) , '\n');
			// 	printf ("--*-%s\n", cube.map[0]);

		ft_check_map_close (cube.map);
	}
}

