/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Shoot with arrow
*/

#include "combat.h"
#include "class.h"
#include "elapsed_time.h"
#include "struct.h"

void shoot_bow(game_t *game)
{
	static int left = 0;

	if (game->player.in_attack) {
		if (get_sprite_seconds(&game->player) > 0.02) {
			left += 64;
			sfClock_restart(game->player.sfClock.clock);
		}
		sfSprite_setTextureRect(game->player.sprite,
			(sfIntRect){left,
			check_attack_direction(game->player.sprite, ARCHER),
			64, 64});
		sfSprite_setOrigin(game->player.sprite, (sfVector2f){64 / 2,
			64 / 2});
	}
	if (get_cooldown_seconds(&game->player) > 0.35 ||
	game->player.in_attack == 0) {
		game->player.in_attack = 0;
		left = 0;
	}
}
