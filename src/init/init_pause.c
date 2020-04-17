/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Init pause
*/

#include <stdlib.h>
#include "init.h"
#include "struct.h"

int malloc_pause_sprites(game_t *game)
{
	game->pause_button = malloc(sizeof(img_t) * 7);
	if (!game->pause_button)
		return (-1);
	game->pause_text = malloc(sizeof(img_t) * 2);
	if (!game->pause_text)
		return (-1);
	return (0);
}

void init_pause_environment(game_t *game)
{
	init_img(&game->pause, "assets/menu/fadingblack.png",
		(sfIntRect){0, 0, 1920, 1080},
		sfSprite_getPosition(game->player.sprite));
	init_img(&game->vignette, "assets/pause/vignette.png",
		(sfIntRect){0, 0, 1920, 1080},
		sfSprite_getPosition(game->player.sprite));
}

int init_pause_sprites(window_t *window, game_t *game)
{
	if (malloc_pause_sprites(game) == -1)
		return (-1);
	for (int i = 0; i < 7; i++)
		init_img(&game->pause_button[i],
		"assets/pause/pause_buttons.png", (sfIntRect){0, 78
		* i, 420, 78}, (sfVector2f){-45, 280 + ((float)i * 145)});
	init_img(&game->scroll, "assets/pause/scroll.png",
	(sfIntRect){0, 0, 1920, 1080}, (sfVector2f){(float)window->mode.width
	/ 2, (float)window->mode.height / 2});
	init_img(&game->pause_rect, "assets/pause/pause_rect.png",
		(sfIntRect){0, 0, 491, 144},
		(sfVector2f){-20000, -20000});
	for (int i = 0; i < 2; i++)
		init_img(&game->pause_text[i],
		"assets/pause/pause_quit_text.png", (sfIntRect){0,
		1080 * i, 1920, 1080}, (sfVector2f){0, 0});
	sfSprite_setPosition(game->pause_rect.sprite, (sfVector2f){-60, 210});
	init_pause_environment(game);
	return (0);
}

