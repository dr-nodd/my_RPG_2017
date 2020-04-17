/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Pause settings event
*/

#include "tools.h"
#include "scene.h"
#include "struct.h"
#include "mouse.h"

void pause_settings_events(window_t *window, menu_t *menu, game_t *game)
{
	if (window->event.type == sfEvtMouseButtonPressed) {
		if (mouse_is_on_button(game->pause_button[2].sprite,
			window->mouse_pos))
			window->scene = PAUSE;
		if (window->event.type == sfEvtMouseButtonPressed) {
			check_resolution(window, menu);
			check_fullscreen(window, menu);
			check_buttons(window, menu);
		}
	}
}
