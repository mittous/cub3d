/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_movment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:41:35 by mel-hous          #+#    #+#             */
/*   Updated: 2023/01/24 09:33:30 by mel-hous         ###   ########.fr       */
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
    sd->p->angle = fmod(sd->p->angle, 2 * M_PI);
    if (sd->p->angle < 0)
        sd->p->angle += (2 * M_PI);
    sd->p->angle += sd->p->retation_speed;
}

void ft_move_right_ang(t_data *sd)
{
    sd->p->angle = fmod(sd->p->angle, 2 * M_PI);
    if (sd->p->angle < 0)
        sd->p->angle += (2 * M_PI);
    sd->p->angle -= sd->p->retation_speed;
}
void ft_move(t_data *sd)
{
    if (sd->p->move_right == 1)
        ft_move_right(sd);
    if (sd->p->move_right == -1)
        ft_move_left(sd);
    if (sd->p->move_up == 1)
        ft_move_up(sd);
    if (sd->p->move_up == -1)
        ft_move_down(sd);
    if (sd->p->rotation == 1)
        ft_move_right_ang(sd);
    if (sd->p->rotation == -1)
        ft_move_left_ang(sd);
}
int	key_hook(int key, t_data *sd)
{
	if (key == 53)
		exit(0);
    // printf("%d\n", key);
	if (key == 2 )
        sd->p->move_right = 1;
    if  ( key == 0)
		sd->p->move_right = -1;
	if (key == 1 )
		sd->p->move_up = 1;
	if (key == 13 )
		sd->p->move_up = -1;
	if (key == 124)
		sd->p->rotation = -1;
	if ( key == 123)
		sd->p->rotation = 1;
	return (0);
}
int	key_rel(int key, t_data *sd)
{
	if (key == 53)
		exit(0);
    // printf("%d\n", key);
	if (key == 2 )
        sd->p->move_right = 0;
    if  ( key == 0)
		sd->p->move_right = 0;
	if (key == 1 )
		sd->p->move_up = 0;
	if (key == 13 )
		sd->p->move_up = 0;
	if (key == 124)
		sd->p->rotation = 0;
	if ( key == 123)
		sd->p->rotation = 0;
	return (0);
}