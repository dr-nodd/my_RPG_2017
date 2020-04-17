/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Destroy musics
*/

#include "struct.h"

void destroy_music(window_t *window, menu_t *menu, game_t *game)
{
	sfMusic_destroy(game->gameover_song.music);
	sfMusic_destroy(menu->main_menu.music);
	sfMusic_destroy(game->main_game_music.music);
	sfMusic_destroy(menu->start.music);
	sfMusic_destroy(menu->hover.music);
	sfMusic_destroy(window->snap.music);
	sfMusic_destroy(game->page_flip.music);
	sfMusic_destroy(game->fx.mob_hit_sound.music);
	sfMusic_destroy(game->fx.bow_sound.music);
	sfMusic_destroy(game->fx.sword_sound.music);
	sfMusic_destroy(game->fx.spell_sound.music);
}
