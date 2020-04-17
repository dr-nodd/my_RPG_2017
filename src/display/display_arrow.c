/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Displays arrows
*/

#include <stdlib.h>
#include "class.h"
#include "elapsed_time.h"
#include "animation.h"
#include "struct.h"

void set_arrow_position(game_t *game)
{
	int anim[4] = {BOW_LEFT, BOW_UP, BOW_RIGHT, BOW_DOWN};
	int angle[4] = {0, 90, 0, 90};
	sfVector2f shape[4] = {{1, 1}, {1, 1}, {-1, 1}, {-1, 1}};

	sfSprite_setPosition(game->arrow.sprite,
	sfSprite_getPosition(game->player.sprite));
	for (int i = 0; i < 4; i++) {
		if (sfSprite_getTextureRect(game->player.sprite).top ==
			anim[i]) {
			sfSprite_setRotation(game->arrow.sprite, angle[i]);
			sfSprite_setScale(game->arrow.sprite, shape[i]);
			return;
		}
	}
}

sfVector2f check_arrow_direction(game_t *game)
{
	float speed = 10;
	int angle[4] = {0, 90, 0, 90};
	sfVector2f shape[4] = {{1, 1}, {1, 1}, {-1, 1}, {-1, 1}};
	sfVector2f dir[4] = {{-speed, 0}, {0, -speed}, {speed, 0},
		{0, speed}};

	for (int i = 0; i < 4; i++)
		if (sfSprite_getRotation(game->arrow.sprite) == angle[i] &&
			sfSprite_getScale(game->arrow.sprite).x == shape[i].x
			&& sfSprite_getScale(game->arrow.sprite).y ==
			shape[i].y)
				return (dir[i]);
	return ((sfVector2f){0, 0});
}

void display_arrow(window_t *window, game_t *game)
{
	sfVector2f arr_dir;

	if (get_img_seconds(&game->arrow) > ARROW_LIFETIME &&
		game->player.in_attack == 1 &&
		game->player.equipment == ARCHER) {
		set_arrow_position(game);
		sfClock_restart(game->arrow.sfClock.clock);
	}
	if (get_img_seconds(&game->arrow) < ARROW_LIFETIME) {
		arr_dir = check_arrow_direction(game);
		sfSprite_move(game->arrow.sprite, arr_dir);
		sfRenderWindow_drawSprite(window->window,
		game->arrow.sprite, NULL);
	}
}
