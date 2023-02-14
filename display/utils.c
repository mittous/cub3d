/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:46:47 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/12 13:13:10 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void p_search(t_data *sd, t_cube *cube)
{
    int i;
    int j;

    i = 0;
    while(sd->cube->map[i])
    {
        j = 0;
        while(sd->cube->map[i][j])
        {
            if (sd->cube->map[i][j] == cube->player_char)
            {
                if (sd->cube->map[i][j] == 'N')
                    sd->p->angle = (3 * M_PI) / 2;
                if (sd->cube->map[i][j] == 'S')
                    sd->p->angle = M_PI / 2;
                if (sd->cube->map[i][j] == 'W')
                    sd->p->angle = M_PI;
                if (sd->cube->map[i][j] == 'E')
                    sd->p->angle = 0;
                sd->cube->map[i][j] = '0';
                sd->p->x = (j * TILE_SIZE) + (TILE_SIZE / 2);
                sd->p->x_cube = (j * TILE_SIZE) + (TILE_SIZE / 2);
                sd->p->y = (i * TILE_SIZE) + (TILE_SIZE / 2);
                sd->p->y_cube = (i * TILE_SIZE) + (TILE_SIZE / 2);
                break;
            }
            j++;
        }
        i++;
    }
}

void   p_init(t_player *p)
{

	// p = malloc(sizeof(t_player));
    p->x = 0;
    p->y = 0;
    p->move_speed = SPEED;
    p->retation_angle = M_PI / 6;
    p->retation_speed = 3 * (M_PI / 180);
    p->move_right = 0;
    p->move_up = 0;
    p->rotation = 0;
}

void ft_draw_line(t_data    *sd ,double  x2,double  y2)
{
   int i = 0;
   double   dx;
   double   dy;
   double x;
   double y;
   int steps;

    x = sd->p->x;
    y = sd->p->y;
    dx = x2 - x;
    dy = y2 - y;
    if(fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);
   while(i <= (int)steps)
   {
        my_mlx_pixel_put(sd->draw, y, x, RED);
        x += dx/steps;
        y += dy/steps;
        i++;
   }
}
