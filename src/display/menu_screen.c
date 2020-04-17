/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Menu display
*/

#include <stdlib.h>
#include "sound.h"
#include "display.h"
#include "elapsed_time.h"
#include "mouse.h"
#include "struct.h"

void set_pos_set_color_menu(menu_t *menu)
{
	sfSprite_setPosition(menu->buttons[3].sprite, (sfVector2f){1550,
	950});
	sfSprite_setPosition(menu->buttons[9].sprite, (sfVector2f){1600,
	950});
	sfSprite_setScale(menu->buttons[3].sprite, (sfVector2f){0.8, 0.8});
	sfSprite_setScale(menu->buttons[9].sprite, (sfVector2f){0.8, 0.8});
	sfSprite_setPosition(menu->menu_fg.sprite, (sfVector2f){700, 420});
	sfSprite_setPosition(menu->menu_knight.sprite, (sfVector2f){700,
	420});
	sfSprite_setScale(menu->menu_fg.sprite, (sfVector2f){0.75, 0.75});
	sfSprite_setColor(menu->background.sprite, (sfColor){255, 255, 255,
	255});
	sfSprite_setColor(menu->menu_fg.sprite, (sfColor){255, 255, 255,
	255});
	sfSprite_setColor(menu->menu_knight.sprite, (sfColor){255, 255, 255,
	255});
}

void set_menu_sprites(window_t *window, menu_t *menu)
{
	set_pos_set_color_menu(menu);
	if (sfSprite_getColor(menu->fadingblack.sprite).a - 3 >= 3) {
		menu->fadingblack.color.a -= 3;
		sfSprite_setColor(menu->fadingblack.sprite,
		menu->fadingblack.color);
	}
	for (int i = 0; i < 4; i++) {
		if (mouse_is_on_button(menu->buttons[i].sprite,
		window->mouse_pos))
			sfSprite_setTextureRect(menu->buttons[i].sprite,
			(sfIntRect){i * 724, 120, 721, 120});
		else
			sfSprite_setTextureRect(menu->buttons[i].sprite,
			(sfIntRect){i * 724, 0, 721, 120});
	}
	if (sfMusic_getStatus(menu->main_menu.music) != sfPlaying) {
		sfMusic_play(menu->main_menu.music);
	}
}

void animate_background(menu_t *menu)
{
	static int left = 100;
	static int top = 0;
	sfIntRect rect;

	rect = sfSprite_getTextureRect(menu->background.sprite);
	if (left >= 4610) {
		left = 100;
		top += rect.height;
	}
	if (top >= rect.height * 4)
		top = 0;
	if (get_img_seconds(&menu->background) > 0.15) {
		sfClock_restart(menu->background.sfClock.clock);
		sfSprite_setTextureRect(menu->background.sprite,
			(sfIntRect){left, top, rect.width, rect.height});
		left += rect.width;
	}
}

void menu_view(window_t *window, menu_t *menu)
{
	sfView_setSize(window->camera, (sfVector2f){1920, 1080});
	sfView_setCenter(window->camera,
	sfSprite_getPosition(menu->background.sprite));
	sfRenderWindow_setView(window->window, window->camera);
}

void menu_screen(window_t *window, menu_t *menu)
{
	set_menu_sprites(window, menu);
	check_menu_sounds(window, menu, 0, 4);
	sfRenderWindow_clear(window->window, sfBlack);
	animate_background(menu);
	animate_menu_knight(menu);
	sfRenderWindow_drawSprite(window->window, menu->background.sprite,
	NULL);
	display_smoke(window, menu);
	sfRenderWindow_drawSprite(window->window,
	menu->menu_knight_shadow.sprite, NULL);
	sfRenderWindow_drawSprite(window->window, menu->menu_knight.sprite,
	NULL);
	sfRenderWindow_drawSprite(window->window, menu->menu_fg.sprite, NULL);
	for (int i = 0; i < 4; i++)
		sfRenderWindow_drawSprite(window->window,
		menu->buttons[i].sprite, NULL);
	sfRenderWindow_drawSprite(window->window, menu->fadingblack.sprite,
	NULL);
	menu_view(window, menu);
}
