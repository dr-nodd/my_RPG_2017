/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Set recruit hitbox
*/

#include "combat.h"
#include "struct.h"

void set_recruit_hitbox(game_t *game)
{
	sfVector2f positions_recruit[4] =
	{{sfSprite_getPosition(game->player.sprite).x + 10,
		sfSprite_getPosition(game->player.sprite).y},
	{sfSprite_getPosition(game->player.sprite).x - 30,
		sfSprite_getPosition(game->player.sprite).y},
	{sfSprite_getPosition(game->player.sprite).x + 10,
		sfSprite_getPosition(game->player.sprite).y + 30},
	{sfSprite_getPosition(game->player.sprite).x + 30,
		sfSprite_getPosition(game->player.sprite).y + 5}};
	sfVector2f shapes_recruit[4] = {{40, 40}, {30, 20},
		{40, 30}, {30, 20}};

	set_range_shape(game, positions_recruit, shapes_recruit);
}
