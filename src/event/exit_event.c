/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Exit events
*/

#include "scene.h"
#include "mouse.h"
#include "struct.h"

void exit_events(window_t *window, menu_t *menu)
{
	for (int i = 4; i <= 5; i++) {
		if (window->event.type == sfEvtMouseButtonPressed &&
		mouse_is_on_button(menu->buttons[i].sprite,
		window->mouse_pos))
			window->scene = (i == 4 ? EXIT : MAIN_MENU);
	}
}
