/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Load game
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"
#include "my.h"
#include "save.h"

void load_equipement(game_t *game, char *str)
{
	int n = 0;

	while (n != 6) {
		game->armor_unlocked[n] = str[n] - 48;
		n++;
	}
}

int load_game(game_t *game)
{
	int fd = open(".save", O_RDONLY);
	char **array = config_load();
	char *str;
	int i = 0;

	while ((str = get_next_line(fd, '\n')) != NULL) {
		for (i = 0; my_strcmp(find_name(str), array[i]) != 0; i++);
		load_variable(i, str, game);
		free(str);
	}
	sfSprite_setPosition(game->player.sprite, game->player.pos);
	close (fd);
	return (0);
}
