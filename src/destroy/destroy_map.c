/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Destroy environment
*/

#include "struct.h"

void destroy_world_map(game_t *game)
{
	sfSprite_destroy(game->world_map.sprite);
	sfTexture_destroy(game->world_map.texture);
}

void destroy_environment(game_t *game)
{
	sfSprite_destroy(game->col.sprite);
	sfTexture_destroy(game->col.texture);
	sfSprite_destroy(game->grass.sprite);
	sfTexture_destroy(game->grass.texture);
	destroy_world_map(game);
}
