/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:23:34 by imittous          #+#    #+#             */
/*   Updated: 2023/02/15 13:22:16 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/cub3d.h"

char	*ft_read_buff_size_cub(char *lines, char *bufer, t_cube *cube, \
	char old_read)
{
	if (bufer[0] == '\n')
	{
		if (old_read != '\n')
		{
			lines = ft_strjoin_gnl(lines, bufer);
			cube->count_text++;
		}
		if (old_read == '\n' && cube->count_text > 6)
			ft_putendl_fd("new line on the map", 2);
	}
	else
		lines = ft_strjoin_gnl(lines, bufer);
	if (bufer[0] && cube->count_text > 5)
		ft_count_char(bufer[0], cube);
	return (lines);
}

char	*read_buff_size_cub(int fd, char *lines, t_cube *cube)
{
	char	*bufer;
	char	old_read;
	int		i;

	bufer = malloc(BUFFER_SIZE + 1);
	if (!bufer)
		return (NULL);
	lines = NULL;
	old_read = '\n';
	i = 1;
	while (i)
	{
		i = read(fd, bufer, BUFFER_SIZE);
		if (i == -1)
		{
			free(bufer);
			return (NULL);
		}
		bufer[i] = '\0';
		lines = ft_read_buff_size_cub(lines, bufer, cube, old_read);
		old_read = bufer[0];
	}
	free (bufer);
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
	one_line_cub(file_line, cube);
	if (cube->player != 1 || cube->one < 1 || cube->zero < 1)
		ft_messing_character_err("missing character (\"N/S/E/W \",0,1)");
}
