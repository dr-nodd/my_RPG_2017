/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Destroy enemies
*/

#include "struct.h"
#include "mob.h"

void destroy_mob(game_t *game)
{
	for (int i = 0; i < MOBS_COUNT; i++) {
		sfSprite_destroy(game->mob[i].sprite);
		sfTexture_destroy(game->mob[i].texture);
		sfSprite_destroy(game->mobshadow[i].sprite);
		sfTexture_destroy(game->mobshadow[i].texture);
	}
}
