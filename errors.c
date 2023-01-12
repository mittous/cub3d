
#include "cub3d.h"

void	ft_wrong_character_err(char s)
{
	printf("character %c is not valid\n", s);
	exit(0);
}

void	ft_messing_character_err(char *message)
{
	printf("%s in your map, please add it so you can enjoy the game", message);
	exit(0);
}
