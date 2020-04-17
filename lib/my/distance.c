/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Calculate distance
*/

#include <math.h>
#include <SFML/Graphics.h>

int calculate_distance(sfSprite *src, sfSprite *dst)
{
	return (sqrt(pow((sfSprite_getPosition(src).x -
		sfSprite_getPosition(dst).x), 2) +
		pow((sfSprite_getPosition(src).y -
		sfSprite_getPosition(dst).y), 2)));
}

int calculate_rect_distance(sfFloatRect *src, sfFloatRect *dst)
{
	return (sqrt(pow((src->left + src->width / 4) -
	(dst->left + dst->width / 4), 2) +
	pow((src->top + src->height / 4) -
	(dst->top + dst->height / 4), 2)));
}

float find_angle(sfSprite *src, sfSprite *dst)
{
	return (atan2(
		sfSprite_getPosition(dst).y - sfSprite_getPosition(src).y,
		sfSprite_getPosition(dst).x - sfSprite_getPosition(src).x));
}
