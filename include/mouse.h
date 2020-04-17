/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Mouse related functions
*/

#ifndef MOUSE_H_
#define MOUSE_H_

#include "struct.h"

int mouse_is_on_button(sfSprite *, sfVector2i);
int ypos_is_on_button(sfSprite *, sfVector2i);
void place_mouse_cursor(sprite_t *, sfVector2i);
sfVector2i get_mouse_position(window_t *, sfView *);

#endif
