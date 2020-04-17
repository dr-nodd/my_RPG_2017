/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Tools
*/

#ifndef TOOLS_H_
#define TOOLS_H_

#include "struct.h"

void sinscale_img(img_t *, float, float, float);
void animate_sprite(sprite_t *, int, float);
int test_collisions(game_t *, sfVector2f);
void check_dash(game_t *);
void check_collisions_type(game_t *);
void check_interactions(window_t *, game_t *);
void check_collisions_type(game_t *);
void check_resolution(window_t *, menu_t *);
void check_fullscreen(window_t *, menu_t *);
void check_buttons(window_t *, menu_t *);
void center_window(window_t *);
void insert_rect(list_t *, sfImage *, int, int);
list_t *initialisation(void);
double frand_a_b(double, double);
char **dialogue_to_array(void);
int rand_dialogue(void);
double frand_a_b(double a, double b);

#endif
