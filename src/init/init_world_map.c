/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Init world map
*/

#include "struct.h"
#include "init.h"

void init_world_map(game_t *game)
{
	init_img(&game->world_map, "assets/map/map.png",
		(sfIntRect){0, 0, 1920, 1080}, (sfVector2f){0, 0});
	init_music(&game->page_flip, "assets/musics/page_flip.ogg", 100,
		sfFalse);
}
