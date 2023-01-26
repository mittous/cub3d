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

// void	ft_drawing_wall(int wall_start, int len, t_data *data)
// {
// 	int	color/* , *bpp, *sz_line, *end */;
// 	void	*img;
	
// 	// img = mlx_xpm_file_to_image(&data->mlx, data->textures.no, , 30);
// 	// void *data_addr = mlx_get_data_addr(img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);

// 	color = create_rgb(25, 81, 100);
// 	int i = wall_start;
// 	int j = 0;
// 	while (wall_start < len + i)
// 	{
// 		// while()
// 		// {
// 			// j = j*TILE;
// 			my_mlx_pixel_put(&data->img, data->id, wall_start, data->textures.img_data[0][j % TILE]);
// 		// }
// 		// printf ("%d\n")
// 		j++;
// 		wall_start++;
// 	}
// }

// int	ft_pixel_color_textur()
// {
	
// }
// int	ft_rendering_wall(t_data *data)
// {
// 	double		wall_height;
// 	double		wall_start;
// 	double		dis_projplane;

// 	dis_projplane = (W_WIDTH / 2) / tan(FOFV / 2);
// 	data->id = 0;
// 		int j = 0;
// 		int mov = 0;
// 	while (data->id < W_WIDTH)
// 	{
// 		wall_height = (TILE / data->dis_rays[data->id]) * dis_projplane;
// 		wall_start = W_HEIGHT / 2 - (wall_height / 2);

// 		int wall_end = wall_start + wall_height;
// 		while (wall_start < wall_end)
// 		{
// 			ft_pixel_color_textur();
// 			// my_mlx_pixel_put(&data->img, data->id, wall_start, data->textures.img_data[0][j % TILE]);
// 			// j *= TILE + mov;
// 			wall_start++;
// 		}
// 		mov++;

// 		// ft_drawing_wall(wall_start, wall_height, data);
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) ), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +1), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +2), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +4), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +5), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +6), \
// 		// 	create_rgb(255, 255, 255));


// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +wall_height), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +wall_height-1), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +wall_height-2), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +wall_height-3), \
// 		// 	create_rgb(255, 255, 255));
// 		// my_mlx_pixel_put(&data->img, data->id, (W_HEIGHT / 2 - (wall_height / 2) +wall_height/2), \
// 		// 	create_rgb(255, 255, 255));

// 		data->id++;
// 	}
// 	return (data->id = 0, 0);
// }

