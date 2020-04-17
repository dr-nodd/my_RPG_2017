/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Spell display for mage
*/

#include "elapsed_time.h"
#include "init.h"
#include "display.h"
#include "tools.h"
#include "class.h"
#include "combat.h"
#include "struct.h"

void shake_spell(game_t *game)
{
	if (sfSprite_getRotation(game->fireball.sprite) == 90)
		sfSprite_move(game->fireball.sprite,
			(sfVector2f){(float)frand_a_b(2, -2), 0});
	else
		sfSprite_move(game->fireball.sprite,
			(sfVector2f){0, (float)frand_a_b(2, -2)});
}

void reset_fireball(game_t *game)
{
	if ((get_sprite_seconds(&game->fireball) > FIREBALL_LIFETIME &&
		game->player.in_attack == 1 &&
		game->player.equipment == MAGE)) {
		set_fireball_position(game);
		sfClock_restart(game->fireball.sfClock.clock);
		sfClock_restart(game->fireball.cooldown.clock);
	}
}

void display_fireball(window_t *window, game_t *game)
{
	sfVector2f arr_dir;

	reset_fireball(game);
	if (get_sprite_seconds(&game->fireball) < FIREBALL_LIFETIME &&
	fireball_collides(game) == 0) {
		arr_dir = check_fireball_direction(game);
		sfSprite_move(game->fireball.sprite, arr_dir);
		animate_fireball(game);
		shake_spell(game);
		set_fireball_particles(game);
		sfRenderWindow_drawSprite(window->window,
		game->fireball.sprite, NULL);
	}
	sfRenderWindow_drawVertexArray(window->window,
		game->fireball_particles, NULL);
	sfRenderWindow_drawSprite(window->window,
	game->explosion.sprite, NULL);
}
