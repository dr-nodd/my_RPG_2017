/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Deals with npc
*/

#include <stdlib.h>
#include "interactions.h"
#include "struct.h"

void handle_npcs(window_t *window, game_t *game)
{
	element_t *ptr;

	ptr = game->list->first;
	while (ptr != NULL) {
		if (ptr->type == QUEST) {
			sfRenderWindow_drawSprite(window->window,
				ptr->icon.sprite, NULL);
		}
		ptr = ptr->next;
	}
}
