/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Settings events
*/

#include <stdlib.h>
#include "tools.h"
#include "scene.h"
#include "mouse.h"
#include "struct.h"

void check_resolution(window_t *window, menu_t *menu)
{
	if (ypos_is_on_button(menu->resolutions.sprite, window->mouse_pos)) {
		menu->resolutions.rect.top = (menu->resolutions.rect.top >=
		475 - (475 / 5) ? 0 : menu->resolutions.rect.top + 475 / 5);
		sfSprite_setTextureRect(menu->resolutions.sprite,
		menu->resolutions.rect);
	}
}

void check_fullscreen(window_t *window, menu_t *menu)
{
	if (mouse_is_on_button(menu->check.sprite, window->mouse_pos)) {
		menu->check.rect.left =
		(menu->check.rect.left == 0 ? 310 : 0);
		sfSprite_setTextureRect(menu->check.sprite, menu->check.rect);
	}
	if (sfSprite_getTextureRect(menu->check.sprite).left == 0) {
		menu->resolutions.rect.top = 380;
		sfSprite_setTextureRect(menu->resolutions.sprite,
		menu->resolutions.rect);
	}
}

void check_buttons(window_t *window, menu_t *menu)
{
	sfVector2i resolutions[5] = {{1024, 576}, {1280, 720}, {1366, 768},
		{1600, 900}, {1920, 1080}};
	sfUint32 *fullscreen[2] = {(sfUint32*)sfClose,
		(sfUint32*)sfFullscreen};

	if (mouse_is_on_button(menu->buttons[10].sprite, window->mouse_pos)) {
		window->mode.width = resolutions[sfSprite_getTextureRect
		(menu->resolutions.sprite).top / (475 / 5)].x;
		window->mode.height = resolutions[sfSprite_getTextureRect
		(menu->resolutions.sprite).top / (475 / 5)].y;
		sfRenderWindow_destroy(window->window);
		window->window = sfRenderWindow_create(window->mode,
			"Among Gods", (size_t)(menu->check.rect.left == 0 ?
			fullscreen[1] : fullscreen[0]), NULL);
		sfRenderWindow_setFramerateLimit(window->window, 60);
		if (menu->check.rect.left == 310)
			center_window(window);
	}
	if (mouse_is_on_button(menu->buttons[9].sprite, window->mouse_pos))
		window->scene = MAIN_MENU;
}

void settings_events(window_t *window, menu_t *menu)
{
	if (window->event.type == sfEvtClosed)
		sfRenderWindow_close(window->window);
	if (window->event.type == sfEvtMouseButtonPressed) {
		check_resolution(window, menu);
		check_fullscreen(window, menu);
		check_buttons(window, menu);
	}
}
