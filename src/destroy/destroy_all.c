/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Destroy everything
*/

#include "destroy.h"
#include "struct.h"

void destroy_all(window_t *window, menu_t *menu, game_t *game)
{
	destroy_start_menu(menu);
	destroy_environment(game);
	destroy_mob(game);
	destroy_music(window, menu, game);
	destroy_particles(game);
	destroy_player(game);
	destroy_pause(game);
	destroy_ui(game);
}
