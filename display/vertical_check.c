/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:34:32 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/04 11:13:21 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_vertical_check(t_data    *sd, double ang)
{
    if (sd->line->ray_right == 1)
    {
        sd->line->v_x = (abs(sd->p->x / 30) + 1) * 30;
       sd->line->v_y = sd->p->y - (sin(ang) * ((sd->line->v_x - sd->p->x) / cos(ang)));
        if (sd->line->ray_up == 1)
        {
            
            while (((int)(sd->line->v_y/TILE_SIZE) > 0 && (int)(sd->line->v_y/TILE_SIZE) < WIN_HEIGHT/TILE_SIZE) && ((int)(sd->line->v_x/TILE_SIZE) > 0 && (int)(sd->line->v_x/TILE_SIZE) < WIN_WIDTH/TILE_SIZE) &&(sd->cube->map[(int)(sd->line->v_y / TILE_SIZE)][(int)(sd->line->v_x / TILE_SIZE)] != '1'))
             {
                sd->line->v_x += TILE_SIZE;
               sd->line->v_y = sd->line->v_y - (sin(ang)* (TILE_SIZE/cos(ang)));
            }
            // ft_draw_line(sd, ang, sd->line->v_x, sd->line->v_y);
        }
       if (sd->line->ray_down == 1)
        {
                sd->line->v_x = (abs(sd->p->x / 30) + 1) * 30;
                sd->line->v_y = sd->p->y + (sin(ang)* ((sd->p->x - sd->line->v_x) / cos(ang)));
                while (((int)(sd->line->v_y/TILE_SIZE) > 0 && (int)(sd->line->v_y/TILE_SIZE) < WIN_HEIGHT/TILE_SIZE) && ((int)(sd->line->v_x/TILE_SIZE) > 0 && (int)(sd->line->v_x/TILE_SIZE) < WIN_WIDTH/TILE_SIZE) &&(sd->cube->map[(int)(sd->line->v_y / TILE_SIZE)][(int)(sd->line->v_x / TILE_SIZE)] != '1' ))
                 {
                    sd->line->v_x += TILE_SIZE;
                    sd->line->v_y = sd->line->v_y + sin(ang)* (TILE_SIZE/cos(ang));
                }
                // ft_draw_line(sd, ang, sd->line->v_x, *y);
        }
        // ft_draw_line(sd, ang, x, y);
    }

    //  if ((ang <  ((3 *M_PI)/2) && ang >= M_PI) ||(ang < M_PI &&  ang > (M_PI/2)))
    //  {

    //     if (ang <  ((3 *M_PI)/2) && ang >= M_PI)
    //     {
    //         // printf("###################ANG=%f\n", ang);
    //         *x = abs(sd->p->x / 30) * 30;
    //         *y = sd->p->y - (sin(ang) * ((*x - sd->p->x) / cos(ang)));
            
    //         while (((int)(*y/TILE_SIZE) > 0 && (int)(*y/TILE_SIZE) < WIN_HEIGHT/TILE_SIZE) && ((int)(*x/TILE_SIZE) > 0 && (int)(*x/TILE_SIZE) < WIN_WIDTH/TILE_SIZE) &&(sd->cube->map[(int)(*y / TILE_SIZE)][(int)(*x / TILE_SIZE)] != '1'))
    //          {
    //             *x -= TILE_SIZE;
    //             *y = *y - (sin(ang)* (TILE_SIZE/cos(ang)));
    //         }
            
    //     }
    //     if (ang < M_PI &&  ang > (M_PI/2))
    //     {
    //         *x = abs(sd->p->x / 30) * 30;
    //         *y = sd->p->y + (sin(ang) * ((*x - sd->p->x) / cos(ang)));
    //         if (ang >  ((3 *M_PI)/2) && ang < (2 *M_PI))
    //         {
                
    //             while (((int)(*y/TILE_SIZE) > 0 && (int)(*y/TILE_SIZE) < WIN_HEIGHT/TILE_SIZE) && ((int)(*x/TILE_SIZE) > 0 && (int)(*x/TILE_SIZE) < WIN_WIDTH/TILE_SIZE) &&(sd->cube->map[(int)(*y / TILE_SIZE)][(int)(*x / TILE_SIZE)] != '1'))
    //              {
    //                 *x -= TILE_SIZE;
    //                 *y = *y + (sin(ang)* (TILE_SIZE/cos(ang)));
    //             }
                
    //         }
    //     }
        // ft_draw_line(sd, ang, *x, *y);
     }
     
    // if (ang > (M_PI / 2))
    // {
    //     *x = abs(sd->p->x / 30) * 30;
    //     *y = sd->p->y - sin(ang)* ((*x - sd->p->x) / cos(ang));
    //      if (ang > M_PI)
    //     {
    //         while (((int)(*y/TILE_SIZE) > 0 && (int)(*y/TILE_SIZE) < WIN_HEIGHT/TILE_SIZE) && ((int)(*x/TILE_SIZE) > 0 && (int)(*x/TILE_SIZE) < WIN_WIDTH/TILE_SIZE) &&sd->cube->map[(int)(*y / TILE_SIZE)][(int)(*x / TILE_SIZE)] != '1' )
    //         {
    //             *x -= TILE_SIZE;
    //             *y -= sd->p->y - sin(ang)* (TILE_SIZE/cos(ang));
    //         }
    //     }
    //     ft_draw_line(sd, ang, *x, *y);
    // }
// }