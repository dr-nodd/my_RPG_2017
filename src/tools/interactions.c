/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Check the type of collision
*/

#include "elapsed_time.h"
#include "struct.h"
#include "interactions.h"
#include "my.h"

void check_collisions_type(game_t *game)
{
	element_t *ptr = game->list->first;
	sfFloatRect player_rect;
	float temp = 10000000;
	element_t *tempelem;

	player_rect = sfRectangleShape_getGlobalBounds(game->player.hitbox);
	while (ptr != NULL) {
		if (calculate_rect_distance(&ptr->rect, &player_rect) <
			temp) {
			temp = calculate_rect_distance(&ptr->rect,
				&player_rect);
			tempelem = ptr;
		}
		ptr = ptr->next;
	}
	game->player.can_interact = (tempelem->type == ACTION
				|| tempelem->type == NPC
				|| tempelem->type == QUEST ? 1 : 0);
	game->in_dialogue = (tempelem->type == NPC ? 1 : 0);
	game->in_quest = (tempelem->type == QUEST ? 1 : 0);
}

void animate_key(img_t key)
{
	if (get_img_seconds(&key) > 0.5) {
		sfClock_restart(key.sfClock.clock);
		sfSprite_setTextureRect(key.sprite,
			(sfIntRect){0, (sfSprite_getTextureRect
			(key.sprite).top == 0 ? 29 : 0),
			28, 29});
	}
}

void check_interactions(window_t *window, game_t *game)
{
	sfVector2f pos;
	sfFloatRect key_rect;
	sfFloatRect player_rect;

	key_rect = sfSprite_getGlobalBounds(game->ui.key_e.sprite);
	pos = sfSprite_getPosition(game->player.sprite);
	player_rect = sfSprite_getGlobalBounds(game->player.sprite);
	if (game->player.can_interact == 1) {
		animate_key(game->ui.key_e);
		sfSprite_setPosition(game->ui.key_e.sprite, (sfVector2f)
			{(float)(pos.x + key_rect.width / 1.7),
			pos.y + player_rect.height / 1.7});
		if (game->in_shop == 0)
			sfRenderWindow_drawSprite(window->window,
				game->ui.key_e.sprite, NULL);
	}
}
