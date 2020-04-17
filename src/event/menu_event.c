/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Menu events
*/

#include "scene.h"
#include "mouse.h"
#include "struct.h"

void menu_events(window_t *window, menu_t *menu)
{
	int array[4] = {NEW_GAME_PROMPT, LOAD_GAME, SETTINGS, EXIT_PROMPT};

	for (int i = 0; i < 4; i++) {
		if (window->event.type == sfEvtMouseButtonPressed &&
		mouse_is_on_button(menu->buttons[i].sprite,
			window->mouse_pos)) {
			window->scene = array[i];
			break;
		}
	}
}
