/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Settings sprite initialisation
*/

#include <stdlib.h>
#include "init.h"
#include "struct.h"

int malloc_sliders(menu_t *menu)
{
	menu->sliders_bar = malloc(sizeof(img_t) * 2);
	if (!menu->sliders_bar)
		return (-1);
	menu->sliders = malloc(sizeof(img_t) * 2);
	if (!menu->sliders)
		return (-1);
	return (0);
}

int init_sliders(menu_t *menu)
{
	if (malloc_sliders(menu) == -1)
		return (-1);
	for (int i = 0; i < 2; i++) {
		init_img(&menu->sliders_bar[i], "assets/menu/slider.png",
		(sfIntRect){0, 0, 714, 20}, (sfVector2f){1920 / 2, 1080 / 2});
		init_img(&menu->sliders[i], "assets/menu/slider_cursor.png",
		(sfIntRect){0, 0, 34, 74}, (sfVector2f){1920 / 2, 1080 / 2});
		sfSprite_setPosition(menu->sliders_bar[i].sprite,
		(sfVector2f){1300, ((float)i * 170 + 600)});
		sfSprite_setPosition(menu->sliders[i].sprite,
		(sfVector2f){1300 +
		sfSprite_getGlobalBounds(menu->sliders_bar[i].sprite).width /
		2, ((float)i * 170 + 600)});
	}
	for (int i = 6; i < 12; i++) {
		sfSprite_setScale(menu->buttons[i].sprite, (sfVector2f){1, 1});
		sfSprite_setPosition(menu->buttons[i].sprite,
		(sfVector2f){500, ((float)i * 170) - 600});
	}
	return (0);
}

int init_settings_sprites(menu_t *menu)
{
	if (init_sliders(menu) == -1)
		return (-1);
	sfSprite_setPosition(menu->buttons[9].sprite,
	(sfVector2f){1600, 950});
	sfSprite_setPosition(menu->buttons[10].sprite,
	(sfVector2f){850, 950});
	sfSprite_setPosition(menu->buttons[11].sprite,
	(sfVector2f){500, 230});
	init_img(&menu->resolutions, "assets/menu/resolutions.png",
	(sfIntRect){0, 475 - (475 / 5), 577, 475 / 5},
	(sfVector2f){1300, 420});
	sfSprite_setScale(menu->resolutions.sprite, (sfVector2f){0.8, 0.8});
	init_img(&menu->check, "assets/menu/check.png",
	(sfIntRect){0, 0, 310, 310}, (sfVector2f){1300,	230});
	return (0);
}
