/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:56:46 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/16 12:26:10 by imittous         ###   ########.fr       */
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

void	ft_check_map_close(char **map, t_cube *cube)
{
	int	i;
	int	j;

	j = 0;
	cube->map_x = 0;
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
		if (base > 255 && sign == 1)
			ft_putendl_fd("your number is > than 255", 2);
		i++;
	}
	while (str[i] && (str[i] == ' '))
		i++;
	if (!str[i])
		return (base * sign);
	ft_putendl_fd("this format (1 , 2, 3) is not valid, this( 1,2,3)", 2);
	return (0);
}

int	ft_tronsform_int_to_rgb(int count, char *color, int rgb_color)
{
	int		i;
	char	**rgb;

	i = -1;
	if (count == 2)
	{
		rgb = ft_split(color, ',');
		free (color);
		while (rgb[++i])
			if (ft_atoi_cub(rgb[i]) < 0 || ft_atoi_cub(rgb[i]) > 255)
				ft_putendl_fd("color is not valid", 2);
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
