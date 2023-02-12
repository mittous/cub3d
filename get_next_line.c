/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:23:34 by imittous          #+#    #+#             */
/*   Updated: 2021/12/19 22:25:32 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


char	*read_buff_size_cub(int fd, char *lines, t_cube *cube)
{
	char	*bufer;
	char	old_read;
	int		count_text;
	int		i;

	i = 1;
	count_text = 0;
	old_read = '\n';
	bufer = malloc(BUFFER_SIZE + 1);
	lines = NULL; // = malloc(BUFFER_SIZE + 1);
	if (!bufer)
		return (NULL);
	while (i)
	{
		i = read(fd, bufer, BUFFER_SIZE);
		if (i == -1)
		{
			free(bufer);
			bufer = NULL;
			return (NULL);
		}
		bufer[i] = '\0';

		if (bufer[0] == '\n')
		{
			if (old_read != '\n')
			{
				lines = ft_strjoin_gnl(lines, bufer);
				count_text++;
			}
			if (old_read == '\n' && count_text > 6)
			{
				ft_putendl_fd("new line on the map", 2);
				exit (0);
			}
		}
		else
			lines = ft_strjoin_gnl(lines, bufer);
		if (bufer[0] && count_text > 5)
			ft_count_char(bufer[0], cube);
		old_read = bufer[0];
	}
	free (bufer);
	bufer = NULL;
	return (lines);
}

void	one_line_cub(char *lines, t_cube *cube)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!lines[i])
		return ;
	cube->texture = ft_split_gnl(lines, '\n');
	while (*lines && j != 6)
	{
		if (*lines == '\n')
			j++;
		lines++;
	}
	cube->map = ft_split(lines, '\n');
}

void	get_next_line_cub(int fd, t_cube *cube)
{
	static char	*file_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ;
	file_line = read_buff_size_cub(fd, file_line, cube);
	if (!file_line)
		return ;
	one_line_cub(file_line, cube);
	if (cube->player != 1)
		ft_messing_character_err("You'r messing one of the following chars (N,E,W,S)");
	if (cube->one < 1)
		ft_messing_character_err("Ther is no wall (1)");
	if (cube->zero < 1)
		ft_messing_character_err("Ther is no free space (0)");
}