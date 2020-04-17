/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** World map display
*/

#include <stdlib.h>
#include "struct.h"

void display_world_map(window_t *window, game_t *game)
{
	sfView_setSize(window->camera, (sfVector2f){1920, 1080});
	sfRenderWindow_setView(window->window, window->camera);
	sfSprite_setPosition(game->world_map.sprite,
	sfView_getCenter(window->camera));
	sfRenderWindow_clear(window->window, sfBlack);
	sfRenderWindow_drawSprite(window->window, game->world_map.sprite,
	NULL);
}
