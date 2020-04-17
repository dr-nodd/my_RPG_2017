/*
** EPITECH PROJECT, 2018
** voila
** File description:
** my_rpg
*/

#include <stdlib.h>
#include "mouse.h"
#include "struct.h"

void load_pause(window_t *window, game_t *game)
{
	sfImage *image;
	sfTexture *texture;

	sfView_destroy(window->camera);
	image = sfRenderWindow_capture(window->window);
	window->camera = sfView_createFromRect((sfFloatRect){0, 0,
		(float)window->mode.width, (float)window->mode.height});
	sfSprite_setOrigin(game->pause.sprite,
		(sfVector2f){(float)window->mode.width / 2,
		(float)window->mode.height / 2});
	texture = sfTexture_createFromImage(image, NULL);
	sfSprite_setTexture(game->pause.sprite, texture, sfTrue);
	sfSprite_setPosition(game->pause_rect.sprite, (sfVector2f){-20000,
		-20000});
	sfSprite_setTextureRect(game->scroll.sprite, (sfIntRect){0, 0,
		sfSprite_getTextureRect(game->scroll.sprite).width, 0});
}

void set_pause_buttons_scale(game_t *game, int i, float scale_threshold)
{
	if (sfSprite_getScale(game->pause_button[i].sprite).x <=
	scale_threshold || sfSprite_getScale(game->pause_button[i].sprite).y
	<= scale_threshold) {
		sfSprite_scale(game->pause_button[i].sprite, (sfVector2f){1.1,
			1.1});
		sfSprite_setPosition(game->pause_rect.sprite,
			sfSprite_getPosition(game->pause_button[i].sprite));
	}
}

void set_pause_buttons(window_t *window, game_t *game)
{
	float scale_threshold = 1;

	for (int i = 0; i < 7; i++) {
		if (mouse_is_on_button(game->pause_button[i].sprite,
		window->mouse_pos))
			set_pause_buttons_scale(game, i,
			scale_threshold);
		else
			sfSprite_setScale(game->pause_button[i].sprite,
				(sfVector2f){0.8, 0.8});
	}
}
