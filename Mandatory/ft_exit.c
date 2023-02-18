/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:15:01 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/18 11:33:52 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(t_data **game)
{
	mlx_destroy_image((*game)->win->mlx_ptr, (*game)->draw->img);
	mlx_destroy_window((*game)->win->mlx_ptr, (*game)->win->window);
	free_word((*game)->cube->map);
	free((*game)->cube);
	free((*game)->win);
	free((*game)->draw);
	free((*game)->p);
	free((*game));
	exit(0);
}
