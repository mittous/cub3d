/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:12:37 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/16 05:08:50 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_drawing_wall(int ray, double wall_real_height,
					t_data *data, int text)
{
	double	wal_hieght;
	int		start;
	int		end;
	int		dis_from_top;

	if (wall_real_height > WIN_HEIGHT)
		wal_hieght = WIN_HEIGHT;
	else
		wal_hieght = wall_real_height;
	start = (WIN_HEIGHT / 2.0) - (wal_hieght / 2.0);
	end = (WIN_HEIGHT / 2.0) + (wal_hieght / 2.0);
	while (start < end)
	{
		dis_from_top = start + (wall_real_height / 2) - (WIN_HEIGHT / 2);
		data->draw->offset_y = dis_from_top / wall_real_height
			* data->textur->height;
		my_mlx_pixel_put(data->draw, start, ray,
			data->textur[text].addr
		[(data->textur[text].width * data->draw->offset_y)
			+ data->draw->offset_x]);
		start++;
	}
}

int	ft_rgb_to_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	draw_wall_texturs(t_data *sd, int i)
{
	sd->draw->proj_plane = (WIN_WIDTH / 2) / tan(30 * (M_PI / 180));
	sd->draw->wal_hieght = (TILE_SIZE / sd->line->distance)
		* sd->draw->proj_plane;
	sd->draw->wal_start = WIN_HEIGHT / 2 - (sd->draw->wal_hieght / 2);
	sd->draw->wal_end = sd->draw->wal_start + sd->draw->wal_hieght;
	if (sd->line->v_hit == 1)
	{
		sd->draw->offset_x = fmod(sd->line->v_y, TILE_SIZE)
			/ TILE_SIZE * sd->textur->width;
		if (sd->line->ray_right == 1)
			ft_drawing_wall(i, sd->draw->wal_hieght, sd, 1);
		else if (sd->line->ray_left == 1)
			ft_drawing_wall(i, sd->draw->wal_hieght, sd, 2);
	}
	else if (sd->line->h_hit == 1)
	{
		sd->draw->offset_x = fmod(sd->line->h_x, TILE_SIZE)
			/ TILE_SIZE * sd->textur->width;
		if (sd->line->ray_up == 1)
			ft_drawing_wall(i, sd->draw->wal_hieght, sd, 3);
		else if (sd->line->ray_down == 1)
			ft_drawing_wall(i, sd->draw->wal_hieght, sd, 0);
	}
}

void	distance_comper(t_data *sd, double ang)
{
	if (distance(sd->p->x, sd->p->y, sd->line->v_x, sd->line->v_y)
		< distance(sd->p->x, sd->p->y, sd->line->h_x, sd->line->h_y))
	{
		sd->line->h_hit = false;
		sd->line->distance = distance(sd->p->x, sd->p->y, sd->line->v_x,
				sd->line->v_y) * cos(ang - sd->p->angle);
	}
	else if (distance(sd->p->x, sd->p->y, sd->line->v_x, sd->line->v_y)
		> distance(sd->p->x, sd->p->y, sd->line->h_x, sd->line->h_y))
	{
		sd->line->v_hit = false;
		sd->line->distance = distance(sd->p->x, sd->p->y, sd->line->h_x,
				sd->line->h_y) * cos(ang - sd->p->angle);
	}
}

void	ft_raycasting(t_data *sd)
{
	double	ang_inc;
	double	ang;
	int		i;

	i = 0;
	ang_inc = (60 * (M_PI / 180)) / WIN_WIDTH;
	ang = sd->p->angle - (30 * (M_PI / 180));
	sd->draw->offset_x = 0;
	while (i < WIN_WIDTH)
	{
		sd->line->v_hit = false;
		sd->line->h_hit = false;
		ang = fmod(ang, 2 * M_PI);
		if (ang < 0)
			ang += (2 * M_PI);
		line_direction_init(sd->line, ang);
		if (ang != 0 && ang != M_PI)
			ft_horizontal_check(ang, sd);
		if (ang != M_PI / 2 && ang != (1.5 * M_PI))
			ft_vertical_check(sd, ang);
		distance_comper(sd, ang);
		draw_wall_texturs(sd, i);
		ang += ang_inc;
		i++;
	}
}
