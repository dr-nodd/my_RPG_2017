/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** write in save file
*/

#include "my.h"
#include "save.h"
#include "struct.h"

char *write_fourth_in_game(int x, char *str, game_t *game)
{
	switch (x) {
	case (11):
		str = my_strcat(str, my_itoa(game->player_stat.max_xp, 10));
		break;
	case (12):
		str = my_strcat(str, my_itoa(game->player_stat.lvl, 10));
		break;
	case (13):
		str = my_strcat(str, my_itoa(game->ui.arrow_nbr, 10));
		break;
	}
	return (str);
}

char *write_third_in_save(int x, char *str, game_t *game)
{
	switch (x) {
	case (7):
		str = my_strcat(str, my_itoa(game->ui.potion_nbr, 10));
		break;
	case (8):
		str = my_strcat(str, save_equipement(game));
		break;
	case (9):
		str = my_strcat(str, my_itoa(game->player_stat.money, 10));
		break;
	case (10):
		str = my_strcat(str, my_itoa(game->player_stat.xp, 10));
		break;
	default:
		str = write_fourth_in_game(x, str, game);
		break;
	}
	return (str);
}

char *write_two_in_save(int x, char *str, game_t *game)
{
	switch (x) {
	case (3):
		str = my_strcat(str, my_itoa(game->player_stat.max_health,
			10));
		break;
	case (4):
		str = my_strcat(str, my_itoa(game->player_stat.mana, 10));
		break;
	case (5):
		str = my_strcat(str, my_itoa(game->player_stat.max_mana, 10));
		break;
	case (6):
		str = my_strcat(str, my_itoa(game->ui.potion_mana_nbr, 10));
		break;
	default:
		str = write_third_in_save(x, str, game);
		break;
	}
	return (str);
}

char *write_in_save(int x, char *str, game_t *game)
{
	sfVector2f pos = sfSprite_getPosition(game->player.sprite);

	switch (x) {
	case (0):
		str = my_strcat(str, my_itoa(pos.x, 10));
		break;
	case (1):
		str = my_strcat(str, my_itoa(pos.y, 10));
		break;
	case (2):
		str = my_strcat(str, my_itoa((int)(game->player_stat.health),
			10));
		break;
	default:
		str = write_two_in_save(x, str, game);
	}
	return (str);
}
