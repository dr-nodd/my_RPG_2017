/*
** EPITECH PROJECT, 2018
** mana potion
** File description:
** rpg
*/

#include "my.h"
#include "struct.h"

void set_potion_mana_count_text(game_t *game)
{
	char *potion_count;
	char *var;
	sfFloatRect rect =
		sfText_getGlobalBounds(game->ui.arrow_count_txt.text);

	var = my_itoa(game->ui.potion_mana_nbr, 10);
	if (game->ui.potion_mana_nbr == 0)
		potion_count = my_strcat("x", "0");
	else
		potion_count = my_strcat("x", var);
	sfText_setString(game->ui.potion_mana_count_txt.text, potion_count);
	sfText_setCharacterSize(game->ui.potion_mana_count_txt.text, 100);
	sfText_setScale(game->ui.potion_mana_count_txt.text,
		(sfVector2f){0.25, 0.25});
	sfText_setOrigin(game->ui.potion_mana_count_txt.text,
		(sfVector2f){rect.width / 2, rect.height / 2});
}

void handle_potion_mana_count(window_t *window, game_t *game)
{
	sfVector2f pos =
		sfSprite_getPosition(game->ui.potion_count.sprite);

	set_potion_mana_count_text(game);
	sfSprite_setPosition(game->ui.potion_mana_count.sprite, (sfVector2f)
		{pos.x + 80, pos.y});
	sfText_setPosition(game->ui.potion_mana_count_txt.text, (sfVector2f)
		{pos.x + 102, pos.y - 6});
	sfRenderWindow_drawSprite(window->window,
		game->ui.potion_mana_count.sprite, NULL);
	sfRenderWindow_drawText(window->window,
		game->ui.potion_mana_count_txt.text, NULL);
}
