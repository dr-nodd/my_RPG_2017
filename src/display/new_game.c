/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** New Game
*/

#include <stdlib.h>
#include "npc.h"
#include "tools.h"
#include "mob.h"
#include "combat.h"
#include "sound.h"
#include "display.h"
#include "struct.h"

void new_game_interactions(window_t *window, game_t *game)
{
	if (game->player.can_interact == 0) {
		game->in_shop = 0;
		game->in_dialogue = 0;
	}
	if (game->in_shop == 1)
		show_shop_menu(window, game);
	if (game->in_dialogue == 2) {
		show_dialogue(window, game);
	}
}

void play_musics(window_t *window, game_t *game)
{
	if (sfMusic_getStatus(game->main_game_music.music) != sfPlaying) {
		sfMusic_play(game->main_game_music.music);
	}
	sfMusic_setVolume(game->main_game_music.music, window->music_volume);
	sfMusic_setVolume(game->fx.bow_sound.music, window->effect_volume);
	sfMusic_setVolume(game->fx.spell_sound.music, window->effect_volume);
	sfMusic_setVolume(game->fx.sword_sound.music, window->effect_volume);
}

void launch_new_game(window_t *window, game_t *game)
{
	play_musics(window, game);
	move_player(game, game->player_stat.speed);
	check_dash(game);
	sfView_setSize(window->camera, (sfVector2f){672, 378});
	sfView_setCenter(window->camera,
	sfSprite_getPosition(game->player.sprite));
	sfRenderWindow_setView(window->window, window->camera);
	animate_combat(game);
	sfRenderWindow_clear(window->window, sfBlack);
	display_player(window, game);
	handle_npcs(window, game);
	handle_enemies(window, game);
	display_arrow(window, game);
	display_fireball(window, game);
	check_equipments_to_show(window, game);
	set_ui(window, game);
	new_game_interactions(window, game);
}

void check_prompt(window_t *window, menu_t *menu)
{
	check_yes_no_buttons(window, menu);
	check_menu_sounds(window, menu, 4, 5);
	sfRenderWindow_clear(window->window, sfBlack);
	animate_background(menu);
	animate_menu_knight(menu);
}

void new_game_prompt(window_t *window, menu_t *menu)
{
	check_prompt(window, menu);
	sfRenderWindow_drawSprite(window->window,
				  menu->background.sprite, NULL);
	display_smoke(window, menu);
	sfRenderWindow_drawSprite(window->window,
				  menu->menu_knight_shadow.sprite, NULL);
	sfRenderWindow_drawSprite(window->window,
				  menu->menu_knight.sprite, NULL);
	sfRenderWindow_drawSprite(window->window,
				  menu->menu_fg.sprite, NULL);
	if (menu->ld_game == 0)
		sfRenderWindow_drawSprite(window->window,
					  menu->new_game_text.sprite, NULL);
	sfRenderWindow_drawSprite(window->window,
				  menu->buttons[4].sprite, NULL);
	sfRenderWindow_drawSprite(window->window,
				  menu->buttons[5].sprite, NULL);
}
