/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Switch analyse event
*/

#include "struct.h"
#include "scene.h"
#include "event.h"

void third_analyse_event(window_t *window, menu_t *menu, game_t *game)
{
	switch (window->scene) {
	case (PAUSE_SETTINGS):
		pause_settings_events(window, menu, game);
		break;
	case (PAUSE_TO_MENU):
		pause_back_to_menu_events(window, game);
		break;
	case (PAUSE_EXIT):
		pause_quit_events(window, game);
		break;
	case (GAMEOVER):
		gameover_events(window, menu, game);
		break;
	}
}

void second_analyse_event(window_t *window, menu_t *menu, game_t *game)
{
	switch (window->scene) {
	case (SETTINGS):
		settings_events(window, menu);
		break;
	case (EXIT_PROMPT):
		exit_events(window, menu);
		break;
	case (MAIN_GAME):
		sfView_zoom(window->camera, 0.35);
		game_intro_events(window, game);
		break;
	case (PAUSE):
		pause_events(window, menu, game);
		break;
	default:
		third_analyse_event(window, menu, game);
		break;
	}
}

void analyse_event(window_t *window, menu_t *menu, game_t *game)
{
	if (window->event.type == sfEvtClosed)
		sfRenderWindow_close(window->window);
	switch (window->scene) {
	case (WORLDMAP):
		display_world_map_events(window);
		break;
	case (MAIN_MENU):
		menu_events(window, menu);
		break;
	case (NEW_GAME_PROMPT):
		new_game_event(window, menu);
		break;
	default:
		second_analyse_event(window, menu, game);
		break;
	}
}
