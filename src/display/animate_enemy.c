/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Animation for enemy
*/

#include "animation.h"
#include "struct.h"

int enemy_left_is_valid(sfSprite *sprite)
{
	int left[] = {0, 192, 384, 576, 768, 960, 1152, 1344, 1536};

	for (int i = 0; i <= 8; i++)
		if (sfSprite_getTextureRect(sprite).left == left[i])
			return (1);
	return (0);
}

void set_proper_enemy_rect(game_t *game, int distance, int *left, int i)
{
	if (distance <= 120) {
		sfSprite_setTextureRect(game->mob[i].sprite,
			(sfIntRect){left[i], sfSprite_getTextureRect
			(game->mob[i].sprite).top, sfSprite_getTextureRect
			(game->mob[i].sprite).width, sfSprite_getTextureRect
			(game->mob[i].sprite).height});
	} else {
		sfSprite_setTextureRect(game->mob[i].sprite,
			(sfIntRect){0, sfSprite_getTextureRect
			(game->mob[i].sprite).top, sfSprite_getTextureRect
			(game->mob[i].sprite).width, sfSprite_getTextureRect
			(game->mob[i].sprite).height});
	}
}

void animate_enemy(sprite_t enemy, float angle)
{
	int top;
	int array[8] = {WALK_LEFT, WALK_UP, WALK_UP, WALK_RIGHT,
			WALK_RIGHT, WALK_DOWN, WALK_DOWN, WALK_LEFT};
	float res = angle + 3.5 / (7.0/8.0);

	top = array[(int)res];
	sfSprite_setTextureRect(enemy.sprite, (sfIntRect){0, top, 64, 64});
	sfSprite_setOrigin(enemy.sprite, (sfVector2f){64 / 2, 64 / 2});
}

int find_enemy_attack_direction(float angle)
{
	static int top = 0;
	int array[8] = {SWORD_LEFT, SWORD_UP, SWORD_UP, SWORD_RIGHT,
			SWORD_RIGHT, SWORD_DOWN, SWORD_DOWN, SWORD_LEFT};
	float res = angle + 3.5 / (7.0/8.0);

	top = array[(int)res];
	return (top);
}
