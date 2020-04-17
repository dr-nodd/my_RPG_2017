/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Structures
*/

#ifndef TOOLS_STRUCT_H_
#define TOOLS_STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct
{
	sfClock *clock;
	sfTime time_s;
	float seconds;
} sfClock_t;

typedef struct
{
	float health;
	int max_health;
	int money;
	int xp;
	int max_xp;
	int mana;
	int max_mana;
	float speed;
	int equipment;
	int lvl;
} stat_t;

typedef struct
{
	sfSprite *sprite;
	sfTexture *texture;
	sfIntRect rect;
	sfVector2f pos;
	sfClock_t sfClock;
	sfColor color;
	sfRectangleShape *hitbox;
	sfRectangleShape *range;
	sfClock_t cooldown;
	sfClock_t dash_cooldown;
	int in_attack;
	int health;
	int equipment;
	int shoot;
	int dash;
	int dead;
	int can_interact;
} sprite_t;

typedef struct
{
	sfSprite *sprite;
	sfTexture *texture;
	sfIntRect rect;
	sfVector2f pos;
	sfClock_t sfClock;
	sfColor color;
} img_t;

typedef struct
{
	sfMusic *music;
	float volume;
} music_t;

typedef struct
{
	sfText *text;
	sfFont *font;
} text_t;

typedef struct element_s
{
	sfFloatRect rect;
	struct element_s *next;
	int type;
	img_t icon;
} element_t;

typedef struct list_s
{
	element_t *first;
}list_t;

typedef struct rect_s
{
	sfFloatRect shape;
	struct rect_s *next;
} rect_t;

#endif
