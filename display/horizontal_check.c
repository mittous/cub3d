/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:34:29 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/05 18:02:21 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_horizontal_check(double ang, t_data *sd)
{
     double y_intercept;
   double x_intercept;
   double dx;
   double dy;

   y_intercept = abs(sd->p->y / TILE_SIZE) * TILE_SIZE;
   if (sd->line->ray_down == 1)
         y_intercept += 30;
    x_intercept = sd->p->x + (y_intercept - sd->p->y) / tan(ang);
    sd->line->h_x = x_intercept;
    sd->line->h_y = y_intercept;
    dy = TILE_SIZE;
    if(sd->line->ray_up == 1)
        dy *= -1;
    dx = TILE_SIZE/tan(ang); 
    if(sd->line->ray_left == 1 && dx > 0)
        dx *= -1;
    if(sd->line->ray_right == 1 && dx < 0)
        dx *= -1;
    if(sd->line->ray_up == 1)
        sd->line->h_y--;
    while(sd->line->h_x >= 0 && sd->line->h_x <= WIN_WIDTH && sd->line->h_y >= 0 && sd->line->h_y <= WIN_HEIGHT )
    {
        if(sd->cube->map[(int)((sd->line->h_y) / TILE_SIZE)] && (int)(ft_strlen(sd->cube->map[(int)((sd->line->h_y) / TILE_SIZE)])) > (int)((sd->line->h_x) / TILE_SIZE) && sd->cube->map[(int)((sd->line->h_y) / TILE_SIZE)][(int)((sd->line->h_x) / TILE_SIZE)] == '1')
        {
            sd->line->h_hit = true;
            break;
        }
        sd->line->h_x += dx;
        sd->line->h_y += dy;
    }
}
    // if (sd->line->ray_right == 1)
    // {
    //     // puts("1\n");
    //     if (sd->line->ray_up == 1)
    //     {
    //         sd->line->h_y = abs(sd->p->y / 30) * 30;
    //         sd->line->h_x = sd->p->x + ((sd->line->h_y - sd->p->y) / tan(ang));
    //         while (((sloorline->h_y/TILE_SIZE) > 0 && (int)(sd->line->h_y/TILE_SIZE) < WIN_HEIGHT/TILE_SIZE) && ((int)(sd->line->h_x/TILE_SIZE) > 0 && (int)(sd->line->h_x/TILE_SIZE) < WIN_WIDTH/TILE_SIZE) && sd->cube->map[(int)(sd->line->h_y / TILE_SIZE)][(int)(sd->line->h_x / TILE_SIZE)] != '1')
    //         {
    //             sd->line->h_y -= TILE_SIZE;
    //             sd->line->h_x += (TILE_SIZE / tan(ang));
    //         }
    //         // printf("#####X=%lf--#########Y=%lf\n",sd->line->h_x/ TILE_SIZE,sd->line->h_y/ TILE_SIZE);
    //     }
    //     else if (sd->line->ray_down == 1)
    //     {
    //         sd->line->h_y = (abs(sd->p->y / 30) + 1) * 30;
    //          sd->line->h_x = sd->p->x + ((sd->line->h_y - sd->p->y) / tan(ang));
    //         while (((int)(sd->line->h_y/TILE_SIZE) > 0 && (int)(sd->line->h_y/TILE_SIZE) < WIN_HEIGHT/TILE_SIZE) && ((int)(sd->line->h_x/TILE_SIZE) > 0 && (int)(sd->line->h_x/TILE_SIZE) < WIN_WIDTH/TILE_SIZE) && sd->cube->map[(int)(sd->line->h_y / TILE_SIZE)][(int)(sd->line->h_x / TILE_SIZE)] != '1')
    //         {
    //             sd->line->h_y += TILE_SIZE;
    //             sd->line->h_x += (TILE_SIZE / tan(ang));
    //         }
    //         // ft_draw_line(sd, ang, sd->line->h_x, sd->line->h_y);
    //     }
    // }
    // else if (sd->line->ray_left == 1)
    // {
    //     if (sd->line->ray_up == 1)
    //     {
    //         sd->line->h_y = abs(sd->p->y / 30) * 30;
    //         sd->line->h_x = sd->p->x - ((sd->p->y - sd->line->h_y) / tan(ang));
    //         while (((int)(sd->line->h_y/TILE_SIZE) > 0 && (int)(sd->line->h_y/TILE_SIZE) < WIN_HEIGHT/TILE_SIZE) && ((int)(sd->line->h_x/TILE_SIZE) > 0 && (int)(sd->line->h_x/TILE_SIZE) < WIN_WIDTH/TILE_SIZE) &&sd->cube->map[(int)(sd->line->h_y / TILE_SIZE)][(int)(sd->line->h_x / TILE_SIZE)] != '1')
    //         {
    //             sd->line->h_y -= TILE_SIZE;
    //             sd->line->h_x -= (TILE_SIZE / tan(ang));
    //         }
    //     }
    //     else if (sd->line->ray_down == 1)
    //     {
    //         // puts("2\n");
    //         sd->line->h_y = (abs(sd->p->y / 30) + 1) * 30;
    //         sd->line->h_x = sd->p->x - ((sd->line->h_y - sd->p->y) / tan(ang));
           
    //         while ((sd->cube->map[(int)(sd->line->h_y / TILE_SIZE)][(int)(sd->line->h_x / TILE_SIZE)] != '1'))
    //         {
    //             sd->line->h_y += TILE_SIZE;
    //             sd->line->h_x -= (TILE_SIZE / tan(ang));
    //         }
    //     }
    // }