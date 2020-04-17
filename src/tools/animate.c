/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Animate a sprite
*/

#include "elapsed_time.h"
#include "struct.h"

void animate_sprite(sprite_t *object, int frame_nb, float speed)
{
	sfIntRect rect;

	rect = sfSprite_getTextureRect(object->sprite);
	object->sfClock.seconds = get_sprite_seconds(object);
	if (object->sfClock.seconds > speed) {
		sfClock_restart(object->sfClock.clock);
		if (object->rect.left > (frame_nb - 2) * rect.width)
			object->rect.left = rect.width;
		else
			object->rect.left += rect.width;
	}
	sfSprite_setTextureRect(object->sprite, object->rect);
}
