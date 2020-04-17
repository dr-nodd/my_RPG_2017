/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Collisions with fireball
*/

#include <stdlib.h>
#include "class.h"
#include "mob.h"
#include "struct.h"

int check_fireball_collide_mob(game_t *game, sfFloatRect ball_pos)
{
	sfFloatRect mob_pos[MOBS_COUNT];

	for (int i = 0; i < MOBS_COUNT; i++) {
		mob_pos[i] =
			sfRectangleShape_getGlobalBounds
			(game->mob[i].hitbox);
		if (sfFloatRect_intersects(&mob_pos[i],
			&ball_pos, NULL)) {
			return (1);
		}
	}
	return (0);
}

int check_fireball_collide_object(game_t *game, sfFloatRect ball_pos)
{
	element_t *ptr = game->list->first;

	while (ptr != NULL) {
		if (sfFloatRect_intersects(&ptr->rect, &ball_pos, NULL)) {
			return (1);
		}
		ptr = ptr->next;
	}
	return (0);
}

int fireball_collides(game_t *game)
{
	sfFloatRect ball_pos;

	if (game->player.equipment == MAGE) {
		ball_pos = sfSprite_getGlobalBounds(game->fireball.sprite);
		if (check_fireball_collide_mob(game, ball_pos) == 1) {
			return (2);
		}
		else if (check_fireball_collide_object(game, ball_pos) == 1) {
			return (1);
		}
	}
	return (0);
}
