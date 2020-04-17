/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Buy items in shop
*/

#include "mouse.h"
#include "interactions.h"
#include "struct.h"

void check_arrow_buy(window_t *window, game_t *game, int price)
{
	if (mouse_is_on_button(REFILL_ARROW) &&
	game->player_stat.money >= price) {
		game->ui.arrow_nbr += 1;
		game->player_stat.money -= price;
	}
}

void check_potion_buy(window_t *window, game_t *game, int price)
{
	if (mouse_is_on_button(REFILL_POTION) &&
	game->player_stat.money >= price) {
		game->ui.potion_nbr += 1;
		game->player_stat.money -= price;
	}
}

void check_mana_potion_buy(window_t *window, game_t *game, int price)
{
	if (mouse_is_on_button(REFILL_MANA_POTION) &&
	game->player_stat.money >= price) {
		game->ui.potion_mana_nbr += 1;
		game->player_stat.money -= price;
	}
}

void check_mage_class_buy(window_t *window, game_t *game, int price)
{
	if (mouse_is_on_button(PURCHASE_MAGE) &&
	game->player_stat.money >= price && game->armor_unlocked[4] == 0) {
		game->armor_unlocked[4] = 1;
		game->player_stat.money -= price;
	}
}

void refill_player(window_t *window, game_t *game)
{
	if (window->event.type == sfEvtMouseButtonPressed &&
		game->in_shop == 1) {
		check_arrow_buy(window, game, 3);
		check_potion_buy(window, game, 25);
		check_mana_potion_buy(window, game, 45);
		check_mage_class_buy(window, game, 500);
	}
}
