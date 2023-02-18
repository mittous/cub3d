/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:56:19 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/18 11:01:16 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	vertical_hit_facing(t_data	*sd, int i)
{
	if (sd->line->ray_right == 1)
	{
		sd->draw->offset_x = fmod(sd->line->v_y, TILE_SIZE)
			/ TILE_SIZE * sd->textur[1].width;
		ft_drawing_wall(i, sd->draw->wal_hieght, sd, 1);
	}
	else if (sd->line->ray_left == 1)
	{
		sd->draw->offset_x = fmod(sd->line->v_y, TILE_SIZE)
			/ TILE_SIZE * sd->textur[2].width;
		ft_drawing_wall(i, sd->draw->wal_hieght, sd, 2);
	}
}

void	horizontal_hit_facing(t_data	*sd, int i)
{
	if (sd->line->ray_up == 1)
	{
		sd->draw->offset_x = fmod(sd->line->h_x, TILE_SIZE)
			/ TILE_SIZE * sd->textur[3].width;
		ft_drawing_wall(i, sd->draw->wal_hieght, sd, 3);
	}
	else if (sd->line->ray_down == 1)
	{
		sd->draw->offset_x = fmod(sd->line->h_x, TILE_SIZE)
			/ TILE_SIZE * sd->textur[0].width;
		ft_drawing_wall(i, sd->draw->wal_hieght, sd, 0);
	}
}
