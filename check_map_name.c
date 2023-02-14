/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 06:29:22 by imittous          #+#    #+#             */
/*   Updated: 2023/02/14 06:36:28 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_checkber(char *s, int ac)
{
	int	i;

	i = 0;
	if (!s)
	{
		printf("there is no map name");
		exit(0);
	}
	while (s[i])
		i++;
	if (!s[i] && s[i - 1] == 'b' && s[i - 2] == 'u' && ac == 2
		&& s[i - 3] == 'c' && s[i - 4] == '.')
		return (1);
	else if (ac != 2)
		printf("number of argument is not '2'");
	else
		printf("map extention is not '.cub'");
	exit(0);
}
