/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Window initialisation
*/

#include <stdlib.h>
#include "scene.h"
#include "struct.h"

void center_window(window_t *window)
{
	sfVector2i window_pos;

	window_pos = sfRenderWindow_getPosition(window->window);
	window_pos.x = sfVideoMode_getDesktopMode().width / 2 -
	sfRenderWindow_getSize(window->window).x / 2;
	window_pos.y = sfVideoMode_getDesktopMode().height / 2 -
	sfRenderWindow_getSize(window->window).y / 2;
	sfRenderWindow_setPosition(window->window, window_pos);
}

int init_window(window_t *window)
{
	window->music_volume = 100;
	window->effect_volume = 100;
	window->mode = sfVideoMode_getDesktopMode();
	window->window = sfRenderWindow_create(window->mode,
			"Among Gods", sfFullscreen, NULL);
	if (!window->window)
		return (-1);
	sfRenderWindow_setFramerateLimit (window->window, 60);
	window->scene = SPLASH_SCREEN;
	window->camera = sfView_createFromRect((sfFloatRect){0, 0,
		(float)window->mode.width, (float)window->mode.height});
	center_window(window);
	return (0);
}
