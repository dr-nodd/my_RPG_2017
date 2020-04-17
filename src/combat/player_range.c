/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Check range
*/

#include <stdlib.h>
#include "class.h"
#include "combat.h"
#include "mob.h"
#include "struct.h"
#include "animation.h"

int is_in_range(game_t *game, sprite_t mob)
{
	sfFloatRect player_range;
	sfFloatRect mob_hitbox;

	player_range = sfRectangleShape_getGlobalBounds(game->player.range);
		mob_hitbox =
		sfRectangleShape_getGlobalBounds(mob.hitbox);
	if (sfFloatRect_intersects(&player_range, &mob_hitbox, NULL))
		return (1);
	return (0);
}

void set_range_shape(game_t *game, sfVector2f *positions, sfVector2f *shapes)
{
	int top[4] = {SWORD_UP, SWORD_LEFT, SWORD_DOWN, SWORD_RIGHT};
	int dagger[4] = {DAGGER_UP, DAGGER_LEFT, DAGGER_DOWN, DAGGER_RIGHT};

	for (int i = 0; i < 4; i++) {
		if (sfSprite_getTextureRect(game->player.sprite).top ==
			top[i] || sfSprite_getTextureRect
			(game->player.sprite).top == dagger[i]) {
			sfRectangleShape_setSize(game->player.range,
			shapes[i]);
			sfRectangleShape_setOrigin(game->player.range,
			(sfVector2f)
			{sfRectangleShape_getSize(game->player.range).x / 2,
			sfRectangleShape_getSize(game->player.range).y / 2});
			sfRectangleShape_setPosition(game->player.range,
			positions[i]);
		}
	}
}

void set_player_range(game_t *game)
{
	if (game->player.equipment == DAGGER) {
		set_dagger_range(game);
		return;
	}
	if (game->player.equipment == RECRUIT)
		set_recruit_hitbox(game);
	else if (game->player.equipment == WARRIOR)
		set_warrior_hitbox(game);
	else
		set_god_hitbox(game);
}

void set_hitboxes(sprite_t *entity)
{
	sfRectangleShape_setPosition(entity->hitbox,
		sfSprite_getPosition(entity->sprite));
	sfRectangleShape_move(entity->hitbox, (sfVector2f){0, 6});
}
