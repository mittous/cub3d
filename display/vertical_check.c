/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:34:32 by mel-hous          #+#    #+#             */
/*   Updated: 2023/01/24 13:16:35 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_vertical_check(t_data    *sd, double ang, double  *y, double  *x)
{
    if ((ang >  ((3 *M_PI)/2) && ang < (2 *M_PI)) ||(ang >= 0 &&  ang < (M_PI/2)))
    {
        *(x) = (abs(sd->p->x / 30) + 1) * 30;
        *(y) = sd->p->y - (sin(ang) * ((*(x) - sd->p->x) / cos(ang)));
        if (ang >  ((3 *M_PI)/2) && ang < (2 *M_PI))
        {
            
            while ((sd->cube->map[(int)(*y / TILE_SIZE)][(int)(*x / TILE_SIZE)] != '1'))
             {
                *(x) += TILE_SIZE;
                *(y) = *y - (sin(ang)* (TILE_SIZE/cos(ang)));
            }
            ft_draw_line(sd, ang, *x, *y);
        }
       if (( ang < (2 *M_PI)) ||(ang >= 0 &&  ang < (M_PI/2)))
        {
                *x = (abs(sd->p->x / 30) + 1) * 30;
                *y = sd->p->y + (sin(ang)* ((sd->p->x - *x) / cos(ang)));
                while ((sd->cube->map[(int)(*y / TILE_SIZE)][(int)(*x / TILE_SIZE)] != '1' ))
                 {
                    *x += TILE_SIZE;
                    *y = *y + sin(ang)* (TILE_SIZE/cos(ang));
                }
                ft_draw_line(sd, ang, *x, *y);
        }
        // ft_draw_line(sd, ang, x, y);
    }

    //  if ((ang <  ((3 *M_PI)/2) && ang >= M_PI) ||(ang < M_PI &&  ang > (M_PI/2)))
    //  {

    //     if (ang <  ((3 *M_PI)/2) && ang >= M_PI)
    //     {
    //         printf("###################ANG=%f\n", ang);
    //         x = abs(sd->p->x / 30) * 30;
    //         y = sd->p->y - (sin(ang) * ((x - sd->p->x) / cos(ang)));
            
    //         while ((sd->cube->map[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] != '1'))
    //          {
    //             x -= TILE_SIZE;
    //             y = y - (sin(ang)* (TILE_SIZE/cos(ang)));
    //         }
            
    //     }
    //     if (ang < M_PI &&  ang > (M_PI/2))
    //     {
    //         x = abs(sd->p->x / 30) * 30;
    //         y = sd->p->y + (sin(ang) * ((x - sd->p->x) / cos(ang)));
    //         if (ang >  ((3 *M_PI)/2) && ang < (2 *M_PI))
    //         {
                
    //             while ((sd->cube->map[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] != '1'))
    //              {
    //                 x -= TILE_SIZE;
    //                 y = y + (sin(ang)* (TILE_SIZE/cos(ang)));
    //             }
                
    //         }
    //     }
    //     ft_draw_line(sd, ang, x, y);
    //  }
     
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