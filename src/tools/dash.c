/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Dash for player
*/

#include <stdlib.h>
#include "animation.h"
#include "elapsed_time.h"
#include "struct.h"

sfVector2f check_dash_dir(sfSprite *character)
{
	float speed = 12;
	int top[4] = {WALK_UP, WALK_LEFT, WALK_DOWN, WALK_RIGHT};
	sfVector2f dir[4] =
		{{0, -speed}, {-speed, 0},
		{0, speed}, {speed, 0}};

	for (int i = 0; i < 4; i++)
		if (sfSprite_getTextureRect(character).top == top[i])
			return (dir[i]);
	return ((sfVector2f){0, 0});
}

void set_dash_smoke_properties(game_t *game, int left)
{
	int anim[4] = {WALK_UP, WALK_LEFT, WALK_DOWN, WALK_RIGHT};
	sfVector2f scale[4] = {{0.7, 0.7}, {-0.7, 0.7},
		{0.7, 0.7}, {0.7, 0.7}};

	sfSprite_setTextureRect(game->dash_smoke.sprite,
		(sfIntRect){left, 0, 79, 80});
	for (int i = 0; i < 4; i++)
		if (sfSprite_getTextureRect(game->player.sprite).top ==
			anim[i])
			sfSprite_setScale(game->dash_smoke.sprite, scale[i]);
}

int check_if_dash_collides(game_t *game, sfVector2f dir)
{
	element_t *ptr;
	sfFloatRect player_rect;

	ptr = game->list->first;
	player_rect = sfRectangleShape_getGlobalBounds(game->player.hitbox);
	player_rect.left += dir.x;
	player_rect.top += dir.y;
	while (ptr != NULL) {
		if (sfFloatRect_intersects(&ptr->rect, &player_rect, NULL))
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void apply_dash(game_t *game, sfVector2f dir)
{
	sfClock_restart(game->player.dash_cooldown.clock);
	dir = check_dash_dir(game->player.sprite);
	if (check_if_dash_collides(game, dir) == 0)
		sfSprite_move(game->player.sprite, dir);
}

void check_dash(game_t *game)
{
	sfVector2f dir;
	static int left = 0;
	static int distance = 0;

	if (distance > 12 * 5) {
		game->player.dash = 0;
		left = -79;
		distance = 0;
	}
	if (game->player.dash == 1) {
		if (get_img_seconds(&game->dash_smoke) > 0.005) {
			sfClock_restart(game->dash_smoke.sfClock.clock);
			left += 79;
		}
		apply_dash(game, dir);
		distance += 12;
	} else
		left = -79;
	set_dash_smoke_properties(game, left);
}
