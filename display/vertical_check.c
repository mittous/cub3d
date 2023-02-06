/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:34:32 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/05 18:02:10 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_vertical_check(t_data    *sd, double ang)
{
     double y_intercept;
   double x_intercept;
   double v_dx;
   double dy;

   x_intercept = floor(sd->p->x / TILE_SIZE) * TILE_SIZE;
   if (sd->line->ray_right == 1)
         x_intercept += 30;
    y_intercept = sd->p->y + (x_intercept - sd->p->x) * tan(ang);
    sd->line->v_x = x_intercept;
    sd->line->v_y = y_intercept;
    v_dx = TILE_SIZE;
    if(sd->line->ray_left == 1)
        v_dx *= -1;
    dy = TILE_SIZE*tan(ang); 
    if(sd->line->ray_up == 1 && dy > 0)
        dy *= -1;
    if(sd->line->ray_down == 1 && dy < 0)
        dy *= -1;
    if(sd->line->ray_left == 1)
        sd->line->v_x--;
    while(sd->line->v_x >= 0 && sd->line->v_x < WIN_WIDTH && sd->line->v_y >= 0 && sd->line->v_y < WIN_HEIGHT)
    {
        if(sd->cube->map[(int)(fabs(sd->line->v_y / TILE_SIZE))][(int)(fabs(sd->line->v_x / TILE_SIZE))] == '1')
        {
            sd->line->v_hit = true;
            break;
        }
        sd->line->v_x += v_dx;
        sd->line->v_y += dy;
    }
}
