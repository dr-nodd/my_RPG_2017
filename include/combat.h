/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Combat animation
*/

#ifndef COMBAT_H_
#define COMBAT_T_

#include "struct.h"

void swing_sword(game_t *);
void swing_dagger(game_t *);
void launch_spell(game_t *);
void shoot_bow(game_t *);
void set_hitboxes(sprite_t *);
int is_in_range(game_t *game, sprite_t mob);
void set_range_shape(game_t *, sfVector2f *, sfVector2f *);
void set_player_range(game_t *);
void set_dagger_range(game_t *);
void set_god_hitbox(game_t *);
void set_recruit_hitbox(game_t *);
void set_warrior_hitbox(game_t *);
int arrow_collides(game_t *);
void animate_combat(game_t *);
void set_player_range(game_t *);
int check_attack_direction(sfSprite *, int);
int fireball_collides(game_t *);
void reset_mob_position(game_t *, int);

#endif
