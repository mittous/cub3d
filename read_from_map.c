
#include "cub3d.h"

int	mini_check(char map)
{
	if (map != 'N' && map != 'S' && map != 'E' && map != 'W' && map != ' '
		&& map != '0' && map != '1' && map != '\n')
		return (0);
	return (1);
}

t_char_map	ft_count_char(char c, t_char_map char_map)
{
								// fix that logic //
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		char_map.player++;
	if (c == '1')
		char_map.one++;
	if (c == '0')
		char_map.zero++;
	// printf ("*-*-*-*n = %d s =  %d e = %d w = %d one = %d zero = %d\n", char_map.n, char_map.s, char_map.e, char_map.w, char_map.one, char_map.zero);
	
	return (char_map);
}

char	*get_next_line(int fd, t_char_map char_map)
{
	static char	*lines;
	char		*bufer;

	bufer = malloc(2);
	if (!bufer)
		return (NULL);
	while (char_map.read_ret > 0)
	{
		char_map.read_ret = read(fd, bufer, 1);
		if (char_map.read_ret == -1 || !mini_check(bufer[0]))
			ft_wrong_character(bufer[0]);
		char_map = ft_count_char(bufer[0], char_map);
		// printf ("n = %d s =  %d e = %d w = %d one = %d zero = %d\n", char_map.n, char_map.s, char_map.e, char_map.w, char_map.one, char_map.zero);
		bufer[char_map.read_ret] = '\0';
		lines = ft_strjoin(lines, bufer);
	}
	if (char_map.player != 1)
		ft_messing_character("You'r messing one of the following chars (N,E,W,S)");
	if (char_map.one < 1)
		ft_messing_character("Ther is no wall (1)");
	if (char_map.zero < 1)
		ft_messing_character("Ther is no free space (0)");
	free (bufer);
	return (lines);
}
