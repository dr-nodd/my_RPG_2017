/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Sounds in menu
*/

#include "mouse.h"
#include "struct.h"

void check_settings_sound(window_t *window, menu_t *menu, int i, int *played)
{
	if (ypos_is_on_button(menu->buttons[i].sprite,
		window->mouse_pos)) {
			if (played[i] == 0)
				sfMusic_play(menu->hover.music);
			played[i]++;
		} else
			played[i] = 0;
}

void check_other_menu_sounds(window_t *window, menu_t *menu, int i,
		int *played)
{
	if (mouse_is_on_button(menu->buttons[i].sprite,
		window->mouse_pos)) {
			if (played[i] == 0)
				sfMusic_play(menu->hover.music);
			played[i]++;
		} else
			played[i] = 0;
}

void check_menu_sounds(window_t *window, menu_t *menu, int begin, int end)
{
	static int played[12];

	for (int i = begin; i <= end; i++)
		if (i == 6 || i == 7 || i == 8 || i == 11)
			check_settings_sound(window, menu, i, played);
		else
			check_other_menu_sounds(window, menu, i, played);
}
