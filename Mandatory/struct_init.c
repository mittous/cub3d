/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:39:38 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/18 10:50:15 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*allocate_data1(t_data	*data)
{
	data->win = (t_display *)malloc(sizeof(t_display));
	if (!data->win)
	{
		free(data->draw);
		free(data->p);
		free(data);
		return (NULL);
	}
	data->cube = (t_cube *)malloc(sizeof(t_cube));
	if (!data->cube)
	{
		free(data->win);
		free(data->draw);
		free(data->p);
		free(data);
		return (NULL);
	}
	return (data);
}

t_data	*allocate_data2(t_data *data)
{
	data->line = (t_line *)malloc(sizeof(t_line));
	if (!data->line)
	{
		free(data->cube);
		free(data->win);
		free(data->draw);
		free(data->p);
		free(data);
		return (NULL);
	}
	return (data);
}

t_data	*allocate_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		return (NULL);
	}
	data->p = (t_player *)malloc(sizeof(t_player));
	if (!data->p)
	{
		free(data);
		return (NULL);
	}
	data->draw = (t_draw *)malloc(sizeof(t_draw));
	if (!data->draw)
	{
		free(data->p);
		free(data);
		return (NULL);
	}
	if (!allocate_data1(data) || !allocate_data2(data))
		return (NULL);
	return (data);
}
