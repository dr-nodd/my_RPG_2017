/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Potions
*/

#include "elapsed_time.h"
#include "struct.h"

void check_if_player_used_a_potion(window_t *window, game_t *game)
{
	if (window->event.type == sfEvtKeyPressed &&
	window->event.key.code == sfKeyA) {
		if (game->ui.potion_nbr > 0) {
			game->ui.potion_nbr -= 1;
			sfClock_restart(game->ui.potion_count.sfClock.clock);
		}
	}
	if (window->event.type == sfEvtKeyPressed &&
	window->event.key.code == sfKeyZ) {
		if (game->ui.potion_mana_nbr > 0) {
			game->ui.potion_mana_nbr -= 1;
			sfClock_restart
			(game->ui.potion_mana_count.sfClock.clock);
		}
	}
}

void check_potion_usage(game_t *game)
{
	if (get_img_seconds(&game->ui.potion_count) < 2.0)
		if (game->player_stat.health < game->player_stat.max_health)
			game->player_stat.health += 0.15;
	if (get_img_seconds(&game->ui.potion_mana_count) < 0.8)
		if (game->player_stat.mana < game->player_stat.max_mana)
			game->player_stat.mana += 1.0;
}
