/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:34:29 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/04 11:16:32 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_horizontal_check(double ang, t_data *sd)
{
    if ((ang >  ((3 *M_PI)/2) && ang < (2 * M_PI)) ||(ang > 0 &&  ang < (M_PI/2)))
    {
        // puts("1\n");
        if (sd->line->ray_up == 1 && sd->line->ray_right == 1)
        {
            sd->line->h_y = abs(sd->p->y / 30) * 30;
            sd->line->h_x = sd->p->x + ((sd->line->h_y - sd->p->y) / tan(ang));
            while ((int)(sd->line->h_y/TILE_SIZE) > 0 &&sd->cube->map[(int)(sd->line->h_y / TILE_SIZE)][(int)(sd->line->h_x / TILE_SIZE)] != '1')
            {
                sd->line->h_y -= TILE_SIZE;
                sd->line->h_x += (TILE_SIZE / tan(ang));
            }
            // printf("#####X=%lf--#########Y=%lf\n",sd->line->h_x/ TILE_SIZE,sd->line->h_y/ TILE_SIZE);
        }
        if (sd->line->ray_down == 1 && sd->line->ray_right == 1)
        {
            sd->line->h_y = (abs(sd->p->y / 30) + 1) * 30;
             sd->line->h_x = sd->p->x + ((sd->line->h_y - sd->p->y) / tan(ang));
            while (((int)(sd->line->h_y/TILE_SIZE) > 0 && (int)(sd->line->h_y/TILE_SIZE) < WIN_HEIGHT/TILE_SIZE) && ((int)(sd->line->h_x/TILE_SIZE) > 0 && (int)(sd->line->h_x/TILE_SIZE) < WIN_WIDTH/TILE_SIZE) && sd->cube->map[(int)(sd->line->h_y / TILE_SIZE)][(int)(sd->line->h_x / TILE_SIZE)] != '1')
            {
                sd->line->h_y += TILE_SIZE;
                sd->line->h_x += (TILE_SIZE / tan(ang));
            }
            // ft_draw_line(sd, ang, sd->line->h_x, sd->line->h_y);
        }
    }
    if (sd->line->ray_up == 1 && sd->line->ray_left == 1)
    {
        if (ang <  ((3 *M_PI)/2) && ang >= M_PI)
        {
            sd->line->h_y = abs(sd->p->y / 30) * 30;
            sd->line->h_x = sd->p->x - ((sd->p->y - sd->line->h_y) / tan(ang));
            while (((int)(sd->line->h_y/TILE_SIZE) > 0 && (int)(sd->line->h_y/TILE_SIZE) < WIN_HEIGHT/TILE_SIZE) && ((int)(sd->line->h_x/TILE_SIZE) > 0 && (int)(sd->line->h_x/TILE_SIZE) < WIN_WIDTH/TILE_SIZE) &&sd->cube->map[(int)(sd->line->h_y / TILE_SIZE)][(int)(sd->line->h_x / TILE_SIZE)] != '1')
            {
                sd->line->h_y -= TILE_SIZE;
                sd->line->h_x -= (TILE_SIZE / tan(ang));
            }
        }
        if (sd->line->ray_down == 1 && sd->line->ray_left == 1)
        {
            // puts("2\n");
            sd->line->h_y = (abs(sd->p->y / 30) + 1) * 30;
            sd->line->h_x = sd->p->x - ((sd->line->h_y - sd->p->y) / tan(ang));
            if (ang >  ((3 *M_PI)/2) && ang < (2 *M_PI))
            {
                
                while ((sd->cube->map[(int)(sd->line->h_y / TILE_SIZE)][(int)(sd->line->h_x / TILE_SIZE)] != '1'))
                 {
                    sd->line->h_y += TILE_SIZE;
                    sd->line->h_x -= (TILE_SIZE / tan(ang));
                }
            }
        }
    }
}