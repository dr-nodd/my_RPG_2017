/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Spell
*/

#include "animation.h"
#include "combat.h"
#include "class.h"
#include "elapsed_time.h"
#include "struct.h"

void launch_spell(game_t *game)
{
	static int left = 0;

	if (game->player.in_attack) {
		if (get_sprite_seconds(&game->player) > 0.05) {
			left += 64;
			sfClock_restart(game->player.sfClock.clock);
		}
		sfSprite_setTextureRect(game->player.sprite,
			(sfIntRect){left,
			check_attack_direction(game->player.sprite, MAGE),
			64, 64});
		sfSprite_setOrigin(game->player.sprite, (sfVector2f){64 / 2,
			64 / 2});
	}
	if (get_cooldown_seconds(&game->player) > 0.30 ||
	game->player.in_attack == 0) {
		game->player.in_attack = 0;
		left = 0;
	}
}

void animate_fireball(game_t *game)
{
	static int left = 0;

	if (get_cooldown_seconds(&game->fireball) > 0.1) {
		sfClock_restart(game->fireball.cooldown.clock);
		left += 154;
	}
	if (left >= 154 * 6)
		left = 0;
	sfSprite_setTextureRect(game->fireball.sprite,
		(sfIntRect){left, 0, 154, 44});
}

void set_fireball_position(game_t *game)
{
	int anim[4] = {SPELL_LEFT, SPELL_UP, SPELL_RIGHT, SPELL_DOWN};
	int angle[4] = {0, 90, 0, 90};
	sfVector2f shape[4] = {{0.5, 0.5}, {0.5, 0.5}, {-0.5, 0.5}, {-0.5,
		0.5}};

	sfSprite_setPosition(game->fireball.sprite,
	sfSprite_getPosition(game->player.sprite));
	for (int i = 0; i < 4; i++) {
		if (sfSprite_getTextureRect(game->player.sprite).top ==
			anim[i]) {
			sfSprite_setRotation(game->fireball.sprite, angle[i]);
			sfSprite_setScale(game->fireball.sprite, shape[i]);
			return;
		}
	}
}

sfVector2f check_fireball_direction(game_t *game)
{
	float speed = 2;
	int angle[4] = {0, 90, 0, 90};
	sfVector2f shape[4] = {{0.5, 0.5}, {0.5, 0.5}, {-0.5, 0.5},
		{-0.5, 0.5}};
	sfVector2f dir[4] =
		{{-speed, 0}, {0, -speed},
		{speed, 0}, {0, speed}};

	for (int i = 0; i < 4; i++)
		if (sfSprite_getRotation(game->fireball.sprite) == angle[i] &&
		sfSprite_getScale(game->fireball.sprite).x == shape[i].x
		&& sfSprite_getScale(game->fireball.sprite).y ==
		shape[i].y)
			return (dir[i]);
	return ((sfVector2f){0, 0});
}
