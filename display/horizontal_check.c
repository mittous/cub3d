/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:34:29 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/14 06:49:06 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_horizontal_check(double ang, t_data *sd)
{
	double	y_intercept;
	double	x_intercept;
	double	dx;
	double	dy;

	y_intercept = floor(sd->p->y / TILE_SIZE) * TILE_SIZE;
	if (sd->line->ray_down == 1)
		y_intercept += 30;
	x_intercept = sd->p->x + (y_intercept - sd->p->y) / tan(ang);
	sd->line->h_x = x_intercept;
	sd->line->h_y = y_intercept;
	dy = TILE_SIZE;
	if (sd->line->ray_up == 1)
		dy *= -1;
	dx = TILE_SIZE / tan(ang);
	if (sd->line->ray_left == 1 && dx > 0)
		dx *= -1;
	if (sd->line->ray_right == 1 && dx < 0)
		dx *= -1;
	while (sd->line->h_x >= 0 && sd->line->h_x <= (sd->cube->map_x * 30)
		&& sd->line->h_y >= 0 && sd->line->h_y <= (sd->cube->map_y * 30))
	{
		if (sd->line->ray_up == 1)
		{
			if(sd->cube->map[(int)((sd->line->h_y - 1) / TILE_SIZE)] 
				&& (int)(ft_strlen(sd->cube->map[(int)((sd->line->h_y - 1) / TILE_SIZE)])) > (int)((sd->line->h_x) / TILE_SIZE)
				&& sd->cube->map[(int)((sd->line->h_y - 1) / TILE_SIZE)][(int)((sd->line->h_x) / TILE_SIZE)] == '1')
			{
				sd->line->h_hit = true;
				break ;
			}
		}
		if(sd->cube->map[(int)((sd->line->h_y) / TILE_SIZE)] 
			&& (int)(ft_strlen(sd->cube->map[(int)((sd->line->h_y) / TILE_SIZE)])) > (int)((sd->line->h_x) / TILE_SIZE)
			&& sd->cube->map[(int)((sd->line->h_y) / TILE_SIZE)][(int)((sd->line->h_x) / TILE_SIZE)] == '1')
		{
			sd->line->h_hit = true;
			break ;
		}
		sd->line->h_x += dx;
		sd->line->h_y += dy;
	}
}
