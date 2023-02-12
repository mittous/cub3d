#include "../cub3d.h"

void    ft_get_textur(t_data *data)
{
	int tmp;

	data->textur[0].img = mlx_xpm_file_to_image(data->win->mlx_ptr, data->cube->so, &data->textur[0].height, \
	&data->textur[0].width);
	data->textur[0].addr = (int *)mlx_get_data_addr(data->textur[0].img, &tmp, &tmp, &tmp);

	data->textur[1].img = mlx_xpm_file_to_image(data->win->mlx_ptr, data->cube->ea, &data->textur[1].height, \
	&data->textur[1].width);
	data->textur[1].addr = (int *)mlx_get_data_addr(data->textur[1].img, &tmp, &tmp, &tmp);
}