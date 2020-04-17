/*
** EPITECH PROJECT, 2018
** init player stat
** File description:
** RPG
*/

#include "struct.h"
#include "init.h"

void init_stat(game_t *game)
{
	init_text(&game->ui.hp_stat_txt, "assets/fonts/pixelade.ttf",
		80, "HP");
	game->player_stat.health = 100.0;
	game->player_stat.money = 10;
	game->player_stat.max_health = 100;
	game->player_stat.xp = 0;
	game->player_stat.lvl = 1;
	game->player_stat.max_xp = 150;
	game->player_stat.mana = 150;
	game->player_stat.max_mana = 150;
	game->player_stat.speed = 1.7;
	game->player_stat.equipment = 1;
}
