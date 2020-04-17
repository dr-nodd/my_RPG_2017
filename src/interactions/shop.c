/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Shop menu
*/

#include "interactions.h"
#include "display.h"
#include "struct.h"

void set_menu_position(game_t *game, sfVector2f camera_pos)
{
	static int x = 0;
	static int y = 0;
	sfFloatRect menu_rect;

	for (int i = 0; i < 9; i++) {
		menu_rect = sfSprite_getGlobalBounds
			(game->shop_background[i].sprite);
		sfSprite_setPosition(game->shop_background[i].sprite,
			(sfVector2f){(camera_pos.x + x *
			(menu_rect.width - 1)), camera_pos.y + y *
			(menu_rect.height - 1)});
		x++;
		if (x > 2) {
			x = 0;
			y++;
		}
		if (y > 2)
			y = 0;
	}
}

void adjust_menu_position(game_t *game, sfVector2f camera_size)
{
	sfFloatRect menu_rect;
	sfVector2f menu_pos;
	sfVector2f scale = (sfVector2f){1.55, 1.55};

	for (int i = 0; i < 9; i++) {
		menu_rect = sfSprite_getGlobalBounds
			(game->shop_background[i].sprite);
		menu_pos = sfSprite_getPosition
			(game->shop_background[i].sprite);
		sfSprite_setPosition(game->shop_background[i].sprite,
			(sfVector2f){(menu_pos.x + camera_size.x / 4) -
			menu_rect.width, menu_pos.y});
		sfSprite_setScale(game->shop_background[i].sprite, scale);
	}
}

void set_shop_items_position(game_t *game)
{
	sfVector2f scale;

	for (int i = 0; i < 9; i++) {
		scale = sfSprite_getScale(game->shop_background[i].sprite);
		sfSprite_setScale(game->shop_items[i].sprite, (sfVector2f)
			{(float)(scale.x * 0.8), (float)(scale.y * 0.8)});
		sfSprite_setPosition(game->shop_items[i].sprite,
			sfSprite_getPosition
			(game->shop_background[i].sprite));
	}
}

void show_shop_menu(window_t *window, game_t *game)
{
	sfVector2f camera_pos;
	sfVector2f camera_size;

	camera_pos = sfView_getCenter(window->camera);
	camera_size = sfView_getSize(window->camera);
	set_menu_position(game, camera_pos);
	adjust_menu_position(game, camera_size);
	set_shop_items_position(game);
	handle_shop_interactions(window, game);
	for (int i = 0; i < 9; i++) {
		sfRenderWindow_drawSprite(window->window,
			game->shop_background[i].sprite, NULL);
		sfRenderWindow_drawSprite(window->window,
			game->shop_items[i].sprite, NULL);
	}
	check_if_mage_is_unlocked(window, game);
}
