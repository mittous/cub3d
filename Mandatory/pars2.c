/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:46:26 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/18 10:46:32 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi_cub(const char *str)
{
	int	i;
	int	sign;
	int	base;

	sign = 1;
	i = 0;
	base = 0;
	while (str[i] && (str[i] == ' '))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		base = (base * 10) + (str[i] - 48);
		if (base > 255 && sign == 1)
			ft_putendl_fd("your number is > than 255", 2);
		i++;
	}
	while (str[i] && (str[i] == ' '))
		i++;
	if (!str[i])
		return (base * sign);
	ft_putendl_fd("this format (1 , 2, 3) is not valid, this( 1,2,3)", 2);
	return (0);
}

int	ft_tronsform_int_to_rgb(int count, char *color, int rgb_color)
{
	int		i;
	char	**rgb;

	i = -1;
	if (count == 2)
	{
		rgb = ft_split(color, ',');
		free (color);
		while (rgb[++i])
			if (ft_atoi_cub(rgb[i]) < 0 || ft_atoi_cub(rgb[i]) > 255)
				ft_putendl_fd("color is not valid", 2);
		if (rgb[0] && rgb[1] && rgb[2])
		{
			rgb_color = ft_rgb_to_color(ft_atoi_cub(rgb[0]), \
				ft_atoi_cub(rgb[1]), ft_atoi_cub(rgb[2]));
			free_word(rgb);
			return (rgb_color);
		}
	}
	ft_putendl_fd("color is not valid", 2);
	return (0);
}
