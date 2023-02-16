/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 06:51:24 by imittous          #+#    #+#             */
/*   Updated: 2023/02/16 17:19:12 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_count_line(char **map, t_cube *cube)
{
	int	j;

	j = 0;
	while (map[j])
		j++;
	cube->map_y = j;
	return (j);
}

int	ft_check_up_down_map(char **map, t_cube *cube)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_count_line(map, cube) - 1;
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
	return (0);
}

int	ft_check_rdlu_space(char **map, int i, int j)
{
	if ((!map[j - 1][i] || map[j - 1][i] == ' ')
		|| (!map[j + 1][i] || map[j + 1][i] == ' ')
		|| (!map[j][i + 1] || map[j][i + 1] == ' ')
		|| (!map[j][i - 1] || map[j][i - 1] == ' '))
	{
		return (1);
	}
	return (0);
}

void	ft_check_map_close(char **map, t_cube *cube)
{
	int	i;
	int	map_x;
	int	j;

	i = 0;
	
	j = 0;
	cube->map_x = 0;
	if (ft_check_up_down_map(map, cube))
	{
		while (map[j])
		{
			i = 0;
			while (map[j][i])
			{
				if (map[j][i] == '0' || map[j][i] == cube->player_char)
					if (ft_check_rdlu_space(map, i, j))
						ft_putendl_fd("map is not suround by one", 2);
				
				i++;
				if (cube->map_x < i)
					cube->map_x = i;
			}
			j++;
		}
	}
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
		if (base > 2147483647 && sign == 1)
			ft_putendl_fd("your number is > than 255", 2);
		i++;
	}
	while (str[i] && (str[i] == ' '))
		i++;
	if (!str[i])
		return (base * sign);
	ft_putendl_fd("this format (1 , 2, 3) is not valid, this ( 1,2,3) yes", 2);
	return (0);
}

int ft_tronsform_int_to_rgb(int count, char *color, int rgb_color)
{
	int		i;
	char	**rgb;

	i = -1;
	if (count == 2)
	{
		rgb = ft_split(color, ',');
		while (rgb[++i])
		{
			rgb[i] = ft_strtrim(rgb[i], " ");
			if (ft_atoi_cub(rgb[i]) < 0 || ft_atoi_cub(rgb[i]) > 255)
			{
				ft_putendl_fd("color is not valid", 2);
			}
		}
		if (rgb[0] && rgb[1] && rgb[2])
		{
			rgb_color = ft_rgb_to_color(ft_atoi_cub(rgb[0]), \
				ft_atoi_cub(rgb[1]), ft_atoi_cub(rgb[2]));
			//free_word(rgb);
			return (rgb_color);
		}
	}
	ft_putendl_fd("color is not valid", 2);
	return (0);
}

int	ft_count_coma(char	*color)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (color[++i])
	{
		if (ft_isdigit(color[i]))
		{
			if (color[i] == ',')
				count++;
		}
		else
		{
			ft_putendl_fd("Non digit information for colors", 2);
		}
	}
	return (ft_tronsform_int_to_rgb(count, color, 0));
}

int	ft_check_file_exist(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("texture file is not exist\n", 2);
	}
	return (fd);
}

void	ft_fill_infos(t_cube *cub, char **path)
{
	if (!ft_strcmp(path[0], "NO") && ft_check_file_exist(path[1]))
		cub->no = path[1];
	else if (!ft_strcmp(path[0], "SO") && ft_check_file_exist(path[1]))
		cub->so = path[1];
	else if (!ft_strcmp(path[0], "WE") && ft_check_file_exist(path[1]))
		cub->we = path[1];
	else if (!ft_strcmp(path[0], "EA") && ft_check_file_exist(path[1]))
		cub->ea = path[1];
	else if (!ft_strcmp(path[0], "C"))
	{
		cub->ceiling = ft_count_coma(path[1]);
		//free_word(path);
	}
	else if (!ft_strcmp(path[0], "F"))
	{
		cub->floor = ft_count_coma(path[1]);
		//free_word(path);
	}
	else
	{
		ft_putendl_fd("Invalide identefire", 2);
	}
}

void	ft_check_texture(t_cube *cub)
{
	int		i;
	char	**path;

	i = -1;
	while (cub->texture[++i])
	{
		path = ft_split (cub->texture[i], ' ');
		if (path[1] && !path[2])
			ft_fill_infos(cub, path);
		else
		{
			ft_putendl_fd("you may have space in the middele of the info", 2);
		}
	}
}

int ft_exit(t_data *game)
{
	int	i;

	i = -1;
	while (game->cube->texture[++i])
		//free(game->cube->texture[i]);
	//free(game->cube->texture);
	i = -1;
	while (game->cube->map[++i])
		//free(game->cube->map[i]);
	//free(game->cube->map);
	//free(game->cube);
	//free(game->win);
	//free(game->draw);
	//free(game);
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	*game;

	game = allocate_data();
	if (ft_checkber(av[1], ac))
	{
		ft_memset(game->cube, 0, sizeof(t_cube));
		game->cube->fd = open(av[1], O_RDONLY);
		if (game->cube->fd < 0)
		{
			printf("file is not valid");
			return (1);
		}
		game->win->mlx_ptr = mlx_init();
		game->draw->img = mlx_new_image(game->win->mlx_ptr, WIN_WIDTH,
				WIN_HEIGHT);
		game->draw->addr = mlx_get_data_addr(game->draw->img,
				&game->draw->bits_per_pixel, &game->draw->line_length,
				&game->draw->endian);
		get_next_line_cub(game->cube->fd, game->cube);
		ft_check_texture(game->cube);
		ft_check_map_close (game->cube->map, game->cube);
		p_init(game->p);
		ft_get_textur(game);
    	game->win->window = mlx_new_window(game->win->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
		p_search(game, game->cube);
		mlx_hook(game->win->window, 2, 1L << 1, key_hook, &game);
		mlx_hook(game->win->window, 3, 2L << 0, key_rel, &game);
		mlx_loop_hook(game->win->mlx_ptr, draw_2d_map, &game);
		// printf("##################\n");
		// mlx_hook(game->win, 17, 0, ft_exit, &game);
		// draw_2d_map(&game);
		mlx_loop(game->win->mlx_ptr);
	}
}
