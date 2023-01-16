
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
			return (free_word(word), NULL);
		s += lwrd;
	}
	word[j] = NULL;
	return (word);
}

// char	*get_next_line(int fd, t_cube *cube, int check_digit)
// {
// 	static char	*lines;
// 	char		*bufer;
// 	int			read_ret;
// 	int			check_nl;
// 	int			count_id;

// 	read_ret = 1;
// 	bufer = malloc(2);
// 	lines = malloc(1);
// 	check_nl = 0;
// 	if (!bufer)
// 		return (NULL);
// 	count_id = 0;
// 	while (read_ret)
// 	{
// 	printf ("check_digit = %d\n", check_digit);
// 	printf ("count_id = %d\n", count_id);
// 		if (check_digit == 0 && count_id == 6)
// 			break ;
// 		read_ret = read(fd, bufer, 1);
// 		if (read_ret == -1) 
// 		{
// 			ft_putendl_fd("Error wille reading file", 2);
// 			exit (0);
// 		}
// 		bufer[1] = '\0';
// 		if (check_nl == 1 && bufer[0] != '\n')
// 		{
// 			count_id++;
// 			check_nl = 0;
// 		}
// 		if (check_digit == 1 && !mini_check(bufer[0])) //had lblasa fach kaysali i9ra ident kaylga \n okayzidha flmap
// 		{
// 			printf ("-*%c*-\n", lines[0]);
// 			ft_wrong_character_err(bufer[0]);
// 		}
// 		if (!read_ret || /* (check_digit == 0 && count_id == 6)|| */ (check_digit == 1 && bufer[0] == '\n' && bufer[0] == lines[ft_strlen(lines) - 1]))
// 		{
// 			printf ("*-%c-*\n", bufer[0]);
// 			break ;
// 		}
// 		if (bufer[0] == '\n')
// 			check_nl = 1;
// 		ft_count_char(bufer[0], cube);
// 		lines = ft_strjoin(lines, bufer);
// 	}

// 	// if (cube->player != 1)
// 	// 	ft_messing_character_err("You'r messing one of the following chars (N,E,W,S)");
// 	// if (cube->one < 1)
// 	// 	ft_messing_character_err("Ther is no wall (1)");
// 	// if (cube->zero < 1)
// 	// 	ft_messing_character_err("Ther is no free space (0)");
// 	// free (bufer);
// 	printf ("%s\n", lines);
// 	return (lines);
// }
