/*
** EPITECH PROJECT, 2018
** mana
** File description:
** rpg
*/

#include <stdlib.h>
#include "struct.h"
#include "init.h"
#include "elapsed_time.h"

int init_mana_bar(game_t *game)
{
	init_img(&game->ui.mana_bar, "assets/sprites/ui/mana_bar.png",
	(sfIntRect){0, 0, 481, 73}, (sfVector2f){0, 0});
	init_img(&game->ui.mana, "assets/sprites/ui/mana.png",
	(sfIntRect){0, 0, 481, 73}, (sfVector2f){0, 0});
	return (0);
}

void set_mana_bars(game_t *game)
{
	sfVector2f pos = sfSprite_getPosition(game->ui.health_bar.sprite);
	sfVector2f scale = sfSprite_getScale(game->ui.health_bar.sprite);

	sfSprite_setScale(game->ui.mana_bar.sprite,
	(sfVector2f){scale.x * 1, scale.y * 0.8 });
	sfSprite_setScale(game->ui.mana.sprite,
	(sfVector2f){scale.x * 1, scale.y * 0.8 });
	sfSprite_setPosition(game->ui.mana_bar.sprite,
	(sfVector2f){pos.x - 30, pos.y + 13});
	sfSprite_setPosition(game->ui.mana.sprite,
	(sfVector2f){pos.x - 30, pos.y + 13});
}

void handle_mana_value(game_t *game)
{
	sfIntRect bar = sfSprite_getTextureRect(game->ui.mana.sprite);

	bar.width = game->player_stat.mana * 481 / game->player_stat.max_mana;
	sfSprite_setTextureRect(game->ui.mana.sprite, bar);
}

void refill_mana(game_t *game)
{
	if (game->player_stat.mana < game->player_stat.max_mana &&
	get_img_seconds(&game->ui.mana) > 1.0) {
		sfClock_restart(game->ui.mana.sfClock.clock);
		game->player_stat.mana += 1;
	}
}

void handle_mana_bar(window_t *window, game_t *game)
{
	set_mana_bars(game);
	handle_mana_value(game);
	refill_mana(game);
	sfRenderWindow_drawSprite(window->window,
	game->ui.mana_bar.sprite, NULL);
	sfRenderWindow_drawSprite(window->window, game->ui.mana.sprite, NULL);
}
