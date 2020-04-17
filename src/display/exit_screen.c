/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Exit screen
*/

#include <stdlib.h>
#include "mouse.h"
#include "struct.h"
#include "sound.h"
#include "display.h"

void check_yes_no_buttons(window_t *window, menu_t *menu)
{
	for (int i = 4; i <= 5; i++) {
		if (mouse_is_on_button(menu->buttons[i].sprite,
		window->mouse_pos))
			sfSprite_setTextureRect(menu->buttons[i].sprite,
			(sfIntRect){i * 724, 120, 721, 120});
		else
			sfSprite_setTextureRect(menu->buttons[i].sprite,
			(sfIntRect){i * 724, 0, 721, 120});
		sfRenderWindow_drawSprite(window->window,
		menu->buttons[i].sprite, NULL);
	}
}

void exit_screen(window_t *window, menu_t *menu)
{
	check_menu_sounds(window, menu, 4, 5);
	sfRenderWindow_clear(window->window, sfWhite);
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
	sfRenderWindow_drawSprite(window->window, menu->exit_prompt.sprite,
	NULL);
	check_yes_no_buttons(window, menu);
}
