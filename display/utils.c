/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:46:47 by mel-hous          #+#    #+#             */
/*   Updated: 2023/01/21 16:58:36 by mel-hous         ###   ########.fr       */
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
                sd->p->xx = (j * TILE_SIZE) + (TILE_SIZE / 2);
                sd->p->y = (i * TILE_SIZE) + (TILE_SIZE / 2);
                sd->p->yy = (i * TILE_SIZE) + (TILE_SIZE / 2);
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
    p->move_speed = speed;
    p->retation_angle = M_PI / 10;
    p->retation_speed = 3 * (M_PI / 180);
}

void ft_draw_line(t_data    *sd , int len)
{
   int i = 0;
   double   x;
   double   y;

    x = sd->p->x;
    y = sd->p->y;
   while(i <= len)
   {
        my_mlx_pixel_put(sd->draw, y, x, RED);
        x += cos(sd->p->angle);
        y += sin(sd->p->angle);
        i++;
   }
}
// #include "cub3d.h"

// int	create_rgb(int r, int g, int b)
// {
// 	return (r << 16 | g << 8 | b);
// }

// void	ft_draw_ceiling(t_data *data, double start, double len)
// {
// 	int	color;

// 	color = create_rgb(data->color.f[2], data->color.f[1], data->color.f[0]);
// 	while (start <= len)
// 	{
// 		my_mlx_pixel_put(&data->img, data->id, start, color);
// 		start++;
// 	}
// }

// void	ft_draw_floor(t_data *data, double start, double len)
// {
// 	int	color;

// 	color = create_rgb(data->color.c[2], data->color.c[1], data->color.c[0]);
// 	while (start <= len)
// 	{
// 		my_mlx_pixel_put(&data->img, data->id, start, color);
// 		start++;
// 	}
// }

// void	ft_drawing_wall(int start, int len, t_data *data)
// {
// 	int	color;

// 	color = create_rgb(45, 97, 34);
// 	// ft_draw_ceiling(data, 0, start);
// 	// ft_draw_floor(data, start + len, W_HEIGHT);
// 	if (len > W_HEIGHT)
// 		len = W_HEIGHT;
// 	while (start < len)
// 	{
// 		my_mlx_pixel_put(&data->img, data->id, start, color);
// 		start++;
// 	}
// 	printf ("start: %d\n, len: %d\n", start, len);
// }


// int	ft_rendering_wall(t_data *data)
// {
// 	double		wall_height;
// 	double		wall_start;
// 	double		dis_projplane;
// 	double		rayangle;

// 	rayangle = FOFV / W_WIDTH;
// 	dis_projplane = (W_WIDTH / 2) / tan(FOFV / 2);
// 	data->id = 0;
// 	while (data->id < W_WIDTH)
// 	{
// 		wall_height = (TILE / data->dis_rays[data->id]) * dis_projplane;
// 		wall_start = W_HEIGHT / 2 - (wall_height / 2);
// 		my_mlx_pixel_put(&data->img, data->id, W_HEIGHT / 2 - (wall_height / 2), \
// 			create_rgb(255, 255, 255));
// 		ft_drawing_wall(wall_start, wall_height, data);
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +1), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +2), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +3), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +4), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +5), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +6), \
// 		// 	create_rgb(255, 255, 255));


// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +wall_height-6), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +wall_height-7), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +wall_height-3), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +wall_height-4), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +wall_height-5), \
// 		// 	create_rgb(255, 255, 255));

// 		data->id++;
// 	}
// 	return (data->id = 0, 0);
// }


		