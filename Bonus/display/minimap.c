/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:43:47 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/16 09:15:57 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	print_player(t_data *sd)
{
	sd->p->x_cube = sd->p->x;
	sd->p->y_cube = sd->p->y;
	sd->p->x_cube = sd->p->x -3;
	while (sd->p->x_cube < sd->p->x + 3)
	{
		sd->p->y_cube = sd->p->y -3;
		while (sd->p->y_cube < sd->p->y + 3)
		{
			my_mlx_pixel_put(sd->draw, MINI_MAPE * (sd->p->y_cube),
				MINI_MAPE * (sd->p->x_cube), RED);
			sd->p->y_cube++;
		}
		sd->p->x_cube++;
	}
}

void	print_pixel(t_data *sd, int x, int y, int color)
{
	int	i;
	int	j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while ((MINI_MAPE * i) < (MINI_MAPE * TILE_SIZE))
	{
		j = 0;
		while ((MINI_MAPE * j) < (MINI_MAPE * TILE_SIZE))
		{
			my_mlx_pixel_put(sd->draw, MINI_MAPE * (y + j),
				MINI_MAPE * (x + i), color);
			j++;
		}
		i++;
	}
	print_player(sd);
}

void	draw_mini_map(t_data	*data, int i, int j)
{
	while (data->cube->map[i])
	{
		j = 0;
		while (data->cube->map[i][j])
		{
			if (data->cube->map[i][j] == '1')
				print_pixel(data, j, i, BLACK);
			else if (data->cube->map[i][j] == '0')
				print_pixel(data, j, i, WHITE);
			j++;
		}
		i++;
	}
}
