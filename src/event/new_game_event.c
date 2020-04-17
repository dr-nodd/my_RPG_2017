/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** New Game event
*/

#include "scene.h"
#include "struct.h"
#include "mouse.h"

void new_game_event(window_t *window, menu_t *menu)
{
	for (int i = 4; i <= 5; i++) {
		if (window->event.type == sfEvtMouseButtonPressed &&
		mouse_is_on_button(menu->buttons[i].sprite,
			window->mouse_pos)) {
			window->scene = (i == 4 ? MAIN_GAME : MAIN_MENU);
			if (window->scene == MAIN_GAME) {
				sfMusic_stop(menu->main_menu.music);
			}
			break;
		}
	}
}
