/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Combat sprite
*/

#include "combat.h"
#include "class.h"
#include "struct.h"
#include "elapsed_time.h"

int swing_cooldown(game_t *game, int left)
{
	if (get_cooldown_seconds(&game->player) > 0.25 ||
	game->player.in_attack == 0) {
		game->player.in_attack = 0;
		left = 0;
	}
	set_player_range(game);
	return (left);
}

void swing_sword(game_t *game)
{
	static int left = 0;

	if (game->player.in_attack) {
		if (get_sprite_seconds(&game->player) > 0.05) {
			left += 192;
			sfClock_restart(game->player.sfClock.clock);
		}
		sfSprite_setTextureRect(game->player.sprite, (sfIntRect){left,
		check_attack_direction(game->player.sprite, WARRIOR), 192,
		192});
		sfSprite_setOrigin(game->player.sprite, (sfVector2f){192 / 2,
		192 / 2});
	} else
		sfSprite_setOrigin(game->player.sprite, (sfVector2f){64 / 2,
		64 / 2});
	left = swing_cooldown(game, left);
}

void swing_dagger(game_t *game)
{
	static int left = 0;

	if (game->player.in_attack) {
		if (get_sprite_seconds(&game->player) > 0.05) {
			left += 64;
			sfClock_restart(game->player.sfClock.clock);
		}
		sfSprite_setTextureRect(game->player.sprite, (sfIntRect){left,
		check_attack_direction(game->player.sprite, DAGGER), 64, 64});
		sfSprite_setOrigin(game->player.sprite,
		(sfVector2f){64 / 2, 64 / 2});
	}
	left = swing_cooldown(game, left);
}
