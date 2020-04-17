/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Initialisation
*/

#include "struct.h"
#include "init.h"

int init_spells(game_t *game)
{
	init_sprite(&game->explosion, "assets/sprites/spells/explosion.png",
	(sfIntRect){-128, 0, 2048 / 15, 128},
	(sfVector2f){20000, 20000});
	sfSprite_setScale(game->explosion.sprite, (sfVector2f){0.7, 0.7});
	return (0);
}
