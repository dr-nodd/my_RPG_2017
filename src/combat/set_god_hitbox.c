/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Set god hitbox
*/

#include "combat.h"
#include "struct.h"

void set_god_hitbox(game_t *game)
{
	sfVector2f positions_god[4] =
	{{sfSprite_getPosition(game->player.sprite).x + 10,
		sfSprite_getPosition(game->player.sprite).y - 30},
	{sfSprite_getPosition(game->player.sprite).x - 35,
		sfSprite_getPosition(game->player.sprite).y + 10},
	{sfSprite_getPosition(game->player.sprite).x - 5,
		sfSprite_getPosition(game->player.sprite).y + 30},
	{sfSprite_getPosition(game->player.sprite).x + 35,
		sfSprite_getPosition(game->player.sprite).y + 10}};
	sfVector2f shapes_god[4] = {{30, 90}, {90, 30},
		{30, 90}, {90, 30}};

	set_range_shape(game, positions_god, shapes_god);
}
