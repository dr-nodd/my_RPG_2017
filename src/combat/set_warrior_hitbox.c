/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Set warrior hitbox
*/

#include "combat.h"
#include "struct.h"

void set_warrior_hitbox(game_t *game)
{
	sfVector2f positions_warrior[4] =
	{{sfSprite_getPosition(game->player.sprite).x + 10,
		sfSprite_getPosition(game->player.sprite).y - 20},
	{sfSprite_getPosition(game->player.sprite).x - 40,
		sfSprite_getPosition(game->player.sprite).y},
	{sfSprite_getPosition(game->player.sprite).x + 10,
		sfSprite_getPosition(game->player.sprite).y + 30},
	{sfSprite_getPosition(game->player.sprite).x + 40,
		sfSprite_getPosition(game->player.sprite).y}};
	sfVector2f shapes_warrior[4] = {{80, 35}, {40, 30},
		{80, 40}, {40, 30}};

	set_range_shape(game, positions_warrior, shapes_warrior);
}
