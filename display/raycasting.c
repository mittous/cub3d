/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:12:37 by mel-hous          #+#    #+#             */
/*   Updated: 2023/01/22 16:48:25 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_raycasting(t_data   *sd)
{
    double ang_inc;
    double ang;
    int i;

    i = 0;
    ang_inc = (60 *(M_PI/180)) / WIN_WIDTH;
    ang = sd->p->angle + (30 * (M_PI / 180));
    while (i < WIN_WIDTH)
    {
       ft_vertical_check(sd, ang);
        ang -= ang_inc;
        i++;
    }
    
    
}