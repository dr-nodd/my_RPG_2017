/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Collision chained list
*/

#include <stdlib.h>
#include "struct.h"
#include "interactions.h"
#include "init.h"

list_t *initialisation(void)
{
	list_t *list = malloc(sizeof(*list));
	element_t *element = malloc(sizeof(*element));

	element->rect = (sfFloatRect){0, 0, 0, 0};
	element->next = NULL;
	list->first = element;
	return (list);
}

void erase_square(element_t *rectangle, sfImage *image)
{
	for (int i = rectangle->rect.left; i < rectangle->rect.left +
		rectangle->rect.width; i++) {
		for (int j = rectangle->rect.top; j < rectangle->rect.top +
			rectangle->rect.height; j++) {
			sfImage_setPixel(image, i, j, sfTransparent);
		}
	}
}

element_t *insert_algo_rect(sfImage *image, int x, int y, element_t *new)
{

	while (sfImage_getPixel(image, x, y).a > 0) {
		new->rect.width++;
		x++;
	}
	x--;
	while (sfImage_getPixel(image, x, y).a > 0) {
		new->rect.height++;
		y++;
	}
	y--;
	erase_square(new, image);
	init_icon(new);
	return (new);
}

void insert_all_rect(sfImage *image, int x, int y, element_t *new)
{
	if (sfImage_getPixel(image, x, y).b > 200) {
		new->type = NPC;
	} else {
		new->type = COLLISION;
	}

}

void insert_rect(list_t *list, sfImage *image, int x, int y)
{
	element_t *new = malloc(sizeof(*new));

	new->rect.left = x;
	new->rect.top = y;
	new->rect.width = 0;
	new->rect.height = 0;
	if (sfImage_getPixel(image, x, y).r > 200
	&& sfImage_getPixel(image, x, y).g > 200) {
		new->type = QUEST;
	} else if (sfImage_getPixel(image, x, y).g > 200) {
		new->type = ACTION;
	} else
		insert_all_rect(image, x, y, new);
	new = insert_algo_rect(image, x, y, new);
	new->next = list->first;
	list->first = new;
}
