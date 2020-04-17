/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Sound related includes
*/

#ifndef SOUND_H_
#define SOUND_H_

#include "struct.h"

void check_menu_sounds(window_t *, menu_t *, int, int);
void change_volumes(window_t *, menu_t *, int);
void play_hover(window_t *, menu_t *, img_t *);
void play_mob_hit_sound(game_t *);
void play_fx(game_t *);

#endif
