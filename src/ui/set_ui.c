/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Set ui
*/

#include "tools.h"
#include "interactions.h"
#include "struct.h"

void set_ui(window_t *window, game_t *game)
{
	handle_health_bar(window, game);
	handle_mana_bar(window, game);
	handle_arrow_count(window, game);
	handle_potion_count(window, game);
	handle_potion_mana_count(window, game);
	handle_money_ui(window, game);
	check_potion_usage(game);
	check_interactions(window, game);
}
