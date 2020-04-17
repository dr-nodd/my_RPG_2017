/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Change player equipment
*/

#include <stdlib.h>
#include "class.h"
#include "struct.h"

void change_player_equipment(game_t *game)
{
	int equipment;
	sfTexture *texture;

	equipment = sfSprite_getTextureRect(game->armors_prompt.sprite).top /
		sfSprite_getTextureRect(game->armors_prompt.sprite).height;
	sfTexture_destroy(game->player.texture);
	texture = sfTexture_createFromFile(game->armors_t_path[equipment],
		NULL);
	if (!texture)
		return;
	sfSprite_setTexture(game->player.sprite, texture, sfTrue);
	game->player.equipment = equipment;
	if (equipment == DAGGER || equipment == ARCHER)
		game->player_stat.speed = 1.7;
	else if (equipment == GOD || equipment == WARRIOR)
		game->player_stat.speed = 1.2;
	else
		game->player_stat.speed = 1.5;
	sfSprite_setTextureRect(game->high_dust.sprite, (sfIntRect){0, 0, 174,
		213});
}
