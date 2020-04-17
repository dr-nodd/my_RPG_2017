/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Destroy player
*/

#include "struct.h"

void destroy_player(game_t *game)
{
	sfSprite_destroy(game->player.sprite);
	sfTexture_destroy(game->player.texture);
	sfSprite_destroy(game->armors_prompt.sprite);
	sfTexture_destroy(game->armors_prompt.texture);
	sfSprite_destroy(game->high_dust.sprite);
	sfTexture_destroy(game->high_dust.texture);
	sfSprite_destroy(game->player_shadow.sprite);
	sfTexture_destroy(game->player_shadow.texture);
	sfSprite_destroy(game->dash_smoke.sprite);
	sfTexture_destroy(game->dash_smoke.texture);
	sfSprite_destroy(game->arrow.sprite);
	sfTexture_destroy(game->arrow.texture);
	sfSprite_destroy(game->fireball.sprite);
	sfTexture_destroy(game->fireball.texture);
	sfSprite_destroy(game->gameover.sprite);
	sfTexture_destroy(game->gameover.texture);
	sfSprite_destroy(game->explosion.sprite);
	sfTexture_destroy(game->explosion.texture);
}
