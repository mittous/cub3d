/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 06:38:22 by imittous          #+#    #+#             */
/*   Updated: 2023/02/14 06:46:13 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_wrong_character_err(char s)
{
	printf("character '%c' is not valid\n", s);
	exit(0);
}

void	ft_messing_character_err(char *message)
{
	printf("%s in your map, please add them all so you can enjoy the game", \
		message);
	exit(0);
}
