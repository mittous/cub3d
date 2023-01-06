
#include "cub3d.h"

int	mini_check(char map)
{
	if (map != 'N' && map != 'S' && map != 'E' && map != 'W' && map != ' '
		&& map != '0' && map != '1' && map != '\n')
		return (0);
	return (1);
}

void	ft_count_char(char c, t_char_map *char_map)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		char_map->player++;
	if (c == '1')
		char_map->one++;
	if (c == '0')
		char_map->zero++;
}

char	*get_next_line(int fd, t_char_map *char_map)
{
	static char	*lines;
	char		*bufer;
	int			read_ret;

	read_ret = 1;
	bufer = malloc(2);
	lines = malloc(1);
	if (!bufer || !lines)
		return (NULL);
	while (read_ret > 0)
	{
		read_ret = read(fd, bufer, 1);
		if (read_ret == -1 || !mini_check(bufer[0]))
			ft_wrong_character_err(bufer[0]);
		ft_count_char(bufer[0], char_map);
		bufer[1] = '\0';
		lines = ft_strjoin(lines, bufer);
	}
	if (char_map->player != 1)
		ft_messing_character_err("You'r messing one of the following chars (N,E,W,S)");
	if (char_map->one < 1)
		ft_messing_character_err("Ther is no wall (1)");
	if (char_map->zero < 1)
		ft_messing_character_err("Ther is no free space (0)");
	free (bufer);
	return (lines);
}

