/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:21:03 by mel-hous          #+#    #+#             */
/*   Updated: 2023/01/18 15:28:30 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
# include  <mlx.h>

// void    player_print(t_data *conf)
// {
//     int r = 15; 
//     int i = 0;
//     int j = 0;
//     double x = conf->p->x;
//     double y = conf->p->y;
//     i = -r;
//     int f = 0;
//     // line(conf,conf->player.py * minimap,
// 	// conf->player.px * minimap,
// 	// ((conf->player.py  + ( 10 * sin(conf->player.rotangle)) * minimap)) ,
// 	// ((conf->player.px  + ( 10 * cos(conf->player.rotangle)) * minimap)), C2);
//     i = -r;
//     while (i < r)
//     {
//         j = -r;
//         while (j < r)
//         {
//             if ((i * i) + (j * j) <= (r * r))
//             {
//                 conf->draw->addr[(int)(((i + y))) *
//                 WIN_WIDTH + (int)(((j + x) ))] = RED;
//                 // conf->img.addr[(int)(((i + y))) *
//                 // (WIDTH) + (int)(((j + x)))] = C2;
//             }
//             j++;
//         }
//         i++;
//     }
// }
void	my_mlx_pixel_put(t_draw *data, int y, int x, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void print_pixel(t_data *test, int x, int y, int color )
{
   int i;
   int j;
    x *= 30;
    y *= 30;
    i = 0;
    
    while (i < 29)
    {
        j = 0;
        while (j < 29)
        {
          
            // if(((x == test->p->x * 30) && (y == test->p->y * 30)) && (j == 15 && i == 15))
            //     my_mlx_pixel_put(test->draw, y + j ,x + i, RED);
            // else
            my_mlx_pixel_put(test->draw, y + j ,x + i, color);
            j++;
        }
        i++;
    }
    // player_print(test);
    my_mlx_pixel_put(test->draw, test->p->y ,test->p->x, RED);
}

// t_player    p_init()
// {
//     t_player    p;

//     p.x = 0;
//     p.y = 0;
//     p.turn_direction = 0;
//     p.walk_direction = 0;
//     p.move_speed = 2.0;
//     p.retation_angle = M_PI / 2;
//     p.retation_speed = 3 * (M_PI / 180);
//     return (p);
// }

int draw_2d_map(t_data *sd)
{
    // t_display win;
    int i;
    int j;

    t_player   p;

    i = 0;
    j = 0;
    
    sd->draw->img = mlx_new_image(sd->win->mlx_ptr, WIN_WIDTH,  WIN_HEIGHT);
    sd->draw->addr = mlx_get_data_addr(sd->draw->img, &sd->draw->bits_per_pixel, &sd->draw->line_length,&sd->draw->endian);
    while(sd->cube->map[i])
    {
        j = 0;
        while(sd->cube->map[i][j])
        {
            if (sd->cube->map[i][j] == '1')
                print_pixel(sd,j,i,BLACK);
            else if (sd->cube->map[i][j] == '0')
                print_pixel(sd,j,i,WHITE);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window( sd->win->mlx_ptr, sd->win->window, sd->draw->img, 0, 0);
    // mlx_key_hook(win.window, key_hook, &draw);
    return(0);
}