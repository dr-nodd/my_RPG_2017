/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Show armors
*/

#include "class.h"
#include "elapsed_time.h"
#include "struct.h"

int check_which_armor_is_available(game_t *game, int top_armor)
{
	static int n = 0;

	if (n > CLASSES_COUNT - 1)
		n = 0;
	if (game->armor_unlocked[n] == 1) {
		top_armor = 164 * n;
		n++;
	}
	if (n > CLASSES_COUNT - 1)
		n = 0;
	while (game->armor_unlocked[n] == 0) {
		if (n > CLASSES_COUNT - 1)
			n = 0;
		n++;
	}
	return (top_armor);
}

void set_armor_to_show(window_t *window, game_t *game)
{
	static int top_armor = 0;

	top_armor = check_which_armor_is_available(game, top_armor);
	sfClock_restart(game->armors_prompt.sfClock.clock);
	sfSprite_setTextureRect(game->armors_prompt.sprite, (sfIntRect)
	{0, top_armor, 167, 164});
	sfSprite_setPosition(game->armors_prompt.sprite,
	(sfVector2f){(sfView_getCenter(window->camera).x -
	sfView_getSize(window->camera).x / 2) -
	sfSprite_getGlobalBounds(game->armors_prompt.sprite).width / 2,
	sfView_getCenter(window->camera).y});
}

void display_smoke_when_changing_armor(window_t *window, game_t *game)
{
	if (get_img_seconds(&game->high_dust) > 0.02) {
		sfClock_restart(game->high_dust.sfClock.clock);
		sfSprite_setTextureRect(game->high_dust.sprite, (sfIntRect)
		{sfSprite_getTextureRect(game->high_dust.sprite).left +
		sfSprite_getTextureRect(game->high_dust.sprite).width,
		0, 174, 213});
	}
	sfSprite_setPosition(game->high_dust.sprite,
	(sfVector2f){sfSprite_getPosition(game->player.sprite).x + 5,
	sfSprite_getPosition(game->player.sprite).y - 10});
	sfRenderWindow_drawSprite(window->window,
	game->high_dust.sprite, NULL);
}

void handle_time_show_armor(game_t *game, int threshold, float dest,
			window_t *window)
{
	static int is_arrived = 0;

	if (get_img_seconds(&game->armors_prompt) < threshold / 2) {
		if (sfSprite_getPosition(game->armors_prompt.sprite).x < dest)
			sfSprite_move(game->armors_prompt.sprite,
			(sfVector2f){10, 0});
		else
			is_arrived = 1;
		if (is_arrived)
			sfSprite_setPosition(game->armors_prompt.sprite,
			(sfVector2f) {dest, sfView_getCenter(window->camera).y});
	} else
		if (sfSprite_getPosition(game->armors_prompt.sprite).x > dest
		- sfSprite_getGlobalBounds(game->armors_prompt.sprite).width)
			sfSprite_move(game->armors_prompt.sprite,
			(sfVector2f){-10, 0});
		else {
			is_arrived = 0;
			game->show_armor = 0;
		}
}

void check_equipments_to_show(window_t *window, game_t *game)
{
	int threshold = 5;
	float dest;

	dest = ((sfView_getCenter(window->camera).x -
	sfView_getSize(window->camera).x / 2) -
	sfSprite_getGlobalBounds(game->armors_prompt.sprite).width / 2) +
	sfSprite_getGlobalBounds(game->armors_prompt.sprite).width;
	if (get_img_seconds(&game->armors_prompt) < threshold) {
		handle_time_show_armor(game, threshold, dest, window);
		sfSprite_setPosition(game->armors_prompt.sprite, (sfVector2f)
		{sfSprite_getPosition(game->armors_prompt.sprite).x,
		sfView_getCenter(window->camera).y});
		sfSprite_setScale(game->armors_prompt.sprite,
		(sfVector2f){0.5, 0.5});
		sfRenderWindow_drawSprite(window->window,
		game->armors_prompt.sprite, NULL);
	}
	display_smoke_when_changing_armor(window, game);
}
