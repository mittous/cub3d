/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:12:37 by mel-hous          #+#    #+#             */
/*   Updated: 2023/01/22 11:24:45 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_raycasting(t_data   *sd)
{
    double ang_inc;
    double ang;
    int i;

    i = 0;
    ang_inc = (60 *(M_PI/180)) / 320;
    ang = sd->p->angle + (30 * (M_PI / 180));
    while (i < 320)
    {
        ft_draw_line(sd, 30, ang);
        ang -= ang_inc;
        i++;
    }
    
    
}