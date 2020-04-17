/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Display game switch
*/

#include "save.h"
#include "display.h"
#include "struct.h"
#include "scene.h"
#include "mouse.h"

void fourth_display_game(window_t *window, menu_t *menu, game_t *game)
{
	switch (window->scene) {
	case (PAUSE_TO_MENU):
		pause_back_to_menu(window, game);
		break;
	case (PAUSE_EXIT):
		pause_quit(window, game);
		break;
	case (SAVE):
		save_game(game);
		window->scene = MAIN_GAME;
		break;
	case (GAMEOVER):
		gameover_screen(window, menu, game);
		break;
	}
}

void third_display_game(window_t *window, menu_t *menu, game_t *game)
{
	switch (window->scene) {
	case (SETTINGS):
		settings_screen(window, menu);
		break;
	case (EXIT_PROMPT):
		exit_screen(window, menu);
		break;
	case (MAIN_GAME):
		launch_new_game(window, game);
		break;
	case (PAUSE):
		launch_pause(window, game);
		break;
	case (PAUSE_SETTINGS):
		pause_settings(window, menu, game);
		break;
	default:
		fourth_display_game(window, menu, game);
	}
}

void second_display_game(window_t *window, menu_t *menu, game_t *game)
{
	switch (window->scene) {
	case (MAIN_MENU):
		menu_screen(window, menu);
		menu->ld_game = 0;
		break;
	case (NEW_GAME_PROMPT):
		new_game_prompt(window, menu);
		break;
	case (NEW_GAME):
		launch_new_game(window, game);
		break;
	case (LOAD_GAME):
		menu->ld_game++;
		load_game(game);
		window->scene = NEW_GAME_PROMPT;
		break;
	default:
		third_display_game(window, menu, game);
		break;
	}
}

void display_game(window_t *window, menu_t *menu, game_t *game)
{
	window->mouse_pos = get_mouse_position(window, window->camera);
	check_screenshot(window, menu);
	switch (window->scene) {
	case (WORLDMAP):
		display_world_map(window, game);
		break;
	case (EXIT):
		sfRenderWindow_close(window->window);
		break;
	case (SPLASH_SCREEN):
		splash_screen(window, menu);
		break;
	case (START_SCREEN):
		start_screen(window, menu);
		break;
	default:
		second_display_game(window, menu, game);
		break;
	}
}
