/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Rescale buttons in game
*/

#include "struct.h"

void rescale_game_buttons_settings(menu_t *menu, game_t *game)
{
	sfSprite_setScale(menu->resolutions.sprite,
	(sfVector2f){sfSprite_getScale(game->scroll.sprite).x - 0.2,
	sfSprite_getScale(game->scroll.sprite).y - 0.2});
	sfSprite_setScale(menu->check.sprite,
	sfSprite_getScale(game->scroll.sprite));
}

void rescale_game_settings_buttons(menu_t *menu, game_t *game)
{
	sfSprite_setScale(menu->buttons[7].sprite,
	(sfVector2f){sfSprite_getScale(game->scroll.sprite).x -
	0.2, sfSprite_getScale(game->scroll.sprite).y - 0.2});
	sfSprite_setScale(menu->buttons[8].sprite,
	(sfVector2f){sfSprite_getScale(game->scroll.sprite).x - 0.2,
	sfSprite_getScale(game->scroll.sprite).y - 0.2});
	sfSprite_setScale(menu->buttons[11].sprite,
	(sfVector2f){sfSprite_getScale(game->scroll.sprite).x - 0.2,
	sfSprite_getScale(game->scroll.sprite).y - 0.2});
	sfSprite_setScale(menu->sliders_bar[0].sprite,
	sfSprite_getScale(game->scroll.sprite));
	sfSprite_setScale(menu->sliders_bar[1].sprite,
	sfSprite_getScale(game->scroll.sprite));
	sfSprite_setScale(menu->sliders[0].sprite,
	sfSprite_getScale(game->scroll.sprite));
	sfSprite_setScale(menu->sliders[0].sprite,
	sfSprite_getScale(game->scroll.sprite));
	rescale_game_buttons_settings(menu, game);
}

void rescale_in_game_settings_buttons(window_t *window, menu_t *menu,
	game_t *game, sfVector2f center)
{
	sfSprite_setPosition(menu->buttons[11].sprite, (sfVector2f)
	{center.x + (float)(window->mode.width / 15), center.y -
	(float)(window->mode.width / 4.8)});
	sfSprite_setPosition(menu->buttons[6].sprite, (sfVector2f)
	{center.x + (float)(window->mode.width / 15), center.y -
	(float)(window->mode.width / 10)});
	sfSprite_setPosition(menu->buttons[7].sprite,
	(sfVector2f){sfSprite_getPosition(menu->sliders_bar[0].sprite).x,
	sfSprite_getPosition(menu->sliders_bar[0].sprite).y -
	(float)window->mode.width / 19});
	sfSprite_setPosition(menu->buttons[8].sprite,
	(sfVector2f){sfSprite_getPosition(menu->sliders_bar[1].sprite).x,
	sfSprite_getPosition(menu->sliders_bar[1].sprite).y -
	(float)window->mode.width / 19});
	sfSprite_setScale(menu->buttons[6].sprite,
	(sfVector2f){sfSprite_getScale(game->scroll.sprite).x -
	0.2, sfSprite_getScale(game->scroll.sprite).y - 0.2});
	rescale_game_settings_buttons(menu, game);
}
