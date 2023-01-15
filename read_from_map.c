
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

char	*get_next_line(int fd, t_cube *cube, int check_digit)
{
	static char	*lines;
	char		*bufer;
	int			read_ret;
	int			check_nl;
	int			count_id;

	read_ret = 1;
	count_id = 0;
	bufer = malloc(2);
	lines = malloc(1);
	check_nl = 0;
	if (!bufer)
		return (NULL);
	while (read_ret)
	{
		read_ret = read(fd, bufer, 1);
		if (read_ret == -1) 
		{
			ft_putendl_fd("Error wille reading file", 2);
			exit (0);
		}
		bufer[1] = '\0';
		if (check_nl == 1 && bufer[0] != '\n')
		{
			count_id++;
			check_nl = 0;
		}
		if (check_digit == 1 && !mini_check(bufer[0])) //had lblasa fach kaysali i9ra ident kaylga \n okayzidha flmap
		{
			printf ("-*%c*-\n", lines[0]);
			ft_wrong_character_err(bufer[0]);
		}
		if (!read_ret || (check_digit == 0 && count_id == 6)|| (check_digit == 1 && bufer[0] == '\n' && bufer[0] == lines[ft_strlen(lines) - 1]))
			break ;
		if (bufer[0] == '\n')
			check_nl = 1;
		ft_count_char(bufer[0], cube);
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
