/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:16:50 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/17 14:29:53 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game(t_data *game)
{
	game->win->window = mlx_new_window(game->win->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "cub3d");
	p_search(game, game->cube, 0, 0);
	mlx_hook(game->win->window, 2, 1L << 1, key_hook, &game);
	mlx_hook(game->win->window, 17, 0, ft_exit, &game);
	mlx_hook(game->win->window, 3, 2L << 0, key_rel, &game);
	mlx_loop_hook(game->win->mlx_ptr, draw_2d_map, &game);
	mlx_loop(game->win->mlx_ptr);
}
