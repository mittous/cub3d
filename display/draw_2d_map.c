/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:21:03 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/14 10:10:44 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include  <mlx.h>

void	my_mlx_pixel_put(t_draw *data, int y, int x, int color)
{
	char	*dst;

	if (y >= 0 && y < WIN_HEIGHT && x < WIN_WIDTH && x >= 0)
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

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

void	ft_clear_image(t_data *test)
{
	int	i;
	int	j;

	i = 0;
	while ((i < WIN_HEIGHT))
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			if (i < WIN_HEIGHT / 2)
				my_mlx_pixel_put(test->draw, i, j, test->cube->ceiling);
			else
				my_mlx_pixel_put(test->draw, i, j, test->cube->floor);
			j++;
		}
		i++;
	}
}

int	draw_2d_map(t_data **sd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window((*sd)->win->mlx_ptr, (*sd)->win->window);
	ft_clear_image((*sd));
	ft_raycasting((*sd));
	while ((*sd)->cube->map[i])
	{
		j = 0;
		while ((*sd)->cube->map[i][j])
		{
			if ((*sd)->cube->map[i][j] == '1')
				print_pixel((*sd), j, i, BLACK);
			else if ((*sd)->cube->map[i][j] == '0')
				print_pixel((*sd), j, i, WHITE);
			j++;
		}
		i++;
	}
	ft_move((*sd));
	mlx_put_image_to_window((*sd)->win->mlx_ptr, (*sd)->win->window,
		(*sd)->draw->img, 0, 0);
	return (0);
}
