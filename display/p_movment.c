/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_movment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:41:35 by mel-hous          #+#    #+#             */
/*   Updated: 2023/01/18 15:13:09 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void ft_move_right(t_data *sd)
{
    int x;
    int y;

    x = (sd->p->x + sd->p->move_speed) / 30;
    y = sd->p->y / 30;
    if(sd->cube->map[y][x] != '1')
        sd->p->x += sd->p->move_speed;
}

void ft_move_up(t_data *sd)
{
    int x;
    int y;
    x = sd->p->x / 30;
    y = (sd->p->y - sd->p->move_speed) / 30;
    if(sd->cube->map[y][x] != '1')
        sd->p->y -= sd->p->move_speed;
}

void ft_move_down(t_data *sd)
{
    int x;
    int y;

    x = sd->p->x / 30;
    y = (sd->p->y + sd->p->move_speed) / 30;
    if(sd->cube->map[y][x] != '1')
        sd->p->y += sd->p->move_speed;
}

void ft_move_left(t_data *sd)
{
    int x;
    int y;

    x = (sd->p->x - sd->p->move_speed) / 30;
    y = sd->p->y / 30;
    if(sd->cube->map[y][x] != '1')
        sd->p->x -= sd->p->move_speed;
}

int	key_hook(int key, t_data *sd)
{
    if (key == 53)
		exit(0);
	if (key == 2 || key == 124)
		ft_move_right(sd);
	if (key == 13 || key == 126)
		ft_move_up(sd);
	if (key == 1 || key == 125)
		ft_move_down(sd);
	if (key == 0 || key == 123)
		ft_move_left(sd);
	return (0);
}