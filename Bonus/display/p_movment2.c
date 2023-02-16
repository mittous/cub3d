/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_movment2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:09:46 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/16 09:16:49 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_move_right(t_data **sd)
{
	int	x;
	int	y;

	y = ((*sd)->p->y - (sin((*sd)->p->angle - M_PI / 2)
				* (*sd)->p->move_speed)) / TILE_SIZE;
	if ((*sd)->cube->map[y][(int)(*sd)->p->x / TILE_SIZE] != '1')
	{
		(*sd)->p->y -= sin((*sd)->p->angle - M_PI / 2) * (*sd)->p->move_speed;
	}
	x = ((*sd)->p->x - (cos((*sd)->p->angle - M_PI / 2)
				* (*sd)->p->move_speed)) / TILE_SIZE;
	if ((*sd)->cube->map[(int)(*sd)->p->y / TILE_SIZE][x] != '1')
	{
		(*sd)->p->x -= cos((*sd)->p->angle - M_PI / 2) * (*sd)->p->move_speed;
	}
}

void	ft_move_up(t_data **sd)
{
	int	x;
	int	y;

	y = ((*sd)->p->y - (sin((*sd)->p->angle)
				* (*sd)->p->move_speed)) / TILE_SIZE;
	if ((*sd)->cube->map[y][(int)(*sd)->p->x / TILE_SIZE] != '1')
	{
		(*sd)->p->y -= sin((*sd)->p->angle) * (*sd)->p->move_speed;
	}
	x = ((*sd)->p->x - (cos((*sd)->p->angle)
				* (*sd)->p->move_speed)) / TILE_SIZE;
	if ((*sd)->cube->map[(int)(*sd)->p->y / TILE_SIZE][x] != '1')
	{
		(*sd)->p->x -= cos((*sd)->p->angle) * (*sd)->p->move_speed;
	}
}

void	ft_move_down(t_data **sd)
{
	int	x;
	int	y;

	y = ((*sd)->p->y + (sin((*sd)->p->angle)
				* (*sd)->p->move_speed)) / TILE_SIZE;
	if ((*sd)->cube->map[y][(int)(*sd)->p->x / TILE_SIZE] != '1')
	{
		(*sd)->p->y += sin((*sd)->p->angle) * (*sd)->p->move_speed;
	}
	x = ((*sd)->p->x + (cos((*sd)->p->angle)
				* (*sd)->p->move_speed)) / TILE_SIZE;
	if ((*sd)->cube->map[(int)(*sd)->p->y / TILE_SIZE][x] != '1')
	{
		(*sd)->p->x += cos((*sd)->p->angle) * (*sd)->p->move_speed;
	}
}

void	ft_move_left(t_data **sd)
{
	int	x;
	int	y;

	y = ((*sd)->p->y - (sin((*sd)->p->angle + M_PI / 2)
				* (*sd)->p->move_speed)) / TILE_SIZE;
	if ((*sd)->cube->map[y][(int)(*sd)->p->x / TILE_SIZE] != '1')
	{
		(*sd)->p->y -= sin((*sd)->p->angle + M_PI / 2) * (*sd)->p->move_speed;
	}
	x = ((*sd)->p->x - (cos((*sd)->p->angle + M_PI / 2)
				* (*sd)->p->move_speed)) / TILE_SIZE;
	if ((*sd)->cube->map[(int)(*sd)->p->y / TILE_SIZE][x] != '1')
	{
		(*sd)->p->x -= cos((*sd)->p->angle + M_PI / 2) * (*sd)->p->move_speed;
	}
}
