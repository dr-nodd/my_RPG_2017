/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Animation in combats
*/

#include "mob.h"
#include "class.h"
#include "struct.h"
#include "combat.h"

void switch_combat(game_t *game)
{
	switch (game->player.equipment) {
	case (DAGGER):
		swing_dagger(game);
		break;
	case (RECRUIT):
		swing_sword(game);
		break;
	case (WARRIOR):
		swing_sword(game);
		break;
	case (ARCHER):
		shoot_bow(game);
		break;
	case (MAGE):
		launch_spell(game);
		break;
	case (GOD):
		swing_sword(game);
		break;
	}
}

int damage_mob_combat(int i, game_t *game, int attacked)
{
	if (attacked == 0) {
		game->mob[i].health = (game->mob[i].health > 0 ?
			game->mob[i].health - 10 : 0);
		check_mob_death(game, i);
	}
	return (attacked);
}

void animate_combat(game_t *game)
{
	static int attacked[MOBS_COUNT];

	switch_combat(game);
	for (int i = 0; i < MOBS_COUNT; i++) {
		set_hitboxes(&game->mob[i]);
		if ((is_in_range(game, game->mob[i]) &&
		game->player.in_attack) || arrow_collides(game) == 2 ||
		fireball_collides(game) == 2) {
			animate_hit_mob(game, i, attacked);
			attacked[i] = damage_mob_combat(i, game, attacked[i]);
			attacked[i]++;
		} else {
			sfSprite_setColor(game->mob[i].sprite, sfWhite);
			attacked[i] = 0;
		}
	}
}
