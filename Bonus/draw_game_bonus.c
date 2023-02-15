/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:57:49 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/15 13:59:04 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/cub3d.h"

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
	draw_mini_map(*sd, i, j);
	ft_move((*sd));
	mlx_put_image_to_window((*sd)->win->mlx_ptr, (*sd)->win->window,
		(*sd)->draw->img, 0, 0);
	return (0);
}