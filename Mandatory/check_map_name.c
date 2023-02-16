/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 06:29:22 by imittous          #+#    #+#             */
/*   Updated: 2023/02/16 08:48:58 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_checkber(char *s, int ac)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putendl_fd("there is no map name", 2);
		exit(0);
	}
	while (s[i])
		i++;
	if (!s[i] && s[i - 1] == 'b' && s[i - 2] == 'u' && ac == 2
		&& s[i - 3] == 'c' && s[i - 4] == '.')
		return (1);
	else if (ac != 2)
		ft_putendl_fd("number of argument is not '2'", 2);
	else
		ft_putendl_fd("map extention is not '.cub'", 2);
	exit(0);
}
