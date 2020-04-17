/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Interactions define
*/

#ifndef INTERACTIONS_H_
#define INTERACTIONS_H_

#include "struct.h"

#define COLLISION 0
#define ACTION 1
#define NPC 2
#define QUEST 3

#define REFILL_ARROW game->shop_items[0].sprite, window->mouse_pos
#define REFILL_POTION game->shop_items[1].sprite, window->mouse_pos
#define REFILL_MANA_POTION game->shop_items[2].sprite, window->mouse_pos
#define PURCHASE_MAGE game->shop_items[3].sprite, window->mouse_pos

void refill_player(window_t *, game_t *);
void check_if_player_used_a_potion(window_t *, game_t *);
void check_potion_usage(game_t *);
void handle_mana_bar(window_t *, game_t *);
void handle_health_bar(window_t *, game_t *);
void handle_money_ui(window_t *, game_t *);
void handle_arrow_count(window_t *, game_t *);
void handle_potion_count(window_t *, game_t *);
void handle_potion_mana_count(window_t *, game_t *);
void check_if_mage_is_unlocked(window_t *, game_t *);

#endif
