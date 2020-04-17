/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Mob
*/

#include <stdlib.h>
#include "combat.h"
#include "my.h"
#include "animation.h"
#include "mob.h"
#include "elapsed_time.h"
#include "struct.h"

void loot_exp(game_t *game)
{
	game->player_stat.xp += (5 + rand() % 16);
	if (game->player_stat.xp >= game->player_stat.max_xp) {
		game->player_stat.lvl += 1;
		if (game->player_stat.lvl == 5)
			game->armor_unlocked[1] = 1;
		else if (game->player_stat.lvl == 15)
			game->armor_unlocked[2] = 1;
		game->player_stat.xp -= game->player_stat.max_xp;
		game->player_stat.max_xp += (10 + rand() % 11);
		game->player_stat.max_health +=
		(9 + game->player_stat.lvl + ((rand() % 3) - (rand() % 4)));
		game->player_stat.health = game->player_stat.max_health;
		game->player_stat.max_mana += (
		9 + game->player_stat.lvl + ((rand() % 5) - (rand() % 6)));
		game->player_stat.mana = game->player_stat.max_mana;
	}
}

void animate_mob_death(game_t *game, int i)
{
	static int left[MOBS_COUNT];
	static int top[MOBS_COUNT];

	if (left[i] > 64 * 5 &&
		sfSprite_getTextureRect(game->mob[i].sprite).top == DEATH) {
		game->mob[i].dead = 0;
		game->mob[i].health = 100;
		reset_mob_position(game, i);
		sfSprite_setTextureRect(game->mob[i].sprite,
			(sfIntRect){0, WALK_DOWN, 64, 64});
	}
	if (game->mob[i].dead == 1) {
		if (get_sprite_seconds(&game->mob[i]) > 0.15) {
			left[i] += 64;
			sfClock_restart(game->mob[i].sfClock.clock);
		}
		sfSprite_setTextureRect(game->mob[i].sprite,
			(sfIntRect){left[i], top[i] = DEATH, 64, 64});
	} else
		left[i] = 0;
}

void check_mob_death(game_t *game, int i)
{
	if (game->mob[i].health <= 0) {
		game->player_stat.money += 10;
		loot_exp(game);
		game->mob[i].dead = 1;
		if (game->player_stat.lvl == 10)
			game->armor_unlocked[1] = 1;
		else if (game->player_stat.lvl == 20)
			game->armor_unlocked[5] = 1;
	}
}

void move_hit_mob(game_t *game, int i)
{
	float angle;
	sfVector2f dir;
	float speed = 10;

	angle = find_angle(game->mob[i].sprite, game->player.sprite);
	if (angle > (-2.3) && angle < (-0.7))
		dir = (sfVector2f){0, speed};
	if (angle > (-0.7) && angle < (0.7))
		dir = (sfVector2f){-speed, 0};
	if (angle > (0.7) && angle < (2.3))
		dir = (sfVector2f){0, -speed};
	if ((angle > 2.3 && angle < 3.5) || (angle >= -3.5 && angle <= -2.3))
		dir = (sfVector2f){speed, 0};
	sfSprite_move(game->mob[i].sprite, dir);
}

void animate_hit_mob(game_t *game, int i, int *attacked)
{
	if (attacked[i] < 10) {
		if (attacked[i] < 4)
			move_hit_mob(game, i);
		sfSprite_setColor(game->mob[i].sprite, sfRed);
	} else
		attacked[i] = 1000;
}
