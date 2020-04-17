/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Display start menu
*/

#include <stdlib.h>
#include "sound.h"
#include "display.h"
#include "struct.h"
#include "mouse.h"
#include "tools.h"

void check_to_menu(window_t *window, menu_t *menu)
{
	static int to_menu = 0;

	if ((sfMouse_isButtonPressed(sfMouseLeft) &&
	mouse_is_on_button(menu->press_start.sprite, window->mouse_pos) &&
	to_menu != 1) || sfKeyboard_isKeyPressed(sfKeyReturn)) {
		sfMusic_play(menu->start.music);
		to_menu = 1;
	}
	if (to_menu == 1 && sfSprite_getColor(menu->fadingblack.sprite).a +
	6 < 255) {
		menu->fadingblack.color.a += 6;
		sfSprite_setColor(menu->fadingblack.sprite,
		menu->fadingblack.color);
	} else if (to_menu == 1 &&
	sfSprite_getColor(menu->fadingblack.sprite).a != 255) {
		menu->fadingblack.color.a += 1;
		sfSprite_setColor(menu->fadingblack.sprite,
		menu->fadingblack.color);
	}
	window->scene = (sfSprite_getColor(menu->fadingblack.sprite).a ==
	255 ? 2 : 1);
}

void start_screen_appears_set_color(menu_t *menu)
{
	sfSprite_setColor(menu->background.sprite, menu->background.color);
	sfSprite_setColor(menu->menu_fg.sprite, menu->menu_fg.color);
	sfSprite_setColor(menu->press_start.sprite, menu->press_start.color);
	sfSprite_setColor(menu->menu_knight.sprite, menu->press_start.color);
	sfSprite_setColor(menu->menu_knight_shadow.sprite,
		menu->menu_knight_shadow.color);
}

void start_screen_appears(menu_t *menu)
{
	if (sfSprite_getColor(menu->background.sprite).a + 3 < 255) {
		menu->background.color.a += 3;
		menu->menu_fg.color.a += 3;
		menu->press_start.color.a += 3;
		menu->menu_knight.color.a += 3;
		menu->menu_knight_shadow.color.a += 3;
	} else {
		menu->background.color.a = 255;
		menu->menu_fg.color.a = 255;
		menu->press_start.color.a = 255;
		menu->menu_knight.color.a = 255;
		menu->menu_knight_shadow.color.a = 255;
	}
	start_screen_appears_set_color(menu);
}

void draw_start_screen(window_t *window, menu_t *menu)
{
	sfRenderWindow_drawSprite(window->window,
		menu->menu_knight_shadow.sprite, NULL);
	sfRenderWindow_drawSprite(window->window,
		menu->menu_knight.sprite, NULL);
	sfRenderWindow_drawSprite(window->window, menu->menu_fg.sprite, NULL);
	sfRenderWindow_drawSprite(window->window, menu->press_start.sprite,
		NULL);
	sfRenderWindow_drawSprite(window->window, menu->fadingblack.sprite,
		NULL);
}

void start_screen(window_t *window, menu_t *menu)
{
	start_screen_appears(menu);
	if (sfMusic_getStatus(menu->main_menu.music) != sfPlaying)
		sfMusic_play(menu->main_menu.music);
	if (mouse_is_on_button(menu->press_start.sprite, window->mouse_pos)
	&& sfSprite_getColor(menu->press_start.sprite).a > 30) {
		sfSprite_setScale(menu->press_start.sprite,
		(sfVector2f){0.8, 0.8});
	} else
		sinscale_img(&menu->press_start, 7, 10, 0.04);
	play_hover(window, menu, &menu->press_start);
	check_to_menu(window, menu);
	sfRenderWindow_clear(window->window, sfBlack);
	animate_background(menu);
	animate_menu_knight(menu);
	sfRenderWindow_drawSprite(window->window,
		menu->background.sprite, NULL);
	display_smoke(window, menu);
	draw_start_screen(window, menu);
}
