/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Display player
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

void draw_perspective(window_t *window, game_t *game, element_t *tempelem,
	sfFloatRect player_rect)
{
	sfRenderWindow_drawSprite(window->window, game->grass.sprite, NULL);
	if (tempelem->rect.top <= player_rect.top)
		sfRenderWindow_drawSprite(window->window, game->col.sprite,
		NULL);
	sfRenderWindow_drawSprite(window->window, game->player_shadow.sprite,
	NULL);
	if (game->player_moves) {
		sfRenderWindow_drawVertexArray(window->window,
		game->walking_particles, NULL);
	}
	sfRenderWindow_drawSprite(window->window, game->player.sprite, NULL);
	if (tempelem->rect.top > player_rect.top)
		sfRenderWindow_drawSprite(window->window, game->col.sprite,
		NULL);
}

void check_perspective(window_t *window, game_t *game)
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
	draw_perspective(window, game, tempelem, player_rect);
}

void display_player(window_t *window, game_t *game)
{
	sfVector2f pos;

	pos = sfSprite_getPosition(game->player.sprite);
	sfSprite_setPosition(game->player_shadow.sprite,
	(sfVector2f){pos.x, pos.y + 5});
	sfRectangleShape_setPosition(game->player.hitbox,
	(sfVector2f){pos.x, pos.y + 25});
	check_perspective(window, game);
	sfRenderWindow_drawSprite(window->window, game->dash_smoke.sprite,
	NULL);
}
