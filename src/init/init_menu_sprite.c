/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Sprite initialisation
*/

#include <stdlib.h>
#include "init.h"
#include "struct.h"

int color_scale_start_sprites(menu_t *menu)
{
	sfSprite_setColor(menu->menu_fg.sprite, (sfColor){255, 255, 255, 0});
	sfSprite_setScale(menu->menu_fg.sprite, (sfVector2f){0.8, 0.8});
	sfSprite_setColor(menu->press_start.sprite, (sfColor){255, 255, 255,
	0});
	sfSprite_setScale(menu->press_start.sprite, (sfVector2f){0.8, 0.8});
	sfSprite_setColor(menu->fadingblack.sprite, (sfColor){255, 255, 255,
	0});
	sfSprite_setColor(menu->intro.sprite, (sfColor){255, 255, 255, 0});
	sfSprite_setColor(menu->background.sprite, (sfColor){255, 255, 255,
	0});
	sfSprite_setColor(menu->menu_knight.sprite, (sfColor){255, 255, 255,
	0});
	return (0);
}

int init_start_sprites(window_t *window, menu_t *menu)
{
	init_img(&menu->intro, "assets/menu/splashscreen.png", (sfIntRect){0,
	0, 500, 830}, (sfVector2f){(float)window->mode.width / 2,
	(float)window->mode.height / 2});
	sfSprite_setColor(menu->intro.sprite, (sfColor){255, 255, 255, 1});
	init_img(&menu->menu_fg, "assets/menu/menu_title.png", (sfIntRect){0,
	0, 1920, 1080}, (sfVector2f){1920 / 2, 1080 / 2});
	init_img(&menu->press_start, "assets/menu/press_start.png",
	(sfIntRect){0, 0, 693, 173}, (sfVector2f){1920 / 2, 850});
	init_img(&menu->background, "assets/menu/background_spritesheet.png",
	(sfIntRect){100, 0, 4512 / 2, 4320 / 4},
	(sfVector2f){1920 / 2, 1080 / 2});
	init_img(&menu->menu_knight, "assets/menu/knight.png",
	(sfIntRect){0, 0, 768, 768}, (sfVector2f){1920 / 2, 1080 / 2});
	init_img(&menu->menu_knight_shadow, "assets/menu/knight_shadow.png",
	(sfIntRect){0, 0, 792, 527}, (sfVector2f){1920 / 2, 1080 / 2});
	init_img(&menu->fadingblack, "assets/menu/fadingblack.png",
	(sfIntRect){0, 0, 1920, 1080}, (sfVector2f){1920 / 2, 1080 / 2});
	color_scale_start_sprites(menu);
	return (0);
}

int init_menu_sprites(menu_t *menu)
{
	menu->buttons = malloc(sizeof(img_t) * 12);
	if (!menu->buttons)
		return (-1);
	for (int i = 0; i < 12; i++) {
		init_img(&menu->buttons[i], "assets/menu/buttons.png",
		(sfIntRect){i * 724, 0, 724, 120},
		(sfVector2f){1550, ((float)i * 100) + 650});
		sfSprite_setScale(menu->buttons[i].sprite,
		(sfVector2f){0.8, 0.8});
	}
	init_img(&menu->new_game_text, "assets/menu/new_game_text.png",
	(sfIntRect){0, 0, 506, 390}, (sfVector2f){1650, 600});
	init_menu_smoke(menu);
	return (0);
}

int init_exit_sprites(menu_t *menu)
{
	init_img(&menu->exit_prompt, "assets/menu/exit_text.png",
	(sfIntRect){0, 0, 506, 390}, (sfVector2f){1650, 700});
	sfSprite_setPosition(menu->buttons[4].sprite,
	(sfVector2f){1550, 850});
	sfSprite_setPosition(menu->buttons[5].sprite,
	(sfVector2f){1550, 950});
	return (0);
}
