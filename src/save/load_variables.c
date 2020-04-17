/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Load variables
*/

#include "my.h"
#include "struct.h"
#include "save.h"

void load_third_variable(int x, char *str, game_t *game)
{
	switch (x) {
	case (8):
		load_equipement(game, find_variable_name(str));
		break;
	case (9):
		game->player_stat.money = my_getnbr(find_variable_name(str));
		break;
	case (10):
		game->player_stat.xp = my_getnbr(find_variable_name(str));
		break;
	case (11):
		game->player_stat.max_xp = my_getnbr(find_variable_name(str));
		break;
	case (12):
		game->player_stat.lvl = my_getnbr(find_variable_name(str));
		break;
	case (13):
		game->ui.arrow_nbr = my_getnbr(find_variable_name(str));
		break;
	}
}

void load_second_variable(int x, char *str, game_t *game)
{
	switch (x) {
	case (4):
		game->player_stat.mana = my_getnbr(find_variable_name(str));
		break;
	case (5):
		game->player_stat.max_mana =
			my_getnbr(find_variable_name(str));
		break;
	case (6):
		game->ui.potion_mana_nbr = my_getnbr(find_variable_name(str));
		break;
	case (7):
		game->ui.potion_nbr = my_getnbr(find_variable_name(str));
		break;
	default:
		load_third_variable(x, str, game);
	}
}

void load_variable(int x, char *str, game_t *game)
{
	switch (x) {
	case (0):
		game->player.pos.x = my_getnbr(find_variable_name(str));
		break;
	case (1):
		game->player.pos.y = my_getnbr(find_variable_name(str));
		break;
	case (2):
		game->player_stat.health = my_getnbr(find_variable_name(str));
		break;
	case (3):
		game->player_stat.max_health =
			my_getnbr(find_variable_name(str));
		break;
	default:
		load_second_variable(x, str, game);
		break;
	}
}
