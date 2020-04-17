/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Destroys main_menu
*/

#include "struct.h"

void destroy_smoke(menu_t *menu)
{
	sfSprite_destroy(menu->smoke.sprite);
	sfTexture_destroy(menu->smoke.texture);
}

void destroy_main_menu(menu_t *menu)
{
	for (int i = 0; i < 12; i++) {
		sfSprite_destroy(menu->buttons[i].sprite);
		sfTexture_destroy(menu->buttons[i].texture);
	}
	for (int i = 0; i < 2; i++) {
		sfSprite_destroy(menu->sliders_bar[i].sprite);
		sfTexture_destroy(menu->sliders_bar[i].texture);
		sfSprite_destroy(menu->sliders[i].sprite);
		sfTexture_destroy(menu->sliders[i].texture);
	}
	sfSprite_destroy(menu->new_game_text.sprite);
	sfTexture_destroy(menu->new_game_text.texture);
	sfSprite_destroy(menu->exit_prompt.sprite);
	sfTexture_destroy(menu->exit_prompt.texture);
	sfSprite_destroy(menu->resolutions.sprite);
	sfTexture_destroy(menu->resolutions.texture);
	sfSprite_destroy(menu->check.sprite);
	sfTexture_destroy(menu->check.texture);
}

void destroy_start_menu(menu_t *menu)
{
	sfSprite_destroy(menu->intro.sprite);
	sfTexture_destroy(menu->intro.texture);
	sfSprite_destroy(menu->press_start.sprite);
	sfTexture_destroy(menu->press_start.texture);
	sfSprite_destroy(menu->menu_fg.sprite);
	sfTexture_destroy(menu->menu_fg.texture);
	sfSprite_destroy(menu->background.sprite);
	sfTexture_destroy(menu->background.texture);
	sfSprite_destroy(menu->menu_knight.sprite);
	sfTexture_destroy(menu->menu_knight.texture);
	sfSprite_destroy(menu->menu_knight_shadow.sprite);
	sfTexture_destroy(menu->menu_knight_shadow.texture);
	sfSprite_destroy(menu->fadingblack.sprite);
	sfTexture_destroy(menu->fadingblack.texture);
	destroy_main_menu(menu);
	destroy_smoke(menu);
}
