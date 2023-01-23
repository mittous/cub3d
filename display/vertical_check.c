/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:34:32 by mel-hous          #+#    #+#             */
/*   Updated: 2023/01/23 11:42:24 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_vertical_check(t_data    *sd, double ang)
{
    double  x;
    double  y;

    if (ang < ( (3 * M_PI) / 2) && ang >= 0)
    {
        x = (abs(sd->p->x / 30) + 1) * 30;
        y = sd->p->y - (sin(ang) * ((x - sd->p->x) / cos(ang)));
        if (ang > 0)
        {
            // for(int i = 0; i < 2; i++)
            while ((sd->cube->map[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] != '1' && y > 0 && x < sd->draw->line_length))
             {
                // printf("y ==== %f \n x ===== %f\n", y, x);
                x += TILE_SIZE;
                y = y - (sin(ang)* (TILE_SIZE/cos(ang)));
            }
            ft_draw_line(sd, ang, x, y);
        }
   if (ang < 0)
        {
            printf("##################%f\n", ang);
            x = (abs(sd->p->x / 30) + 1) * 30;
            y = sd->p->y + (sin(ang)* ((x - sd->p->x) / cos(ang)));
           while ((sd->cube->map[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] != '1' ))
             {
                // printf("y ==== %f \n x ===== %f\n", y, x);
                x += TILE_SIZE;
                y = y + sin(ang)* (TILE_SIZE/cos(ang));
            }
             ft_draw_line(sd, ang, x, y);
        }
        // ft_draw_line(sd, ang, x, y);
    }
    // if (ang > (M_PI / 2))
    // {
    //     x = abs(sd->p->x / 30) * 30;
    //     y = sd->p->y - sin(ang)* ((x - sd->p->x) / cos(ang));
    //      if (ang > M_PI)
    //     {
    //         while (sd->cube->map[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] != '1' )
    //         {
    //             x -= TILE_SIZE;
    //             y -= sd->p->y - sin(ang)* (TILE_SIZE/cos(ang));
    //         }
    //     }
    //     ft_draw_line(sd, ang, x, y);
    // }
}