/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Shop initialisation
*/

#include <stdlib.h>
#include "init.h"
#include "struct.h"

int malloc_shop_menu(game_t *game)
{
	init_img(&game->pixel_check, "assets/game_menu/check.png", (sfIntRect)
	{0, 0, 38, 38}, (sfVector2f){0, 0});
	game->shop_background = malloc(sizeof(img_t) * 9);
	game->shop_items = malloc(sizeof(img_t) * 9);
	if (!game->shop_items || !game->shop_background)
		return (-1);
	return (0);
}

int init_shop_menu(game_t *game)
{
	int x = 0;
	int y = 0;
	int width = 38;

	if (malloc_shop_menu(game) == -1)
		return (-1);
	for (int i = 0; i < 9; i++) {
		width = (x == 2 * 38 ? 36 : 38);
		init_img(&game->shop_background[i],
		"assets/game_menu/shop_background.png", (sfIntRect){x * width,
		y * 38, width, 38}, (sfVector2f){0, 0});
		init_img(&game->shop_items[i],
		"assets/game_menu/shop_items.png", (sfIntRect){x * width, y *
		38, width, 38}, (sfVector2f){0, 0});
		if (++x > 2) {
			x = 0;
			y++;
		}
	}
	return (0);
}
