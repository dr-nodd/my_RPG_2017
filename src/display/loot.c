/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Loot
*/

#include "display.h"
#include "struct.h"

void display_loot_prompt(window_t *window, game_t *game, int i)
{
	sfSprite_setScale(game->ui.coin[i+1].sprite, (sfVector2f){0.3, 0.3});
	sfText_setScale(game->ui.loot_txt[i].text, (sfVector2f){0.3, 0.3});
	sfText_setString(game->ui.loot_txt[i].text, "+10");
	if (game->mob[i].dead == 1) {
		sfSprite_move(game->ui.coin[i+1].sprite, (sfVector2f){0, -1});
		sfText_move(game->ui.loot_txt[i].text, (sfVector2f){0, -1});
		sfRenderWindow_drawSprite(window->window,
			game->ui.coin[i+1].sprite, NULL);
		sfRenderWindow_drawText(window->window,
			game->ui.loot_txt[i].text, NULL);
		animate_coin(game, 1);
	} else {
		sfSprite_setPosition(game->ui.coin[i+1].sprite,
			sfSprite_getPosition(game->mob[i].sprite));
		sfText_setPosition(game->ui.loot_txt[i].text,
			sfSprite_getPosition(game->mob[i].sprite));
	}
}
