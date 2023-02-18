/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 06:38:22 by imittous          #+#    #+#             */
/*   Updated: 2023/02/18 08:46:20 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_wrong_character_err(void)
{
	ft_putendl_fd("Make sure your map is valid\n \
and you have just the (6) informations needed\n", 2);
}
