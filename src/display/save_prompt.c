/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Display save prompt
*/

#include <stdlib.h>
#include "struct.h"
#include "elapsed_time.h"

void set_save_prompt_position(window_t *window, game_t *game)
{
	sfVector2f scroll_pos = sfSprite_getPosition(game->scroll.sprite);
	sfVector2f camera_size = sfView_getSize(window->camera);

	sfSprite_setPosition(game->ui.save_prompt.sprite, (sfVector2f)
		{(float)(scroll_pos.x + camera_size.x / 5.5),
		(float)(scroll_pos.y - camera_size.y / 2.5)});
	sfSprite_setScale(game->ui.save_prompt.sprite, (sfVector2f){3, 3});
}

void set_save_prompt_color(game_t *game)
{
	sfColor color = sfSprite_getColor(game->ui.save_prompt.sprite);

	if (get_img_seconds(&game->ui.save_prompt) < 1.5) {
		if (color.a + 10 <= 255)
			color.a += 10;
		else
			color.a = 255;
	} else {
		if (color.a - 10 >= 255)
			color.a -= 10;
		else
			color.a = 0;
	}
	sfSprite_setColor(game->ui.save_prompt.sprite, color);
}

void display_save_prompt(window_t *window, game_t *game)
{
	set_save_prompt_position(window, game);
	if (get_img_seconds(&game->ui.save_prompt) < 3) {
		set_save_prompt_color(game);
		sfRenderWindow_drawSprite(window->window,
		game->ui.save_prompt.sprite, NULL);
	}
}
