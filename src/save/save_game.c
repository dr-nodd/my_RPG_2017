/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Save functions
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "struct.h"
#include "save.h"

char *save_equipement(game_t *game)
{
	char *new;
	char *tmp;
	int n = 0;

	new = malloc(sizeof(char) * 7);
	while (n != 6) {
		tmp = my_itoa(game->armor_unlocked[n], 10);
		new[n] = tmp[0];
		n++;
	}
	new[n] = '\0';
	return (new);
}

char **config_array(game_t *game)
{
	char **array;

	array = malloc(sizeof(char *) * 15);
	array[0] = write_in_save(0, "POSX:", game);
	array[1] = write_in_save(1, "POSY:", game);
	array[2] = write_in_save(2, "LIFE:", game);
	array[3] = write_in_save(3, "LIFEMAX:", game);
	array[4] = write_in_save(4, "MANA:", game);
	array[5] = write_in_save(5, "MANAMAX:", game);
	array[6] = write_in_save(6, "MANAPOTION:", game);
	array[7] = write_in_save(7, "LIFEPOTION:", game);
	array[8] = write_in_save(8, "EQUIPEMENT:", game);
	array[9] = write_in_save(9, "MONEY:", game);
	array[10] = write_in_save(10, "XP:", game);
	array[11] = write_in_save(11, "XPMAX:", game);
	array[12] = write_in_save(12, "LVL:", game);
	array[13] = write_in_save(13, "ARROW:", game);
	array[14] = NULL;
	return (array);
}

int change_name(char **array)
{
	int n = 0;
	int fd = open(".save", O_RDWR | O_TRUNC);

	while (array[n] != NULL) {
		write(fd, array[n], my_strlen(array[n]));
		write(fd, "\n", 1);
		n++;
	}
	close (fd);
	return (0);
}

int save_game(game_t *game)
{
	char **array = config_array(game);
	int fd = open(".save", O_WRONLY);

	if (fd < 0) {
		close(fd);
		open(".save", O_CREAT);
	}
	change_name(array);
	return (0);
}
