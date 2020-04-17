/*
** EPITECH PROJECT, 2018
** voila
** File description:
** my_rpg
*/

#include "struct.h"

int mouse_is_on_button(sfSprite *sprite, sfVector2i mouse_pos)
{
	return (mouse_pos.x >= sfSprite_getGlobalBounds(sprite).left &&
	mouse_pos.x <= sfSprite_getGlobalBounds(sprite).width +
	sfSprite_getGlobalBounds(sprite).left && mouse_pos.y >=
	sfSprite_getGlobalBounds(sprite).top && mouse_pos.y <=
	sfSprite_getGlobalBounds(sprite).height +
	sfSprite_getGlobalBounds(sprite).top);
}

int ypos_is_on_button(sfSprite *sprite, sfVector2i mouse_pos)
{
	return (mouse_pos.y >=
	sfSprite_getGlobalBounds(sprite).top && mouse_pos.y <=
	sfSprite_getGlobalBounds(sprite).height +
	sfSprite_getGlobalBounds(sprite).top);
}

void place_mouse_cursor(sprite_t *object, sfVector2i mouse_pos)
{
	sfSprite_setPosition(object->sprite,
	(sfVector2f){(float)mouse_pos.x, (float)mouse_pos.y});
}

sfVector2i get_mouse_position(window_t *window, sfView *view)
{
	sfVector2i mouse_pos;
	sfVector2f mouse_world;

	mouse_pos = sfMouse_getPositionRenderWindow(window->window);
	mouse_world = sfRenderWindow_mapPixelToCoords(window->window,
		mouse_pos, view);
	mouse_pos.x = (float)mouse_world.x;
	mouse_pos.y = (float)mouse_world.y;
	return (mouse_pos);
}
