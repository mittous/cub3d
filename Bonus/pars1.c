/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:56:46 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/18 10:45:05 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	ft_count_longest_line(t_cube *cube)
{
	int	i;
	int	j;

	j = 0;
	cube->map_x = 0;
	while (cube->map[j])
	{
		i = -1;
		while (cube->map[j][++i])
		{
			if (cube->map_x < i)
				cube->map_x = i;
		}
		j++;
	}
}

void	ft_fill_map_with_space(t_cube *cube)
{
	int	i;
	int	j;

	j = 0;
	while (cube->map[j])
	{
		i = ft_strlen(cube->map[j]);
		while (i <= cube->map_x)
		{
			cube->map[j] = ft_strjoin(cube->map[j], " ");
			i++;
		}
		if (!ft_strchr(cube->map[j], '1'))
			ft_putendl_fd("new line in map", 2);
		j++;
	}
}

void	ft_check_map_close(char **map, t_cube *cube)
{
	int	i;
	int	j;

	j = 0;
	cube->map_x = 0;
	ft_count_longest_line(cube);
	ft_fill_map_with_space(cube);
	if (ft_check_up_down_map(map, cube))
	{
		while (map[j])
		{
			i = -1;
			while (map[j][++i])
			{
				if (map[j][i] == '0' || map[j][i] == cube->player_char)
					if ((!map[j - 1][i] || map[j - 1][i] == ' ')
						|| (!map[j + 1][i] || map[j + 1][i] == ' ')
						|| (!map[j][i + 1] || map[j][i + 1] == ' ')
						|| (!map[j][i - 1] || map[j][i - 1] == ' '))
						ft_putendl_fd("map is not suround by one", 2);
			}
			j++;
		}
	}
}
