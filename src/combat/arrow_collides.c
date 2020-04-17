/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Collisions with arrows
*/

#include <stdlib.h>
#include "class.h"
#include "mob.h"
#include "struct.h"

int check_arrow_collide_mob(game_t *game, sfFloatRect arrow_pos)
{
	sfFloatRect mob_pos[MOBS_COUNT];

	for (int i = 0; i < MOBS_COUNT; i++) {
		mob_pos[i] =
			sfRectangleShape_getGlobalBounds
			(game->mob[i].hitbox);
		if (sfFloatRect_intersects(&mob_pos[i],
			&arrow_pos, NULL)) {
			sfSprite_setPosition(game->arrow.sprite,
				(sfVector2f){-20000, -20000});
			return (1);
		}
	}
	return (0);
}

int check_arrow_collide_object(game_t *game, sfFloatRect arrow_pos)
{
	element_t *ptr = game->list->first;

	while (ptr != NULL) {
		if (sfFloatRect_intersects(&ptr->rect, &arrow_pos, NULL)) {
			sfSprite_setPosition(game->arrow.sprite,
				(sfVector2f){-20000, -20000});
			return (1);
		}
		ptr = ptr->next;
	}
	return (0);
}

int arrow_collides(game_t *game)
{
	sfFloatRect arrow_pos;

	if (game->player.equipment == ARCHER) {
		arrow_pos = sfSprite_getGlobalBounds(game->arrow.sprite);
		if (check_arrow_collide_mob(game, arrow_pos) == 1)
			return (2);
		else if (check_arrow_collide_object(game, arrow_pos) == 1)
			return (1);
	}
	return (0);
}
