/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Gameover event
*/

#include "scene.h"
#include "mouse.h"
#include "struct.h"

void gameover_events(window_t *window, menu_t *menu, game_t *game)
{
	if (window->event.type == sfEvtMouseButtonPressed) {
		if (mouse_is_on_button(menu->buttons[3].sprite,
		window->mouse_pos)) {
			sfMusic_stop(game->gameover_song.music);
			window->scene = EXIT;
		}
		else if (mouse_is_on_button(menu->buttons[9].sprite,
		window->mouse_pos)) {
			sfMusic_stop(game->gameover_song.music);
			game->player.health = 100;
			window->scene = MAIN_MENU;
		}
	}
}
