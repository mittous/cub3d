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

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		l;
	char	*k;
	int		j;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	k = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!k)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		k[j++] = s1[i++];
	l = 0;
	while (s2[l])
		k[j++] = s2[l++];
	k[j] = '\0';
	free(s1);
	return (k);
}

char	*read_buff_size(int fd, char *lines, t_cube *cube)
{
	char	*bufer;
	char	old_read;
	int		count_text;
	int		i;

	i = 1;
	count_text = 0;
	old_read = '\n';
	bufer = malloc(BUFFER_SIZE + 1);
	lines = malloc(BUFFER_SIZE + 1);
	if (!bufer)
		return (NULL);
	while (i)
	{
		i = read(fd, bufer, BUFFER_SIZE);
		if (i == -1)
		{
			free(bufer);
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
	return (lines);
}

void	one_line(char *lines, t_cube *cube)
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
		{
			j++;
		}
		lines++;
	}
	cube->map = ft_split(lines, '\n');
}

void	get_next_line(int fd, t_cube *cube)
{
	static char	*file_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ;
	file_line = read_buff_size(fd, file_line, cube);
	if (!file_line)
		return ;
	one_line(file_line, cube);
}
