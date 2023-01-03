
#include "cub3d.h"

void	ft_init(t_cube *cube, t_char_map *char_map)
{	
	char_map->read_ret = 1;
	char_map->n = 0;
	char_map->s = 0;
	char_map->e = 0;
	char_map->w = 0;
	char_map->one = 0;
	char_map->zero = 0;
	cube->fd = 0;
	cube->map = NULL;
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
		else
			cube.map = ft_split(get_next_line(cube.fd, char_map), '\n');
	}
}
