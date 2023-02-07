#include "../cub3d.h"

void    ft_read_textur_files(t_data *data)
{
	// printf ("%s\n", data->cube->ea);
	data->textur[0].fd = open(data->cube->ea, O_RDONLY);
	data->textur[1].fd = open(data->cube->so, O_RDONLY);
	data->textur[2].fd = open(data->cube->no, O_RDONLY);
	data->textur[3].fd = open(data->cube->we, O_RDONLY);
	if (data->textur[0].fd < 0 || data->textur[1].fd < 0 || data->textur[2].fd < 0 || data->textur[3].fd < 0)
	{
		printf("textur file not find");
		return ;
	}
	// printf ("%d\n", data->textur[0].fd);
	data->textur[0].text_file = get_next_line(data->textur[0].fd);
	data->textur[1].text_file = get_next_line(data->textur[1].fd);
	data->textur[2].text_file = get_next_line(data->textur[2].fd);
	data->textur[3].text_file = get_next_line(data->textur[3].fd);
}

void    ft_get_textur(t_data *data)
{
	ft_read_textur_files(data);
	// printf ("%s\n", data->textur[0].text_file);
}