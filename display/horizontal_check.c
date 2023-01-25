/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:34:29 by mel-hous          #+#    #+#             */
/*   Updated: 2023/01/25 11:20:36 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_horizontal_check(double ang, t_data *sd, double *x, double *y)
{
    if ((ang >  ((3 *M_PI)/2) && ang < (2 * M_PI)) ||(ang > 0 &&  ang < (M_PI/2)))
    {
        if (ang >  ((3 *M_PI)/2) && ang < (2 * M_PI))
        {
            *y = abs(sd->p->y / 30) * 30;
            *x = sd->p->x + ((sd->p->y - *y) / tan(ang));
            while ((int)(*y/TILE_SIZE) > 0 &&sd->cube->map[(int)(*y / TILE_SIZE)][(int)(*x / TILE_SIZE)] != '1')
            {
                *y -= TILE_SIZE;
                *x += (TILE_SIZE / tan(ang));
            }
            // printf("#####X=%lf--#########Y=%lf\n",*x/ TILE_SIZE,*y/ TILE_SIZE);
        }
        if (ang > 0 &&  ang < (M_PI/2))
        {
            *y = (abs(sd->p->y / 30) + 1) * 30;
            *x = sd->p->x + ((*y - sd->p->y) / tan(ang));
            while (((int)(*y/TILE_SIZE) > 0 && (int)(*y/TILE_SIZE) < WIN_HEIGHT/TILE_SIZE) && ((int)(*x/TILE_SIZE) > 0 && (int)(*x/TILE_SIZE) < WIN_WIDTH/TILE_SIZE) && sd->cube->map[(int)(*y / TILE_SIZE)][(int)(*x / TILE_SIZE)] != '1')
            {
                *y += TILE_SIZE;
                *x += (TILE_SIZE / tan(ang));
            }
            // ft_draw_line(sd, ang, *x, *y);
        }
    }
    if ((ang <  ((3 *M_PI)/2) && ang >= M_PI) ||(ang < M_PI &&  ang > (M_PI/2)))
    {

        if (ang <  ((3 *M_PI)/2) && ang >= M_PI)
        {
            *y = abs(sd->p->y / 30) * 30;
            *x = sd->p->x - ((sd->p->y - *y) / tan(ang));
            while (((int)(*y/TILE_SIZE) > 0 && (int)(*y/TILE_SIZE) < WIN_HEIGHT/TILE_SIZE) && ((int)(*x/TILE_SIZE) > 0 && (int)(*x/TILE_SIZE) < WIN_WIDTH/TILE_SIZE) &&sd->cube->map[(int)(*y / TILE_SIZE)][(int)(*x / TILE_SIZE)] != '1')
            {
                *y -= TILE_SIZE;
                *x -= (TILE_SIZE / tan(ang));
            }
        }
        if (ang < M_PI &&  ang > (M_PI/2))
        {
            *y = (abs(sd->p->y / 30) + 1) * 30;
            *x = sd->p->x - ((*y - sd->p->y) / tan(ang));
            if (ang >  ((3 *M_PI)/2) && ang < (2 *M_PI))
            {
                
                while ((sd->cube->map[(int)(*y / TILE_SIZE)][(int)(*x / TILE_SIZE)] != '1'))
                 {
                    *y += TILE_SIZE;
                    *x -= (TILE_SIZE / tan(ang));
                }
            }
        }
    }
}