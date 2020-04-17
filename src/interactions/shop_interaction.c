/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Handle shop buy
*/

#include "mouse.h"
#include "struct.h"

void handle_shop_interactions(window_t *window, game_t *game)
{
	sfIntRect menu_rect[9];
	sfFloatRect menu[9];
	sfVector2i mouse_pos = get_mouse_position(window, window->camera);

	for (int i = 0; i < 9; i++) {
		menu_rect[i] = sfSprite_getTextureRect
			(game->shop_background[i].sprite);
		menu[i] = sfSprite_getGlobalBounds
		(game->shop_background[i].sprite);
		if (sfFloatRect_contains
		(&menu[i], mouse_pos.x, mouse_pos.y)) {
			menu_rect[i].top =
			(sfMouse_isButtonPressed(sfMouseLeft) == 0 ?
			(i / 3) * 38 + 115 : (i / 3) * 38 + 230);
		} else {
			menu_rect[i].top = (i / 3) * 38;
		}
		sfSprite_setTextureRect(game->shop_background[i].sprite,
			menu_rect[i]);
	}
}
