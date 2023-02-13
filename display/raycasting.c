/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:12:37 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/12 17:20:53 by mel-hous         ###   ########.fr       */
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

void    ft_drawing_wall(int ray ,double wall_real_height, t_data *data, int offset_x, int text)
{
    double  wall_height;
    int     start;
    int     end;

    if (wall_real_height > WIN_HEIGHT)
        wall_height = WIN_HEIGHT;
    else
        wall_height = wall_real_height;
	start = (WIN_HEIGHT / 2.0) - (wall_height / 2.0);
	end = (WIN_HEIGHT / 2.0) + (wall_height / 2.0);
    while (start < end)
    {
        int dis_from_top = start + (wall_real_height / 2) - (WIN_HEIGHT / 2);
		int offset_y = dis_from_top / wall_real_height * data->textur->height;
        my_mlx_pixel_put(data->draw, start , ray, data->textur[text].addr[(data->textur[text].width * offset_y) + offset_x]);
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
    int offset_x = 0;
    while (i < WIN_WIDTH)
    {
        sd->line->v_hit = false;
        sd->line->h_hit = false;
        ang = fmod(ang, 2 * M_PI);
        if (ang < 0)
            ang += (2 * M_PI);
        line_direction_init(sd->line, ang);

        if (ang !=  0 && ang !=  M_PI)
            ft_horizontal_check(ang, sd);
        if (ang != M_PI/2 && ang !=  (1.5 * M_PI))
            ft_vertical_check(sd, ang);
        double wall_height;
        double wall_start;
        int wall_end;
        if (distance(sd->p->x,sd->p->y,sd->line->v_x,sd->line->v_y) < distance(sd->p->x,sd->p->y,sd->line->h_x ,sd->line->h_y) &&  sd->line->v_hit == true)
        {
            sd->line->distance = distance(sd->p->x,sd->p->y,sd->line->v_x,sd->line->v_y) * cos(ang - sd->p->angle);
            offset_x = fmod(sd->line->v_y, TILE_SIZE) / TILE_SIZE * sd->textur->width;
        }
        else if (distance(sd->p->x,sd->p->y,sd->line->v_x,sd->line->v_y) > distance(sd->p->x,sd->p->y,sd->line->h_x ,sd->line->h_y) &&  sd->line->h_hit == true)
        {
            sd->line->distance =  distance(sd->p->x,sd->p->y,sd->line->h_x ,sd->line->h_y) * cos(ang - sd->p->angle);
            offset_x = fmod(sd->line->h_x, TILE_SIZE) / TILE_SIZE * sd->textur->width;
        }
        wall_height = (TILE_SIZE / sd->line->distance) * dis_projplane;
        wall_start = WIN_HEIGHT / 2 - (wall_height / 2);
        wall_end = wall_start + wall_height;

        printf ("sd->line->v_hit[%d] = %d\n",i, sd->line->v_hit);
        if (sd->line->v_hit)
        {
            if (ang > (3 * M_PI) / 2 || ang < M_PI / 2)
                ft_drawing_wall(i  , wall_height, sd, offset_x, 1);
            if (ang > M_PI / 2 && ang < (3 * M_PI) / 2)
                ft_drawing_wall(i  , wall_height, sd, offset_x, 2);
        }
        else if (!sd->line->v_hit)
        {
            if (ang > M_PI)
                ft_drawing_wall(i  , wall_height, sd, offset_x, 3);
            if (ang < M_PI)
                ft_drawing_wall(i  , wall_height, sd, offset_x, 0);
        }
        ang += ang_inc;
        i++;
    }
    
    
}