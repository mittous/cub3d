/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 06:32:40 by imittous          #+#    #+#             */
/*   Updated: 2023/02/16 12:27:04 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mini_check(char map)
{
	if (map != 'N' && map != 'S' && map != 'E' && map != 'W' && map != ' '
		&& map != '0' && map != '1' && map != '\n')
		return (0);
	return (1);
}

void	ft_count_char(char c, t_cube *cube)
{
	if (mini_check(c))
	{
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			cube->player++;
			cube->player_char = c;
		}
		else if (c == '1')
			cube->one++;
		else if (c == '0')
			cube->zero++;
	}
	else
		ft_wrong_character_err(c);
}

char	**ft_split_gnl(char const *s, char c)
{
	char	**word;
	int		lwrd;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	word = malloc (7 * sizeof(char *));
	if (!word)
		return (NULL);
	while (*s && j != 6)
	{
		while (*s == c && *s)
			s++;
		lwrd = 0;
		while (s[lwrd] != c && s[lwrd])
			lwrd++;
		if (*s && lwrd)
			word[j++] = ft_substr(s, 0, lwrd);
		if (lwrd != 0 && !(word[j - 1]))
			return (0);
		s += lwrd;
	}
	word[j] = NULL;
	return (word);
}
