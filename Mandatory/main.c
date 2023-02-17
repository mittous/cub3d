/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 06:51:24 by imittous          #+#    #+#             */
/*   Updated: 2023/02/17 14:27:45 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		cub->no = ft_strdup(path[1]);
	else if (!ft_strcmp(path[0], "SO") && ft_check_file_exist(path[1]))
		cub->so = ft_strdup(path[1]);
	else if (!ft_strcmp(path[0], "WE") && ft_check_file_exist(path[1]))
		cub->we = ft_strdup(path[1]);
	else if (!ft_strcmp(path[0], "EA") && ft_check_file_exist(path[1]))
		cub->ea = ft_strdup(path[1]);
	else if (!ft_strcmp(path[0], "C"))
		cub->ceiling = ft_count_coma(ft_strdup(path[1]));
	else if (!ft_strcmp(path[0], "F"))
		cub->floor = ft_count_coma(ft_strdup(path[1]));
	else
	{
		ft_putendl_fd("Invalide identefire", 2);
	}
}

void	ft_check_texture(t_cube *cub)
{
	int		i;
	char	**path;

	cub->ceiling = -1;
	cub->floor = -1;
	i = -1;
	while (cub->texture[++i])
	{
		path = ft_split (cub->texture[i], ' ');
		if (path[1] && !path[2])
		{
			ft_fill_infos(cub, path);
			free_word(path);
		}
	}
	if (cub->ceiling == -1 || cub->floor == -1 || !cub->no || !cub->so \
		|| !cub->we || !cub->ea)
	{
		ft_putendl_fd("check that you have all (6) informations needed", 2);
	}
}

int	main(int ac, char **av)
{
	t_data	*game;

	game = allocate_data();
	if (game && ft_checkber(av[1], ac))
	{
		ft_memset(game->cube, 0, sizeof(t_cube));
		game->cube->fd = open(av[1], O_RDONLY);
		if (game->cube->fd < 0)
			ft_putendl_fd("file is not valid", 2);
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
		start_game(game);
	}
	return (0);
}
