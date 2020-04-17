/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Check the states of settings buttons
*/

#include <stdlib.h>
#include "display.h"
#include "sound.h"
#include "mouse.h"
#include "struct.h"

void handle_cursors(window_t *window, menu_t *menu)
{
	for (int i = 0; i < 2; i++) {
		if (sfMouse_isButtonPressed(sfMouseLeft) &&
		ypos_is_on_button(menu->sliders[i].sprite, window->mouse_pos)
		&& sliders_can_move(window->mouse_pos,
		menu->sliders_bar[i].sprite))
			move_sliders(menu->sliders[i].sprite,
				menu->sliders_bar[i].sprite,
				window->mouse_pos);
		change_volumes(window, menu, i);
		sfRenderWindow_drawSprite(window->window,
			menu->sliders_bar[i].sprite, NULL);
		sfRenderWindow_drawSprite(window->window,
			menu->sliders[i].sprite, NULL);
	}
	for (int i = 0; i < 2; i++) {
		sfRenderWindow_drawSprite(window->window,
			menu->sliders_bar[i].sprite, NULL);
		sfRenderWindow_drawSprite(window->window,
			menu->sliders[i].sprite, NULL);
	}
}

void change_apply_and_back_states(window_t *window, menu_t *menu, int i)
{
	if (mouse_is_on_button(menu->buttons[i].sprite, window->mouse_pos))
		sfSprite_setTextureRect(menu->buttons[i].sprite,
			(sfIntRect){i * 724, 120, 721, 120});
	else
		sfSprite_setTextureRect(menu->buttons[i].sprite,
			(sfIntRect){i * 724, 0, 721, 120});
}

void change_cursors_states(window_t *window, menu_t *menu, int i)
{
	if (ypos_is_on_button(menu->buttons[i].sprite, window->mouse_pos))
		sfSprite_setTextureRect(menu->buttons[i].sprite,
			(sfIntRect){i * 724, 120, 721, 120});
	else
		sfSprite_setTextureRect(menu->buttons[i].sprite,
			(sfIntRect){i * 724, 0, 721, 120});
}

void check_buttons_states(window_t *window, menu_t *menu)
{
	for (int i = 6; i < 12; i++) {
		if (i == 9 || i == 10)
			change_apply_and_back_states(window, menu, i);
		else
			change_cursors_states(window, menu, i);
	}
}
