/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** World map event
*/

#include "scene.h"
#include "struct.h"

void display_world_map_events(window_t *window)
{
	if (window->event.type == sfEvtKeyPressed) {
		if (window->event.key.code == sfKeyComma)
			window->scene = MAIN_GAME;
		if (window->event.key.code == sfKeyEscape)
			window->scene = PAUSE;
	}
}
