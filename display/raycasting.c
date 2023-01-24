/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:12:37 by mel-hous          #+#    #+#             */
/*   Updated: 2023/01/24 13:16:59 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_raycasting(t_data   *sd)
{
    double ang_inc;
    double ang;
    int i;
    double x = 0;
    double y = 0;

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
       ft_vertical_check(sd, ang, &x, &y);
        ang += ang_inc;
        i++;
    }
    
    
}