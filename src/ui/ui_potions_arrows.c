/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** UI display
*/

#include "my.h"
#include "struct.h"

void set_arrow_count_text(game_t *game)
{
	char *arrow_count;
	char *var;

	var = my_itoa(game->ui.arrow_nbr, 10);
	if (game->ui.arrow_nbr == 0)
		arrow_count = my_strcat("x", "0");
	else
		arrow_count = my_strcat("x", var);
	sfText_setString(game->ui.arrow_count_txt.text, arrow_count);
	sfText_setCharacterSize(game->ui.arrow_count_txt.text, 100);
	sfText_setScale(game->ui.arrow_count_txt.text, (sfVector2f){0.25,
		0.25});
}

void handle_arrow_count(window_t *window, game_t *game)
{
	sfVector2f pos;
	sfFloatRect rect;

	pos = sfSprite_getPosition(game->ui.health_bar.sprite);
	rect = sfText_getGlobalBounds(game->ui.arrow_count_txt.text);
	set_arrow_count_text(game);
	sfSprite_setPosition(game->ui.arrow_count.sprite, (sfVector2f){pos.x
	+ sfView_getSize(window->camera).x / 8, pos.y});
	sfText_setPosition(game->ui.arrow_count_txt.text,
	(sfVector2f){(float)(pos.x + sfView_getSize(window->camera).x / 6.3),
	(pos.y - (rect.height / 2))});
	sfText_setOrigin(game->ui.arrow_count_txt.text,
	(sfVector2f){rect.width / 2, rect.height / 2});
	sfRenderWindow_drawSprite(window->window, game->ui.arrow_count.sprite,
	NULL);
	sfRenderWindow_drawText(window->window, game->ui.arrow_count_txt.text,
	NULL);
}

void set_potion_count_text(game_t *game)
{
	char *potion_count;
	char *var;
	sfFloatRect rect =
		sfText_getGlobalBounds(game->ui.arrow_count_txt.text);

	var = my_itoa(game->ui.potion_nbr, 10);
	if (game->ui.potion_nbr == 0)
		potion_count = my_strcat("x", "0");
	else
		potion_count = my_strcat("x", var);
	sfText_setString(game->ui.potion_count_txt.text, potion_count);
	sfText_setCharacterSize(game->ui.potion_count_txt.text, 100);
	sfText_setScale(game->ui.potion_count_txt.text, (sfVector2f){0.25,
		0.25});
	sfText_setOrigin(game->ui.potion_count_txt.text,
		(sfVector2f){rect.width / 2, rect.height / 2});
}

void handle_potion_count(window_t *window, game_t *game)
{
	sfVector2f arr_count_pos =
		sfSprite_getPosition(game->ui.arrow_count.sprite);

	set_potion_count_text(game);
	sfSprite_setPosition(game->ui.potion_count.sprite, (sfVector2f)
		{arr_count_pos.x + 80, arr_count_pos.y});
	sfText_setPosition(game->ui.potion_count_txt.text, (sfVector2f)
		{arr_count_pos.x + 102, arr_count_pos.y - 6});
	sfRenderWindow_drawSprite(window->window,
		game->ui.potion_count.sprite, NULL);
	sfRenderWindow_drawText(window->window,
		game->ui.potion_count_txt.text, NULL);
}
