/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Back to menu from pause event
*/

#include "scene.h"
#include "mouse.h"
#include "struct.h"

void pause_back_to_menu_events(window_t *window, game_t *game)
{
	if (window->event.type == sfEvtMouseButtonPressed) {
		if (mouse_is_on_button(game->pause_button[5].sprite,
		window->mouse_pos))
			window->scene = MAIN_MENU;
		else if (mouse_is_on_button(game->pause_button[6].sprite,
		window->mouse_pos)) {
			sfSprite_setPosition(game->pause_rect.sprite,
			(sfVector2f){-20000, -20000});
			window->scene = PAUSE;
		}
	}
}
