/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Menu knight animation
*/

#include "elapsed_time.h"
#include "struct.h"

void set_menu_knight_shadow(menu_t *menu)
{
	sfVector2f pos;

	pos = sfSprite_getPosition(menu->menu_knight.sprite);
	sfSprite_setPosition(menu->menu_knight_shadow.sprite, (sfVector2f)
		{pos.x + 140, pos.y + 110 + (sfSprite_getGlobalBounds
		(menu->menu_knight_shadow.sprite).height / 2)});
}

void animate_menu_knight(menu_t *menu)
{
	static int left = 0;
	static int top = 0;
	sfIntRect rect;

	rect = sfSprite_getTextureRect(menu->menu_knight.sprite);
	if (left >= 3840) {
		left = 0;
		top += rect.height;
	}
	if (top >= 3840)
		top = 0;
	if (get_img_seconds(&menu->menu_knight) > 0.1) {
		sfClock_restart(menu->menu_knight.sfClock.clock);
		sfSprite_setTextureRect(menu->menu_knight.sprite,
			(sfIntRect){left, top, rect.width, rect.height});
		left += rect.width;
	}
	set_menu_knight_shadow(menu);
}
