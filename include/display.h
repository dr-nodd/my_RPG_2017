/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Display related includes
*/

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "struct.h"

void animate_coin(game_t *, int);
void display_game(window_t *, menu_t *, game_t *);
void display_smoke(window_t *, menu_t *);
void display_help(void);
void check_screenshot(window_t *, menu_t *);
void display_screenshot(window_t *, menu_t *);
void display_world_map(window_t *, game_t *);
void display_player(window_t *, game_t *);
void animate_background(menu_t *);
void menu_screen(window_t *, menu_t *);
void new_game_prompt(window_t *, menu_t *);
void animate_menu_knight(menu_t *);
void check_yes_no_buttons(window_t *, menu_t *);
void pause_back_to_menu(window_t *, game_t *);
void display_save_prompt(window_t *, game_t *);
void launch_pause(window_t *, game_t *);
void pause_quit(window_t *, game_t *);
void launch_new_game(window_t *, game_t *);
void rescale_in_game_settings_buttons(window_t *, menu_t *, game_t *,
	sfVector2f);
void check_buttons_states(window_t *, menu_t *);
void handle_cursors(window_t *, menu_t *);
void move_sliders(sfSprite *, sfSprite *, sfVector2i);
int sliders_can_move(sfVector2i, sfSprite *);
void reset_volume_cursors(window_t *, menu_t *, game_t *);
void pause_settings(window_t *, menu_t *, game_t *);
void start_screen(window_t *, menu_t *);
void splash_screen(window_t *, menu_t *);
void settings_screen(window_t *, menu_t *);
void exit_screen(window_t *, menu_t *);
void handle_gameover_buttons(window_t *, menu_t *, game_t *);
void gameover_screen(window_t *, menu_t *, game_t *);
void move_player(game_t *, float);
void set_armor_to_show(window_t *, game_t *);
void check_equipments_to_show(window_t *, game_t *);
void change_player_equipment(game_t *);
void display_arrow(window_t *, game_t *);
void show_shop_menu(window_t *, game_t *);
void handle_shop_interactions(window_t *, game_t *);
void set_ui(window_t *, game_t *);
void animate_fireball(game_t *);
sfVector2f check_fireball_direction(game_t *);
void display_fireball(window_t *, game_t *);
void display_loot_prompt(window_t *, game_t *, int);
void show_dialogue(window_t *, game_t *);

#endif
