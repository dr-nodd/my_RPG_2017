/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Move player around
*/

#include "init.h"
#include "tools.h"
#include "display.h"
#include "struct.h"

void animate_move_player(game_t *game, int *key, int i, sfVector2f *dir)
{

	if (sfKeyboard_isKeyPressed((sfKeyCode)key[i])) {
		game->player.rect.top = (i + 8) * 64;
		animate_sprite(&game->player, 8, 0.1);
		if (!test_collisions(game, dir[i])) {
			game->player.can_interact = 0;
			sfSprite_move(game->player.sprite, dir[i]);
			game->player_moves = 1;
		} else if (test_collisions(game, dir[i]) == 2)
			check_collisions_type(game);
	}
}

void move_player(game_t *game, float speed)
{
	int key[4] = {sfKeyUp, sfKeyLeft, sfKeyDown, sfKeyRight};
	sfVector2f dir[4] = {{0, -speed}, {-speed, 0},
			{0, speed}, {speed, 0}};

	set_walking_particles(game);
	if (!(sfKeyboard_isKeyPressed((sfKeyCode)key[0]) ||
	sfKeyboard_isKeyPressed((sfKeyCode)key[1]) ||
	sfKeyboard_isKeyPressed((sfKeyCode)key[2]) ||
	sfKeyboard_isKeyPressed((sfKeyCode)key[3]))) {
		game->player.rect.left = 0;
		game->player_moves = 0;
	}
	if (!game->player.in_attack)
		for (int i = 0; i < 4; i++)
			animate_move_player(game, key, i, dir);
	sfSprite_setTextureRect(game->player.sprite, game->player.rect);
}
