/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Health ui
*/

#include "scene.h"
#include "struct.h"

void scale_health_bar(window_t *window, game_t *game, sfIntRect bar)
{
	sfSprite_setScale(game->ui.health_bar.sprite,
	sfSprite_getScale(game->ui.health.sprite));
	sfSprite_setPosition(game->ui.health_bar.sprite,
	(sfVector2f){sfSprite_getPosition(game->ui.health.sprite).x + 34,
	sfSprite_getPosition(game->ui.health.sprite).y});
	sfSprite_setTextureRect(game->ui.health_bar.sprite, bar);
	sfRenderWindow_drawSprite(window->window, game->ui.health.sprite,
	NULL);
	sfRenderWindow_drawSprite(window->window, game->ui.health_bar.sprite,
	NULL);
}

void handle_health_bar(window_t *window, game_t *game)
{
	sfIntRect bar;

	bar = sfSprite_getTextureRect(game->ui.health_bar.sprite);
	bar.width =
	game->player_stat.health * 534 / game->player_stat.max_health;
	if (window->scene != GAMEOVER) {
		sfClock_restart(game->gameover.sfClock.clock);
		sfSprite_setColor(game->gameover.sprite, (sfColor){255, 255,
		255, 0});
	}
	if (bar.width <= 0) {
		game->player.dead = 1;
		window->scene = GAMEOVER;
	}
	sfSprite_setScale(game->ui.health.sprite, (sfVector2f){0.2, 0.2});
	sfSprite_setPosition(game->ui.health.sprite, (sfVector2f)
	{sfView_getCenter(window->camera).x, sfView_getCenter(window->camera)
	.y + (sfView_getSize(window->camera).y / 2 -
	(sfSprite_getGlobalBounds(game->ui.health.sprite).height / 2))});
	scale_health_bar(window, game, bar);
}
