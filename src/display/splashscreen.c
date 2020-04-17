/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Splashscreen
*/

#include <stdlib.h>
#include "elapsed_time.h"
#include "struct.h"

void handle_splashscreen(window_t *window, menu_t *menu)
{
	if (get_img_seconds(&menu->intro) < 4 &&
	sfSprite_getColor(menu->intro.sprite).a + 3 < 255) {
		menu->intro.color.a += 3;
		sfSprite_setColor(menu->intro.sprite, menu->intro.color);
	} else if (sfSprite_getColor(menu->intro.sprite).a - 3 > 0){
		menu->intro.color.a -= 3;
		sfSprite_setColor(menu->intro.sprite, menu->intro.color);
	}
	if (get_img_seconds(&menu->intro) > 7)
		window->scene = 1;
}

void check_skip_splashscreen(window_t *window, menu_t *menu,
	int skip_splashscreen)
{
	if (skip_splashscreen &&
		sfSprite_getColor(menu->intro.sprite).a - 7 <= 0)
		window->scene = 1;
}

void splash_screen(window_t *window, menu_t *menu)
{
	static int skip_splashscreen = 0;

	sfRenderWindow_clear(window->window, sfBlack);
	sfRenderWindow_drawSprite(window->window, menu->intro.sprite, NULL);
	if (skip_splashscreen) {
		sfSprite_setColor(menu->intro.sprite, (sfColor){255, 255, 255,
		(sfUint8)sfSprite_getColor(menu->intro.sprite).a - 7});
	} else
		handle_splashscreen(window, menu);
	if (sfKeyboard_isKeyPressed(sfKeyEscape) ||
		sfKeyboard_isKeyPressed(sfKeyReturn) ||
		sfKeyboard_isKeyPressed(sfKeySpace))
		skip_splashscreen = 1;
	check_skip_splashscreen(window, menu, skip_splashscreen);
}
