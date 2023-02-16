/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:46:47 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/16 09:17:06 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	p_search(t_data *sd, t_cube *cube, int i, int j)
{
	while (sd->cube->map[i])
	{
		j = 0;
		while (sd->cube->map[i][j])
		{
			if (sd->cube->map[i][j] == cube->player_char)
			{
				if (sd->cube->map[i][j] == 'N')
					sd->p->angle = (3 * M_PI) / 2;
				if (sd->cube->map[i][j] == 'S')
					sd->p->angle = M_PI / 2;
				if (sd->cube->map[i][j] == 'W')
					sd->p->angle = M_PI;
				if (sd->cube->map[i][j] == 'E')
					sd->p->angle = 0;
				sd->cube->map[i][j] = '0';
				sd->p->x = (j * TILE_SIZE) + (TILE_SIZE / 2);
				sd->p->y = (i * TILE_SIZE) + (TILE_SIZE / 2);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	p_init(t_player *p)
{
	p->x = 0;
	p->y = 0;
	p->move_speed = SPEED;
	p->retation_angle = M_PI / 6;
	p->retation_speed = 3 * (M_PI / 180);
	p->move_right = 0;
	p->move_up = 0;
	p->rotation = 0;
}

void	ft_draw_line(t_data *sd, double x2, double y2, int i)
{
	double	dx;
	double	dy;
	double	x;
	double	y;
	int		steps;

	x = sd->p->x;
	y = sd->p->y;
	dx = x2 - x;
	dy = y2 - y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	while (i <= (int)steps)
	{
		my_mlx_pixel_put(sd->draw, y, x, RED);
		x += dx / steps;
		y += dy / steps;
		i++;
	}
}

double	distance(double x1, double y1, double x2, double y2)
{
	double	x_diff;
	double	y_diff;

	x_diff = x2 - x1;
	y_diff = y2 - y1;
	return (sqrt(x_diff * x_diff + y_diff * y_diff));
}

void	line_direction_init(t_line *line, double angle)
{
	line->ray_up = 0;
	line->ray_down = 0;
	line->ray_left = 0;
	line->ray_right = 0;
	if ((angle > 0) && (angle < M_PI))
	{
		line->ray_up = 0;
		line->ray_down = 1;
	}
	else
	{
		line->ray_up = 1;
		line->ray_down = 0;
	}
	if ((angle > (1.5 * M_PI)) || (angle < (0.5 * M_PI)))
	{
		line->ray_right = 1;
		line->ray_left = 0;
	}
	else
	{
		line->ray_right = 0;
		line->ray_left = 1;
	}
}
