/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:21:03 by mel-hous          #+#    #+#             */
/*   Updated: 2023/01/22 11:25:07 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
# include  <mlx.h>

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
    x *= TILE_SIZE;
    y *= TILE_SIZE;
    i = 0;
    
    while (i < TILE_SIZE - 1)
    {
        j = 0;
        while (j < TILE_SIZE - 1)
        {
            my_mlx_pixel_put(test->draw, y + j ,x + i, color);
            j++;
        }
        i++;
    }
    // player_print(test);
	test->p->xx = test->p->x -3;
	while (test->p->xx < test->p->x + 3)
	{
		test->p->yy = test->p->y -3;
		while (test->p->yy < test->p->y + 3)
		{
		    my_mlx_pixel_put(test->draw, test->p->yy ,test->p->xx, RED);
			test->p->yy++;
		}
		test->p->xx++;
	}
}

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
    ft_raycasting(sd);
    mlx_put_image_to_window( sd->win->mlx_ptr, sd->win->window, sd->draw->img, 0, 0);
    ft_move(sd);
    // mlx_key_hook(win.window, key_hook, &draw);
    return(0);
}