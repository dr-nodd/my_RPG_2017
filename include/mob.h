/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Mob related include
*/

#ifndef MOB_H_
#define MOB_H_

#define MOBS_COUNT 10

#include "struct.h"

void animate_hit_mob(game_t *, int, int *);
void check_mob_death(game_t *, int);
void animate_mob_death(game_t *, int);
int enemy_left_is_valid(sfSprite *);
void set_proper_enemy_rect(game_t *, int, int *, int);
int find_enemy_attack_direction(float);
void mob_attacks_player(game_t *, int, int);
void animate_enemy(sprite_t, float);
void handle_enemies(window_t *, game_t *);

#endif
