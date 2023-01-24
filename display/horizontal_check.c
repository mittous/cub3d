/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:34:29 by mel-hous          #+#    #+#             */
/*   Updated: 2023/01/23 13:22:01 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_horizontal_check(double ang, t_data *sd)
{
    double x;
    double y;

    if (ang < (M_PI / 2) && ang > 0)
    {
        y = abs(sd->p->y / 30) * 30;
        x = (sd->p->y - y) / tan(ang);
        while (sd->cube->map[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] != '1')
        {
            y -= TILE_SIZE;
            x += (TILE_SIZE / tan(ang));
        }
    }
}