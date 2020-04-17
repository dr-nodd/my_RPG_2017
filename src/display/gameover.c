/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Gameover
*/

#include <stdlib.h>
#include "display.h"
#include "animation.h"
#include "elapsed_time.h"
#include "struct.h"

void play_death_animation(window_t *window, game_t *game)
{
	sfIntRect rect;
	static float threshold = 0.2;

	sfView_setCenter(window->camera,
		sfSprite_getPosition(game->player.sprite));
	if (sfView_getSize(window->camera).x > 400)
		sfView_zoom(window->camera, 0.99);
	sfRenderWindow_setView(window->window, window->camera);
	rect = sfSprite_getTextureRect(game->player.sprite);
	rect.top = DEATH;
	if (get_sprite_seconds(&game->player) > threshold &&
		sfSprite_getTextureRect(game->player.sprite).left < 64 * 5) {
		sfClock_restart(game->player.sfClock.clock);
		threshold += 0.2;
		rect.left += 64;
		sfSprite_setTextureRect(game->player.sprite, rect);
	} else if (sfSprite_getTextureRect(game->player.sprite).left >= 64
		* 5)
		threshold = 0.2;
}

void display_gameover(window_t *window, menu_t *menu, game_t *game)
{
	sfColor go_color;
	int speed = 4;

	go_color = sfSprite_getColor(game->gameover.sprite);
	if (get_img_seconds(&game->gameover) > 3 && go_color.a + speed <
		255)
		go_color.a += speed;
	else if (go_color.a + speed > 255)
		go_color.a = 255;
	game->player_stat.health = game->player_stat.max_health;
	sfSprite_setColor(game->gameover.sprite, go_color);
	sfMusic_stop(game->main_game_music.music);
	if (sfMusic_getStatus(game->gameover_song.music) != sfPlaying)
		sfMusic_play(game->gameover_song.music);
	sfRenderWindow_drawSprite(window->window,
		game->gameover.sprite, NULL);
	sfRenderWindow_drawSprite(window->window,
		menu->buttons[3].sprite, NULL);
	sfRenderWindow_drawSprite(window->window,
		menu->buttons[9].sprite, NULL);
}

void gameover_screen(window_t *window, menu_t *menu, game_t *game)
{
	sfRenderWindow_clear(window->window, sfBlack);
	play_death_animation(window, game);
	display_player(window, game);
	handle_gameover_buttons(window, menu, game);
	sfSprite_setPosition(game->gameover.sprite,
	sfSprite_getPosition(game->player.sprite));
	sfSprite_setScale(game->gameover.sprite, (sfVector2f){0.1, 0.1});
	display_gameover(window, menu, game);
}
