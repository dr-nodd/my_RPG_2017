/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Display dialogues
*/

#include <stdlib.h>
#include "tools.h"
#include "struct.h"

void set_dialogue_position(game_t *game, sfVector2f camera_pos)
{
	sfFloatRect menu_rect;

	menu_rect = sfSprite_getGlobalBounds
	(game->ui.dialogue_background.sprite);
	sfSprite_setPosition(game->ui.dialogue_background.sprite,
	(sfVector2f){(camera_pos.x * (menu_rect.width - 1)),
	camera_pos.y * (menu_rect.height - 1)});
	sfText_setPosition(game->ui.dialogue_txt.text,
	(sfVector2f){(camera_pos.x * (menu_rect.width - 1)),
	camera_pos.y * (menu_rect.height - 1)});
}

void adjust_dialogue_position(game_t *game, sfVector2f camera_pos,
	sfVector2f camera_size)
{
	sfVector2f scale = (sfVector2f){0.52, 0.52};

	sfSprite_setPosition(game->ui.dialogue_background.sprite,
	(sfVector2f){camera_pos.x - camera_size.x/3.3,
	camera_pos.y + camera_size.y/2.6});
	sfSprite_setScale(game->ui.dialogue_background.sprite, scale);
	sfText_setPosition(game->ui.dialogue_txt.text,
	(sfVector2f){camera_pos.x - camera_size.x/2.3,
	camera_pos.y + camera_size.y/2.6});
	sfText_setScale(game->ui.dialogue_txt.text, scale);
}

void show_dialogue(window_t *window, game_t *game)
{
	sfVector2f camera_pos;
	sfVector2f camera_size;
	char **array = dialogue_to_array();

	sfText_setString(game->ui.dialogue_txt.text, array[game->rand_dial]);
	camera_pos = sfView_getCenter(window->camera);
	camera_size = sfView_getSize(window->camera);
	set_dialogue_position(game, camera_pos);
	adjust_dialogue_position(game, camera_pos, camera_size);
	sfRenderWindow_drawSprite
	(window->window, game->ui.dialogue_background.sprite, NULL);
	sfRenderWindow_drawText(window->window, game->ui.dialogue_txt.text,
	NULL);
}
