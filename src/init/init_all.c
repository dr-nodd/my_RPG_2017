/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Initialisation
*/

#include "struct.h"
#include "init.h"

int init_all(window_t *window, menu_t *menu, game_t *game)
{
	if (init_window(window) == -1)
		return (-1);
	init_start_sprites(window, menu);
	if (init_menu_sprites(menu) == -1 || init_settings_sprites(menu) == -1)
		return (-1);
	init_exit_sprites(menu);
	init_game_musics(window, menu);
	if (init_game(window, game) == -1 || init_spells(game) == -1
	|| init_fx(game) == -1)
		return (-1);
	return (0);
}
