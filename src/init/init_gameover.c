/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Gameover assets initializer
*/

#include "init.h"
#include "struct.h"

void init_gameover_assets(game_t *game)
{
	init_img(&game->gameover, "assets/game_menu/gameover.png",
	(sfIntRect){0, 0, 1570, 1000}, (sfVector2f){0, 0});
	init_music(&game->gameover_song, "assets/musics/gameover_song.ogg",
	100, sfTrue);
}
