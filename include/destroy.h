/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Destroy includes
*/

#ifndef DESTROY_H_
#define DESTROY_H_

#include "struct.h"

void destroy_start_menu(menu_t *);
void destroy_environment(game_t *);
void destroy_mob(game_t *);
void destroy_music(window_t *, menu_t *, game_t *);
void destroy_particles(game_t *);
void destroy_player(game_t *);
void destroy_pause(game_t *);
void destroy_ui(game_t *);
void destroy_all(window_t *, menu_t *, game_t *);

#endif
