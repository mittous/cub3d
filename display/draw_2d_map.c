/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:21:03 by mel-hous          #+#    #+#             */
/*   Updated: 2023/01/17 15:15:21 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
# include  <mlx.h>

void print_pixel(char **img_addr, int y, int x, int color)
{
    int i;
    int j;

    x *= 50;
    y *= 50;
    i = 0;
    while (i < 50)
    {
        j = 0;
        while (j < 50)
        {
            
            img_addr[(int)(y + j)+ (int)((x + i))] = color;
            j++;
        }
        i++;
    }
}

void draw_2d_map(char **map)
{
    t_display win;
    int i;
    int j;

    i = 0;
    j = 0;
    int y;
    int x;
    int pixel_bits;
    int line_bytes;
    int endian;
  
    win.mlx_ptr = mlx_init();
    win.window = mlx_new_window(win.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
    win.image = mlx_new_image(win.mlx_ptr, 50, 50);
    char *buffer = mlx_get_data_addr(win.image, &pixel_bits, &line_bytes, &endian);
    while(map[j])
    {
        while(map[j][i])
        {
            if (map[j][i] == 1)
            {
                print_pixel(&buffer,j,i,0xABCDEF);
                i++;
            }
            if (map[j][i] == 0)
            {
                print_pixel(&buffer,j,i,3136335);
                i++;
            }
            i++;
        }
        j++;
    }
//     int color = 0xABCDEF;

// if (pixel_bits != 32)
//     color = mlx_get_color_value(win.mlx_ptr, color);

// for(int y = 0; y < 360; ++y)
// for(int x = 0; x < 640; ++x)
// {
//     int pixel = (y * line_bytes) + (x * 4);

//     if (endian == 1)        // Most significant (Alpha) byte first
//     {
//         buffer[pixel + 0] = (color >> 24);
//         buffer[pixel + 1] = (color >> 16) & 0xFF;
//         buffer[pixel + 2] = (color >> 8) & 0xFF;
//         buffer[pixel + 3] = (color) & 0xFF;
//     }
//     else if (endian == 0)   // Least significant (Blue) byte first
//     {
//         buffer[pixel + 0] = (color) & 0xFF;
//         buffer[pixel + 1] = (color >> 8) & 0xFF;
//         buffer[pixel + 2] = (color >> 16) & 0xFF;
//         buffer[pixel + 3] = (color >> 24);
//     }
// }
    mlx_loop(win.mlx_ptr);
}