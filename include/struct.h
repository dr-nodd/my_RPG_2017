/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Structures
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "tools_struct.h"

typedef struct
{
	img_t health;
	img_t health_bar;
	img_t mana;
	img_t mana_bar;
	img_t arrow_count;
	int arrow_nbr;
	text_t arrow_count_txt;
	img_t potion_count;
	img_t potion_mana_count;
	int potion_nbr;
	int potion_mana_nbr;
	text_t potion_count_txt;
	text_t potion_mana_count_txt;
	text_t hp_stat_txt;
	img_t key_e;
	img_t *coin;
	text_t money_txt;
	img_t save_prompt;
	img_t dialogue_background;
	text_t dialogue_txt;
	text_t *loot_txt;
} ui_t;

typedef struct
{
	music_t bow_sound;
	music_t sword_sound;
	music_t spell_sound;
	music_t mob_hit_sound;
} fx_t;

typedef struct
{
	sprite_t player;
	stat_t player_stat;
	img_t player_shadow;
	sprite_t dust;
	img_t grass;
	img_t fadingblack;
	img_t vignette;
	sprite_t *mob;
	img_t *mobshadow;
	img_t pause;
	img_t *pause_button;
	img_t scroll;
	img_t pause_rect;
	img_t *pause_text;
	img_t world_map;
	img_t armors_prompt;
	music_t page_flip;
	int show_armor;
	int *armor_unlocked;
	char **armors_t_path;
	img_t high_dust;
	img_t dash_smoke;
	img_t arrow;
	img_t gameover;
	img_t col;
	list_t *list;
	ui_t ui;
	int in_shop;
	int in_dialogue;
	int in_quest;
	img_t *quest_background;
	img_t *shop_background;
	img_t *shop_items;
	img_t pixel_check;
	int rand_dial;
	sfVertexArray *walking_particles;
	sfColor *walking_particles_color;
	int player_moves;
	sprite_t fireball;
	sfVertexArray *fireball_particles;
	sfColor *fireball_particles_color;
	sprite_t explosion;
	fx_t fx;
	music_t gameover_song;
	music_t main_game_music;
} game_t;

typedef struct
{
	img_t background;
	img_t menu_fg;
	img_t menu_knight;
	img_t menu_knight_shadow;
	img_t press_start;
	img_t fadingblack;
	img_t intro;
	img_t *buttons;
	img_t exit_prompt;
	img_t *sliders_bar;
	img_t *sliders;
	img_t resolutions;
	img_t check;
	img_t settings_background;
	img_t new_game_text;
	img_t screenshot;
	music_t main_menu;
	music_t hover;
	music_t start;
	img_t smoke;
	int ld_game;
	sfTexture *smoke_texture;
} menu_t;

typedef struct window {
	sfRenderWindow* window;
	sfVideoMode mode;
	sfEvent event;
	sfView *camera;
	sfVector2f camera_size;
	float music_volume;
	float effect_volume;
	int scene;
	sfVector2i mouse_pos;
	int is_screenshot;
	music_t snap;
	int debug;
	int show_help;
} window_t;

#endif
