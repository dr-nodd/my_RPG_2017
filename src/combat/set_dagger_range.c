/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Set dagger hitbox
*/

#include "combat.h"
#include "struct.h"

void set_dagger_range(game_t *game)
{
	sfVector2f positions_dagger[4] =
	{{sfSprite_getPosition(game->player.sprite).x,
		sfSprite_getPosition(game->player.sprite).y - 40},
	{sfSprite_getPosition(game->player.sprite).x - 30,
		sfSprite_getPosition(game->player.sprite).y},
	{sfSprite_getPosition(game->player.sprite).x,
		sfSprite_getPosition(game->player.sprite).y + 40},
	{sfSprite_getPosition(game->player.sprite).x + 30,
		sfSprite_getPosition(game->player.sprite).y}};
	sfVector2f shapes_dagger[4] = {{30, 30}, {30, 30},
		{30, 30}, {30, 30}};

	set_range_shape(game, positions_dagger, shapes_dagger);
}
