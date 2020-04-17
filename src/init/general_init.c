/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** General init functions
*/

#include <stdlib.h>
#include "struct.h"

int init_img(img_t *object, char const *texture_path, sfIntRect rect,
	sfVector2f position)
{
	object->texture = sfTexture_createFromFile(texture_path, NULL);
	if (!object->texture)
		return (1);
	object->sprite = sfSprite_create();
	sfSprite_setTexture(object->sprite, object->texture, sfTrue);
	sfSprite_setOrigin(object->sprite, (sfVector2f){(float)rect.width / 2,
		(float)rect.height / 2});
	sfSprite_setTextureRect(object->sprite, rect);
	sfSprite_setPosition(object->sprite, position);
	object->rect = rect;
	object->pos = position;
	object->color = sfSprite_getColor(object->sprite);
	object->sfClock.clock = sfClock_create();
	return (0);
}

int second_init_sprite(sprite_t *object)

{
	object->in_attack = 0;
	object->range = sfRectangleShape_create();
	object->hitbox = sfRectangleShape_create();
	sfRectangleShape_setOrigin(object->hitbox,
		(sfVector2f){30 / 2, 47 / 2});
	sfRectangleShape_setSize(object->hitbox, (sfVector2f){30, 47});
	object->health = 100;
	object->dead = 0;
	return (0);
}

int init_sprite(sprite_t *object, char const *texture_path, sfIntRect rect,
	sfVector2f position)
{
	object->texture = sfTexture_createFromFile(texture_path, NULL);
	if (!object->texture)
		return (1);
	object->sprite = sfSprite_create();
	sfSprite_setTexture(object->sprite, object->texture, sfTrue);
	sfSprite_setOrigin(object->sprite,
		(sfVector2f){(float)rect.width / 2, (float)rect.height / 2});
	sfSprite_setTextureRect(object->sprite, rect);
	sfSprite_setPosition(object->sprite, position);
	object->rect = rect;
	object->pos = position;
	object->color = sfSprite_getColor(object->sprite);
	object->sfClock.clock = sfClock_create();
	object->cooldown.clock = sfClock_create();
	object->dash_cooldown.clock = sfClock_create();
	second_init_sprite(object);
	return (0);
}

int init_music(music_t *music, char const *path, float volume, sfBool is_loop)
{
	music->music = sfMusic_createFromFile(path);
	if (!music)
		return (EXIT_FAILURE);
	sfMusic_setLoop(music->music, is_loop);
	sfMusic_setVolume(music->music, volume);
	return (0);
}

int init_text(text_t *text, char const *font_path, float size,
	char const *text_to_set)
{
	text->text = sfText_create();
	text->font = sfFont_createFromFile(font_path);
	if (!text->font)
		return (EXIT_FAILURE);
	sfText_setString(text->text, text_to_set);
	sfText_setFont(text->text, text->font);
	sfText_setCharacterSize(text->text, size);
	return (0);
}
