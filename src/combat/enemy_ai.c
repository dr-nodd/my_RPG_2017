/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Handle enemies
*/

#include "my.h"
#include "mob.h"
#include "elapsed_time.h"
#include "struct.h"
#include "display.h"

void check_enemies_distance(game_t *game, int *distance, int i, int *left)
{
	if (distance[i] <= 120) {
		mob_attacks_player(game, i, distance[i]);
		if (left[i] >
			sfSprite_getTextureRect(game->mob[i].sprite).width
			* 7)
			left[i] = 0;
		if (get_sprite_seconds(&game->mob[i]) > 0.1 &&
			game->mob[i].in_attack == 0) {
			sfClock_restart(game->mob[i].sfClock.clock);
			left[i] +=
			sfSprite_getTextureRect(game->mob[i].sprite)
			.width;
		}
	}
	set_proper_enemy_rect(game, distance[i], left, i);
}

void handle_enemies(window_t *window, game_t *game)
{
	int distance[MOBS_COUNT];
	static int left[MOBS_COUNT];

	for (int i = 0; i < MOBS_COUNT; i++) {
		if (game->mob[i].dead == 0) {
			distance[i] = calculate_distance(game->mob[i].sprite,
				game->player.sprite);
			check_enemies_distance(game, distance, i, left);
		} else
			animate_mob_death(game, i);
		sfRenderWindow_drawSprite(window->window,
			game->mob[i].sprite, NULL);
		display_loot_prompt(window, game, i);
	}
}
