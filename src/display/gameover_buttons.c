/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Gameover buttons
*/

#include "mouse.h"
#include "struct.h"

void handle_quit_button_gameover(window_t *window, menu_t *menu, int *sound)
{
	if (mouse_is_on_button(menu->buttons[3].sprite, window->mouse_pos)) {
		if (sound[0] == 0)
			sfMusic_play(menu->hover.music);
		sound[0]++;
		sfSprite_setTextureRect(menu->buttons[3].sprite,
			(sfIntRect){3 * 724, 120, 721, 120});
	} else {
		sound[0] = 0;
		sfSprite_setTextureRect(menu->buttons[3].sprite,
			(sfIntRect){3 * 724, 0, 721, 120});
	}
}

void handle_menu_button_gameover(window_t *window, menu_t *menu, int *sound)
{
	if (mouse_is_on_button(menu->buttons[9].sprite, window->mouse_pos)) {
		if (sound[1] == 0)
			sfMusic_play(menu->hover.music);
		sound[1]++;
		sfSprite_setTextureRect(menu->buttons[9].sprite,
			(sfIntRect){9 * 724, 120, 721, 120});
	} else {
		sound[1] = 0;
		sfSprite_setTextureRect(menu->buttons[9].sprite,
			(sfIntRect){9 * 724, 0, 721, 120});
	}
}

void handle_gameover_buttons(window_t *window, menu_t *menu, game_t *game)
{
	static int sound[2];

	handle_quit_button_gameover(window, menu, sound);
	handle_menu_button_gameover(window, menu, sound);
	sfSprite_setScale(menu->buttons[3].sprite, (sfVector2f){0.2, 0.2});
	sfSprite_setScale(menu->buttons[9].sprite, (sfVector2f){0.2, 0.2});
	sfSprite_setColor(menu->buttons[3].sprite,
	sfSprite_getColor(game->gameover.sprite));
	sfSprite_setColor(menu->buttons[9].sprite,
	sfSprite_getColor(game->gameover.sprite));
	sfSprite_setPosition(menu->buttons[3].sprite,
	(sfVector2f){sfSprite_getPosition(game->gameover.sprite).x
	- sfSprite_getGlobalBounds(game->gameover.sprite).width / 1.8,
	sfSprite_getPosition(game->gameover.sprite).y -
	sfSprite_getGlobalBounds(game->gameover.sprite).height / 1.2});
	sfSprite_setPosition(menu->buttons[9].sprite,
	(sfVector2f){sfSprite_getPosition(game->gameover.sprite).x
	+ sfSprite_getGlobalBounds(game->gameover.sprite).width / 1.8,
	sfSprite_getPosition(game->gameover.sprite).y -
	sfSprite_getGlobalBounds(game->gameover.sprite).height / 1.2});
}
