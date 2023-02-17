/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:34:24 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/17 14:34:42 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_exit(t_data **game)
{
	free_word((*game)->cube->map);
	free((*game)->cube);
	free((*game)->win);
	free((*game)->draw);
	free((*game)->p);
	free((*game));
	exit(0);
}
