/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Initialisation
*/

#include "struct.h"
#include "init.h"

int init_fx(game_t *game)
{
	init_music(&game->fx.mob_hit_sound, "assets/musics/mob_hit.ogg",
	100, sfFalse);
	init_music(&game->fx.bow_sound, "assets/musics/bow.ogg", 100,
	sfFalse);
	init_music(&game->fx.sword_sound, "assets/musics/sword.ogg", 100,
	sfFalse);
	init_music(&game->fx.spell_sound, "assets/musics/spell.ogg", 100,
	sfFalse);
	init_music(&game->main_game_music, "assets/musics/main_game.ogg", 100,
	sfTrue);
	return (0);
}
