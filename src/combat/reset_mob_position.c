/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Mob
*/

#include "my.h"
#include "mob.h"
#include "struct.h"
#include "tools.h"

void reset_mob_position(game_t *game, int i)
{
	sfVector2f pos = (sfVector2f){0, 0};

	pos.x = frand_a_b(500 - 200, 500 + 200);
	pos.y = frand_a_b(500 - 200, 500 + 200);
	sfSprite_setPosition(game->mob[i].sprite, pos);
}
