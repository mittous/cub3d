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

void    ft_drawing_wall(int ray ,double wall_start, double wall_end, t_data *data, int offset_x)
{
    int color;

    color = 0;
    int start = wall_start;
    // while (start < wall_end)
    // {
    //     my_mlx_pixel_put(data->draw, start , ray, data->textur[0].addr[color *data->textur[0].width + increes] );
    //     color++;
    //     start++;
    // }
    while (start < wall_end)
    {
        int offset_y = ((int)start - wall_start) * data->textur[0].height / (wall_end - wall_start);
        my_mlx_pixel_put(data->draw, start , ray, data->textur[0].addr[(data->textur[0].width * offset_y) + offset_x]);
        color++;
        start++;
    }

}

int	ft_rgb_to_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
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
    double dis_projplane = (WIN_WIDTH / 2) / tan(30 * (M_PI / 180));
    int increes = 0;
    int offset_x = 0;
    int offset_y = 0;
    while (i < WIN_WIDTH)
    {
        sd->line->v_hit = false;
        sd->line->h_hit = false;
        ang = fmod(ang, 2 * M_PI);
        if (ang < 0)
            ang += (2 * M_PI);
        line_direction_init(sd->line, ang);

        if (ang !=   M_PI/2 && ang !=  (1.5 * M_PI))
            ft_vertical_check(sd, ang);
       if (ang !=  0 && ang !=  M_PI)
            ft_horizontal_check(ang, sd);

        if (distance(sd->p->x,sd->p->y,sd->line->v_x,sd->line->v_y) < distance(sd->p->x,sd->p->y,sd->line->h_x ,sd->line->h_y) &&  sd->line->v_hit == true)
            sd->line->distance = distance(sd->p->x,sd->p->y,sd->line->v_x,sd->line->v_y);
        else
            sd->line->distance =  distance(sd->p->x,sd->p->y,sd->line->h_x ,sd->line->h_y);

        double wall_height = (TILE_SIZE / sd->line->distance) * dis_projplane;
		double wall_start = WIN_HEIGHT / 2 - (wall_height / 2);

		int wall_end = wall_start + wall_height;
        if (wall_end >= WIN_HEIGHT)
            wall_end = WIN_HEIGHT - 1;
        if (wall_start < 0)
            wall_start = 0;
        if (sd->line->v_hit == true)
            offset_x = (int)sd->line->h_x % TILE_SIZE;
        else
            offset_x = (int)sd->line->h_y % TILE_SIZE;
		ft_drawing_wall(i  , wall_start, wall_end, sd, offset_x);
        // printf ("h_x = %f\n", sd->line->h_x);
        ang += ang_inc;
        increes++;
        i++;
    }
    
    
}