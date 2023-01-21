/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_movment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:41:35 by mel-hous          #+#    #+#             */
/*   Updated: 2023/01/21 16:02:37 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void ft_move_right(t_data *sd)
{
    int x;
    int y;

    x = (sd->p->x - (cos(sd->p->angle - M_PI / 2) * sd->p->move_speed)) / TILE_SIZE;
    y = (sd->p->y - (sin(sd->p->angle - M_PI / 2) * sd->p->move_speed)) / TILE_SIZE;
    if(sd->cube->map[y][x] != '1')
    {
        sd->p->x -= cos(sd->p->angle - M_PI / 2) * sd->p->move_speed;
        sd->p->y -= sin(sd->p->angle - M_PI / 2) * sd->p->move_speed;
    }
}

void ft_move_up(t_data *sd)
{
    int x;
    int y;

    x = (sd->p->x - (cos(sd->p->angle) * sd->p->move_speed)) / TILE_SIZE;
    y = (sd->p->y - (sin(sd->p->angle) * sd->p->move_speed)) / TILE_SIZE;
    if(sd->cube->map[y][x] != '1')
    {
        sd->p->x -= cos(sd->p->angle) * sd->p->move_speed;
        sd->p->y -= sin(sd->p->angle) * sd->p->move_speed;
    }
}


void ft_move_down(t_data *sd)
{
    int x;
    int y;

    x = (sd->p->x + (cos(sd->p->angle) * sd->p->move_speed)) / TILE_SIZE;
    y = (sd->p->y + (sin(sd->p->angle) * sd->p->move_speed)) / TILE_SIZE;
    if(sd->cube->map[y][x] != '1')
    {
        sd->p->x += cos(sd->p->angle) * sd->p->move_speed;
        sd->p->y += sin(sd->p->angle) * sd->p->move_speed;
    }
}

void ft_move_left(t_data *sd)
{
    int x;
    int y;

    x = (sd->p->x - (cos(sd->p->angle + M_PI / 2) * sd->p->move_speed)) / TILE_SIZE;
    y = (sd->p->y - (sin(sd->p->angle + M_PI / 2) * sd->p->move_speed)) / TILE_SIZE;
    if(sd->cube->map[y][x] != '1')
    {
        sd->p->x -= cos(sd->p->angle + M_PI / 2) * sd->p->move_speed;
        sd->p->y -= sin(sd->p->angle + M_PI / 2) * sd->p->move_speed;
    }
}



void ft_move_left_ang(t_data *sd)
{
    sd->p->angle += sd->p->retation_angle;
}

void ft_move_right_ang(t_data *sd)
{
    sd->p->angle -= sd->p->retation_angle;
}
int	key_hook(int key, t_data *sd)
{
    if (key == 53)
		exit(0);
    // printf("%d\n", key);
	if (key == 2 )
        ft_move_right(sd);
    if  ( key == 0)
		ft_move_left(sd);
	if (key == 1 )
		ft_move_up(sd);
	if (key == 13 )
		ft_move_down(sd);
	if (key == 124)
		ft_move_left_ang(sd);
	if ( key == 123)
		ft_move_right_ang(sd);
	return (0);
}