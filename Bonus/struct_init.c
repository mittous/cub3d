/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:39:38 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/16 09:19:11 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_data	*allocate_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
	{
		return (NULL);
	}
	data->p = (t_player *)malloc(sizeof(t_player));
	if (data->p == NULL)
	{
		free(data);
		return (NULL);
	}
	data->draw = (t_draw *)malloc(sizeof(t_draw));
	if (data->draw == NULL)
	{
		free(data->p);
		free(data);
		return (NULL);
	}
	data->win = (t_display *)malloc(sizeof(t_display));
	if (data->win == NULL)
	{
		free(data->draw);
		free(data->p);
		free(data);
		return (NULL);
	}
	data->cube = (t_cube *)malloc(sizeof(t_cube));
	if (data->cube == NULL)
	{
		free(data->win);
		free(data->draw);
		free(data->p);
		free(data);
		return (NULL);
	}
	data->line = (t_line *)malloc(sizeof(t_line));
	if (data->line == NULL)
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
