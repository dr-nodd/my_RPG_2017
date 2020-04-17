/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Check collisions
*/

#include "interactions.h"
#include "struct.h"

int test_collisions(game_t *game, sfVector2f dir)
{
	element_t *ptr = game->list->first;
	sfFloatRect player_rect;

	player_rect = sfRectangleShape_getGlobalBounds(game->player.hitbox);
	player_rect.left += dir.x;
	player_rect.top += dir.y;
	while (ptr != NULL) {
		if (sfFloatRect_intersects(&ptr->rect, &player_rect, NULL)
		&& (ptr->type == ACTION || ptr->type == NPC
		|| ptr->type == QUEST))
			return (2);
		if (sfFloatRect_intersects(&ptr->rect, &player_rect, NULL))
			return (1);
		ptr = ptr->next;
	}
	game->player.can_interact = 0;
	return (0);
}
