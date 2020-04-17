/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Init related functions
*/

#ifndef INIT_H_
#define INIT_H_

#include "struct.h"

int init_img(img_t *, char const *, sfIntRect, sfVector2f);
int init_sprite(sprite_t *, char const *, sfIntRect, sfVector2f);
int init_music(music_t *, char const *, float, sfBool);
int init_text(text_t *, char const *, float, char const *);
void init_stat(game_t *);
int init_mana_bar(game_t *);
void init_icon(element_t *);
int init_window(window_t *);
int init_start_sprites(window_t *, menu_t *);
int init_menu_sprites(menu_t *);
int init_exit_sprites(menu_t *);
int init_settings_sprites(menu_t *);
int init_game_musics(window_t *, menu_t *);
void init_menu_smoke(menu_t *);
void init_world_map(game_t *);
int init_pause_sprites(window_t *, game_t *);
void init_player(game_t *);
int init_player_sprites(game_t *);
int init_collisions(game_t *);
void init_environment(game_t *);
int init_mobs(game_t *);
int init_shop_menu(game_t *);
int init_ui(game_t *);
int init_game(window_t *, game_t *);
int init_spells(game_t *);
int init_all(window_t *, menu_t *, game_t *);
int init_walk_particles(game_t *);
int init_fire_particles(game_t *);
void set_pause_yesno_buttons(window_t *, game_t *);
void set_pause_buttons(window_t *, game_t *);
void load_pause(window_t *, game_t *);
void set_fireball_position(game_t *);
void set_walking_particles(game_t *);
void set_fireball_particles(game_t *);
int init_dialogue_background(game_t *);
int init_fx(game_t *);
void init_gameover_assets(game_t *);

#endif
