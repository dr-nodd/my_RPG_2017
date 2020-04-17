/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Scale image
*/

#include <math.h>
#include "elapsed_time.h"
#include "struct.h"

void sinscale_img(img_t *object, float offset, float amplitude, float speed)
{
	sfVector2f object_scale;
	static float x = 0;

	object_scale = sfSprite_getScale(object->sprite);
	if (x > 6)
		x = 0;
	object_scale.x = (cosf(x) + offset) / amplitude;
	object_scale.y = (cosf(x) + offset) / amplitude;
	if (get_img_seconds(object) > 0.01) {
		sfClock_restart(object->sfClock.clock);
		x += speed;
	}
	sfSprite_setScale(object->sprite, object_scale);
}
