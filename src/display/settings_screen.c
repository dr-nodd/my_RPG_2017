/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Settings screen
*/

#include <stdlib.h>
#include "display.h"
#include "struct.h"
#include "sound.h"

void settings_screen(window_t *window, menu_t *menu)
{
	check_buttons_states(window, menu);
	check_menu_sounds(window, menu, 6, 11);
	sfRenderWindow_clear(window->window, sfBlack);
	animate_background(menu);
	sfRenderWindow_drawSprite(window->window,
		menu->background.sprite, NULL);
	display_smoke(window, menu);
	handle_cursors(window, menu);
	for (int i = 6; i < 12; i++)
		sfRenderWindow_drawSprite(window->window,
			menu->buttons[i].sprite, NULL);
	sfRenderWindow_drawSprite(window->window,
		menu->resolutions.sprite, NULL);
	sfRenderWindow_drawSprite(window->window, menu->check.sprite, NULL);
	sfView_setSize(window->camera, (sfVector2f){1920, 1080});
	sfView_setCenter(window->camera,
		sfSprite_getPosition(menu->background.sprite));
	sfRenderWindow_setView(window->window, window->camera);
}
