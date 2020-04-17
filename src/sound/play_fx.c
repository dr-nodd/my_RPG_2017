/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** FX related functions
*/

#include "struct.h"
#include "class.h"

void play_mob_hit_sound(game_t *game)
{
	sfMusic_setVolume(game->fx.mob_hit_sound.music,
	sfMusic_getVolume(game->fx.sword_sound.music));
	sfMusic_play(game->fx.mob_hit_sound.music);
}

void play_fx(game_t *game)
{
	if (game->player.equipment == ARCHER)
		sfMusic_play(game->fx.bow_sound.music);
	else if (game->player.equipment == MAGE)
		sfMusic_play(game->fx.spell_sound.music);
	else {
		if (game->player.equipment == WARRIOR ||
		game->player.equipment == DAGGER ||
		game->player.equipment == GOD ||
		game->player.equipment == RECRUIT)
			sfMusic_play(game->fx.sword_sound.music);
	}
}
