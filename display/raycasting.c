/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:12:37 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/06 10:34:17 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double distance(double x1, double y1, double x2, double y2) {
    double xDiff = x2 - x1;
    double yDiff = y2 - y1;
    return sqrt(xDiff*xDiff + yDiff*yDiff);
}

void line_direction_init(t_line   *line, double angle)
{
    line->ray_up = 0;
    line->ray_down = 0;
    line->ray_left = 0;
    line->ray_right = 0;
    if((angle > 0) && (angle < M_PI))
    {
        line->ray_up = 0;
        line->ray_down = 1;
    }
    else
    {
        line->ray_up = 1;
        line->ray_down = 0;
    }
    if((angle > (1.5 * M_PI)) || (angle < (0.5 * M_PI)))
    {
        line->ray_right = 1;
        line->ray_left = 0;
    }
    else
    {
        line->ray_right = 0;
        line->ray_left = 1;
    }
}

void ft_raycasting(t_data   *sd)
{
    double ang_inc;
    double ang;
    int i;
    

    i = 0;
    ang_inc = (60 *(M_PI/180)) / WIN_WIDTH;
    // sd->p->angle = fmod(sd->p->angle, 2 * M_PI);
    // if (sd->p->angle < 0)
    //     sd->p->angle += (2 * M_PI);
    ang = sd->p->angle - (30 * (M_PI / 180));
    // ang = fmod(ang, 2 * M_PI);
    // if (ang < 0)
    //     ang += (2 * M_PI);
    //     sd->line->v_x = 0;
    //     sd->line->v_y = 0;
    //     sd->line->h_x = 0;
    //     sd->line->h_y = 0;
    while (i < WIN_WIDTH)
    {
        sd->line->v_hit = false;
        sd->line->h_hit = false;
        ang = fmod(ang, 2 * M_PI);
        if (ang < 0)
            ang += (2 * M_PI);
        line_direction_init(sd->line, ang);
        // printf("right = %d\n left = %d\n up = %d\n down = %d\n",sd->line->ray_right,sd->line->ray_left,sd->line->ray_up,sd->line->ray_down);
        // printf("ang = %f\n",ang);
        // sleep(1);
        if (ang !=   M_PI/2 && ang !=  (1.5 * M_PI))
            ft_vertical_check(sd, ang);
       if (ang !=  0 && ang !=  M_PI)
            ft_horizontal_check(ang, sd);
        if (distance(sd->p->x,sd->p->y,sd->line->v_x,sd->line->v_y) < distance(sd->p->x,sd->p->y,sd->line->h_x ,sd->line->h_y) &&  sd->line->v_hit == true)
        {
            // puts("1\n");
            ft_draw_line(sd, sd->line->v_x, sd->line->v_y);
        }
        else
        {
            // printf("h_x = %f\n h_y = %f\n",sd->line->h_x,sd->line->h_y);

            ft_draw_line(sd, sd->line->h_x , sd->line->h_y);
        }
        ang += ang_inc;
        i++;
    }
    
    
}