/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:12:37 by mel-hous          #+#    #+#             */
/*   Updated: 2023/01/25 11:23:16 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double distance(double x1, double y1, double x2, double y2) {
    double xDiff = x2 - x1;
    double yDiff = y2 - y1;
    return sqrt(xDiff*xDiff + yDiff*yDiff);
}

void ft_raycasting(t_data   *sd)
{
    double ang_inc;
    double ang;
    int i;
    double x = sd->p->x;
    double y = sd->p->y;
    double x2 = sd->p->x;
    double y2 = sd->p->y;

    i = 0;
    ang_inc = (60 *(M_PI/180)) / WIN_WIDTH;
    ang = sd->p->angle - (30 * (M_PI / 180));
    ang = fmod(ang, 2 * M_PI);
    if (ang < 0)
        ang += (2 * M_PI);
    while (i < WIN_WIDTH)
    {
        // ang = fmod(ang, 2 * M_PI);
        // if (ang < 0)
        //     ang += (2 * M_PI);
        x = sd->p->x;
        y = sd->p->y;
        x2 = sd->p->x;
        y2 = sd->p->y;
        if (ang !=   M_PI/2 && ang !=   M_PI/2)
            ft_vertical_check(sd, ang, &x, &y);
       if (ang !=   0 && ang !=   M_PI)
            ft_horizontal_check(ang, sd, &x2, &y2);
        if (distance(sd->p->x,sd->p->y,x,y) < distance(sd->p->x,sd->p->y,x2,y2))
            ft_draw_line(sd, ang, x, y);
        else
            ft_draw_line(sd, ang, x2, y2);
        // puts("1\n");
        ang += ang_inc;
        i++;
    }
    
    
}