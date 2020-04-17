/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Pause events
*/

#include "display.h"
#include "struct.h"
#include "mouse.h"
#include "scene.h"

void check_save(window_t *window, game_t *game)
{
	if (mouse_is_on_button(game->pause_button[1].sprite,
	window->mouse_pos))
		sfClock_restart(game->ui.save_prompt.sfClock.clock);
}

int button_pause_pressed(game_t *game, window_t *window)
{
	int n = 0;

	while (mouse_is_on_button(game->pause_button[n].sprite,
		window->mouse_pos) == 0 && n < 5)
		n++;
	return (n);
}

void pause_events_handle(window_t *window, menu_t *menu, game_t *game)
{
	switch (button_pause_pressed(game, window)) {
	case 0:
		window->scene = MAIN_GAME;
		check_save(window, game);
		break;
	case 1:
		window->scene = SAVE;
		break;
	case 2:
		reset_volume_cursors(window, menu, game);
		window->scene = PAUSE_SETTINGS;
		break;
	case 3:
		window->scene = PAUSE_TO_MENU;
		break;
	case 4:
		window->scene = PAUSE_EXIT;
		break;
	}
}

void pause_events(window_t *window, menu_t *menu, game_t *game)
{
	if (window->event.type == sfEvtKeyPressed && window->event.key.code
	== sfKeyEscape) {
		sfSprite_setPosition(game->pause_rect.sprite,
		(sfVector2f){-20000, -20000});
		sfView_setSize(window->camera, (sfVector2f){672, 378});
		sfRenderWindow_setView(window->window, window->camera);
		window->scene = MAIN_GAME;
	}
	if (window->event.type == sfEvtMouseButtonPressed)
		pause_events_handle(window, menu, game);
}
