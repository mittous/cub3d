
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
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		cube->player++;
		cube->player_char = c;
	}
	if (c == '1')
		cube->one++;
	if (c == '0')
		cube->zero++;
}

char	*get_next_line(int fd, t_cube *cube)
{
	static char	*lines;
	char		*bufer;
	int			read_ret;

	read_ret = 1;
	bufer = malloc(2);
	lines = malloc(1);
	if (!bufer || !lines)
		return (NULL);
	while (read_ret)
	{
		read_ret = read(fd, bufer, 1);
		if (read_ret == -1 /* || !mini_check(bufer[0]) */)
			ft_wrong_character_err(bufer[0]);
		if (!read_ret || (bufer[0] == '\n' && bufer[0] == lines[ft_strlen(lines) - 1]))
			break ;
		ft_count_char(bufer[0], cube);
		bufer[1] = '\0';
		lines = ft_strjoin(lines, bufer);
	}
	// if (cube->player != 1)
	// 	ft_messing_character_err("You'r messing one of the following chars (N,E,W,S)");
	// if (cube->one < 1)
	// 	ft_messing_character_err("Ther is no wall (1)");
	// if (cube->zero < 1)
	// 	ft_messing_character_err("Ther is no free space (0)");
	free (bufer);
	return (lines);
}

