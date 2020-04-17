/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Event related includes
*/

#ifndef EVENT_H_
#define EVENT_H_

#include "struct.h"

void analyse_event(window_t *, menu_t *, game_t *);
void display_world_map_events(window_t *);
void menu_events(window_t *, menu_t *);
void exit_events(window_t *, menu_t *);
void new_game_event(window_t *, menu_t *);
void settings_events(window_t *, menu_t *);
void pause_events(window_t *, menu_t *, game_t *);
void pause_settings_events(window_t *, menu_t *, game_t *);
void pause_back_to_menu_events(window_t *, game_t *);
void pause_quit_events(window_t *, game_t *);
void gameover_events(window_t *, menu_t *, game_t *);
void game_intro_events(window_t *, game_t *);

#endif
