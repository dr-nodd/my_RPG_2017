/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Init functions in game
*/

#include "init.h"
#include "struct.h"

int init_game(window_t *window, game_t *game)
{
	init_world_map(game);
	if (init_walk_particles(game) || init_fire_particles(game))
		return (-1);
	init_player(game);
	if (init_pause_sprites(window, game) == -1
	|| init_player_sprites(game) == -1)
		return (-1);
	init_collisions(game);
	init_environment(game);
	if (init_mobs(game) == -1 || init_shop_menu(game) == -1)
		return (-1);
	init_dialogue_background(game);
	if (init_ui(game) == -1)
		return (-1);
	return (0);
}
