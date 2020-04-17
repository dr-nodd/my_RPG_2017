/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Get elapsed time
*/

#include "struct.h"

float get_sprite_seconds(sprite_t *object)
{
	object->sfClock.time_s =
		sfClock_getElapsedTime(object->sfClock.clock);
	object->sfClock.seconds =
		object->sfClock.time_s.microseconds / 1000000.0;
	return (object->sfClock.seconds);
}

float get_img_seconds(img_t *object)
{
	object->sfClock.time_s =
		sfClock_getElapsedTime(object->sfClock.clock);
	object->sfClock.seconds =
		object->sfClock.time_s.microseconds / 1000000.0;
	return (object->sfClock.seconds);
}

float get_cooldown_seconds(sprite_t *object)
{
	object->cooldown.time_s =
		sfClock_getElapsedTime(object->cooldown.clock);
	object->cooldown.seconds =
		object->cooldown.time_s.microseconds / 1000000.0;
	return (object->cooldown.seconds);
}

float get_dash_cooldown_seconds(sprite_t *object)
{
	object->dash_cooldown.time_s =
		sfClock_getElapsedTime(object->dash_cooldown.clock);
	object->dash_cooldown.seconds =
		object->dash_cooldown.time_s.microseconds / 1000000.0;
	return (object->dash_cooldown.seconds);
}
