/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Volume related functions
*/

#include "struct.h"

void change_volumes(window_t *window, menu_t *menu, int i)
{
	if (i == 0) {
		window->music_volume =
			(sfSprite_getPosition(menu->sliders[0].sprite).x -
			sfSprite_getGlobalBounds(menu->sliders_bar[0].sprite).
			left) / (sfSprite_getGlobalBounds
			(menu->sliders_bar[0].sprite).width / 100);
		sfMusic_setVolume(menu->main_menu.music,
			window->music_volume);
	} else {
		window->effect_volume =
			(sfSprite_getPosition(menu->sliders[1].sprite).x -
			sfSprite_getGlobalBounds(menu->sliders_bar[1].sprite).
			left) / (sfSprite_getGlobalBounds
			(menu->sliders_bar[1].sprite).width / 100);
		sfMusic_setVolume(menu->hover.music, window->effect_volume);
	}
}

void move_sliders(sfSprite *cursor, sfSprite *bar, sfVector2i mouse_pos)
{
	sfVector2f position;

	position = (sfVector2f){(float)mouse_pos.x,
		sfSprite_getPosition(bar).y};
	sfSprite_setPosition(cursor, position);
}

int sliders_can_move(sfVector2i mouse_pos, sfSprite *bar)
{
	return (mouse_pos.x >= sfSprite_getGlobalBounds(bar).left &&
	mouse_pos.x <= (sfSprite_getGlobalBounds(bar).left +
	sfSprite_getGlobalBounds(bar).width));
}
