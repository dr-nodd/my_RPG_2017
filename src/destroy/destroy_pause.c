/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Destroy pause
*/

#include "struct.h"

void destroy_pause(game_t *game)
{
	for (int i = 0; i < 7; i++) {
		sfSprite_destroy(game->pause_button[i].sprite);
		sfTexture_destroy(game->pause_button[i].texture);
	}
	sfSprite_destroy(game->scroll.sprite);
	sfTexture_destroy(game->scroll.texture);
	sfSprite_destroy(game->pause_rect.sprite);
	sfTexture_destroy(game->pause_rect.texture);
	for (int i = 0; i < 2; i++) {
		sfSprite_destroy(game->pause_text[i].sprite);
		sfTexture_destroy(game->pause_text[i].texture);
	}
	sfSprite_destroy(game->pause.sprite);
	sfTexture_destroy(game->pause.texture);
	sfSprite_destroy(game->vignette.sprite);
	sfTexture_destroy(game->vignette.texture);
}
