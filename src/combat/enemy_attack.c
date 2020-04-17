/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Enemies attack
*/

#include <math.h>
#include "my.h"
#include "animation.h"
#include "elapsed_time.h"
#include "mob.h"
#include "struct.h"
#include "sound.h"
#include "interactions.h"

void enemy_attacks(game_t *game, int i, float angle)
{
	int top[MOBS_COUNT];
	static int left[MOBS_COUNT];

	top[i] = find_enemy_attack_direction(angle);
	if (!enemy_left_is_valid(game->mob[i].sprite)) {
		left[i] = 0;
		return;
	}
	left[i] += 192;
	if (left[i] > 1536)
		left[i] = 0;
	sfClock_restart(game->mob[i].cooldown.clock);
	sfSprite_setOrigin(game->mob[i].sprite,
		(sfVector2f){192 / 2, 192 / 2});
	sfSprite_setTextureRect(game->mob[i].sprite,
		(sfIntRect){left[i], top[i], 192, 192});
}

void lower_player_health(game_t *game, int attacking)
{
	if (attacking == 0) {
		game->player_stat.health = (game->player.health > 0
		? game->player_stat.health - 10 : 0);
		play_mob_hit_sound(game);
	}
}

void deal_damage_to_player(game_t *game)
{
	static int attacking[MOBS_COUNT];
	sfIntRect rect[MOBS_COUNT];

	for (int i = 0; i < MOBS_COUNT; i++) {
		rect[i] = sfSprite_getTextureRect(game->mob[i].sprite);
		if (rect[i].top >= SWORD_UP && rect[i].left >= 192 * 4) {
			lower_player_health(game, attacking[i]);
			attacking[i]++;
		} else
			attacking[i] = 0;
	}
}

int mob_collides(game_t *game, sprite_t mob, float angle)
{
	element_t *ptr = game->list->first;
	sfFloatRect mob_rect;

	mob_rect = sfRectangleShape_getGlobalBounds(mob.hitbox);
	mob_rect.left += cosf(angle) * 0.4;
	mob_rect.top += sinf(angle) * 0.4;
	while (ptr != NULL) {
		if (sfFloatRect_intersects(&ptr->rect, &mob_rect, NULL))
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void mob_attacks_player(game_t *game, int i, int distance)
{
	float angle;
	static float enemy_speed = 0.4;

	angle = find_angle(game->mob[i].sprite, game->player.sprite);
	if (distance < 55 && get_cooldown_seconds(&game->mob[i]) > 0.5) {
		enemy_attacks(game, i, angle);
		return;
	} else if (distance >= 55) {
		game->mob[i].in_attack = 0;
		if (mob_collides(game, game->mob[i], angle) == 0)
			sfSprite_move(game->mob[i].sprite,
			(sfVector2f){cosf(angle) * enemy_speed,
			sinf(angle) * enemy_speed});
		animate_enemy(game->mob[i], angle);
	}
	deal_damage_to_player(game);
}
