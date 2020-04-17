/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Music related functions
*/

#include "mouse.h"
#include "init.h"
#include "struct.h"

void play_hover(window_t *window, menu_t *menu, img_t *button)
{
	static int play_hover = 1;

	if (mouse_is_on_button(button->sprite, window->mouse_pos)) {
		if (play_hover == 0)
			sfMusic_play(menu->hover.music);
		play_hover++;
	} else {
		play_hover = 0;
	}
}

int init_game_musics(window_t *window, menu_t *menu)
{
	init_music(&window->snap, "assets/musics/snap.ogg", 70, sfFalse);
	init_music(&menu->main_menu, "assets/musics/main_menu_theme2.ogg",
	100, sfTrue);
	init_music(&menu->start, "assets/musics/start.ogg", 100, sfFalse);
	init_music(&menu->hover, "assets/musics/hover.ogg", 100, sfFalse);
	return (0);
}
