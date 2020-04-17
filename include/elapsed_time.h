/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Get elapsed time of several objects
*/

#ifndef ELAPSED_TIME_H_
#define ELAPSED_TIME_H_

#include "struct.h"

float get_sprite_seconds(sprite_t *);
float get_img_seconds(img_t *);
float get_cooldown_seconds(sprite_t *);
float get_dash_cooldown_seconds(sprite_t *);

#endif
