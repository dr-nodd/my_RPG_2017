/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Pause buttons
*/

#include "mouse.h"
#include "struct.h"

void set_pause_yesno_buttons_position(game_t *game, int i)
{
	sfSprite_setPosition(game->pause_button[i].sprite,
		(sfVector2f){
		(sfSprite_getPosition(game->vignette.sprite).x
		- sfSprite_getGlobalBounds(game->vignette.sprite)
		.width / 2) + 400, (sfSprite_getPosition
		(game->vignette.sprite).y - sfSprite_getGlobalBounds
		(game->vignette.sprite).height / 2)});
	sfSprite_setPosition(game->pause_button[i].sprite,
		(sfVector2f){
		sfSprite_getPosition(game->pause_button[i].sprite).x,
		sfSprite_getPosition(game->pause_button[i].sprite).y +
		(140 * i)});
}

void set_pause_yesno_buttons_scale(game_t *game, int i, float scale_threshold)
{
	if (sfSprite_getScale(game->pause_button[i].sprite).x
	<= scale_threshold ||
	sfSprite_getScale(game->pause_button[i].sprite).y
	<= scale_threshold) {
		sfSprite_scale(game->pause_button[i].sprite,
		(sfVector2f){1.1, 1.1});
		sfSprite_setPosition(game->pause_rect.sprite,
		sfSprite_getPosition(game->pause_button[i].sprite));
	}
}

void set_pause_yesno_buttons(window_t *window, game_t *game)
{
	float scale_threshold = 1;

	for (int i = 5; i < 7; i++) {
		set_pause_yesno_buttons_position(game, i);
		if (mouse_is_on_button(game->pause_button[i].sprite,
		window->mouse_pos))
			set_pause_yesno_buttons_scale(game, i,
			scale_threshold);
		else
			sfSprite_setScale(game->pause_button[i].sprite,
			(sfVector2f){0.8, 0.8});
	}
}
