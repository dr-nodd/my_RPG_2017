/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Check if mage class is unlocked
*/

#include "display.h"
#include "struct.h"

void check_if_mage_is_unlocked(window_t *window, game_t *game)
{
	if (game->armor_unlocked[4] == 1) {
		sfSprite_setPosition(game->pixel_check.sprite,
		sfSprite_getPosition(game->shop_items[3].sprite));
		sfRenderWindow_drawSprite(window->window,
		game->pixel_check.sprite, NULL);
	}
}
