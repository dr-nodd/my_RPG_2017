/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Money ui
*/

#include "elapsed_time.h"
#include "my.h"
#include "scene.h"
#include "struct.h"

void set_money_text_pos(window_t *window, game_t *game, sfVector2f coin_pos)
{
	if (window->scene == PAUSE) {
		sfText_setScale(game->ui.money_txt.text,
			(sfVector2f){0.70, 0.70});
		sfText_setPosition(game->ui.money_txt.text, (sfVector2f)
			{coin_pos.x - 80, coin_pos.y + 30});
	} else {
		sfText_setScale(game->ui.money_txt.text, (sfVector2f){0.25,
			0.25});
		sfText_setPosition(game->ui.money_txt.text, (sfVector2f)
			{coin_pos.x - 40, coin_pos.y + 7});
	}
}

void set_coin_text_position(window_t *window, game_t *game)
{
	sfVector2f coin_pos = sfSprite_getPosition(game->ui.coin->sprite);
	char *money;
	char *var;
	sfFloatRect rect = sfText_getGlobalBounds(game->ui.money_txt.text);

	var = my_itoa(game->player_stat.money, 10);
	if (game->player_stat.money == 0)
		money = my_strcat("x", "0");
	else
		money = my_strcat("x", var);
	sfText_setString(game->ui.money_txt.text, money);
	sfText_setCharacterSize(game->ui.money_txt.text, 100);
	sfText_setOrigin(game->ui.money_txt.text,
		(sfVector2f){rect.width / 2, rect.height / 2});
	set_money_text_pos(window, game, coin_pos);
}

void set_coin_position(window_t *window, game_t *game)
{
	sfVector2f camera_pos = sfView_getCenter(window->camera);
	sfVector2f camera_size = sfView_getSize(window->camera);
	sfFloatRect coin_size =
		sfSprite_getGlobalBounds(game->ui.coin->sprite);

	if (window->scene == PAUSE)
		sfSprite_setScale(game->ui.coin->sprite,
			(sfVector2f){0.85, 0.85});
	else
		sfSprite_setScale(game->ui.coin->sprite,
			(sfVector2f){0.30, 0.30});
	sfSprite_setPosition(game->ui.coin->sprite,
		(sfVector2f){(float)((camera_pos.x + camera_size.x / 2) -
		coin_size.width / 1.8), (float)((camera_pos.y - camera_size.y
		/ 2) + coin_size.height / 1.8)});
	set_coin_text_position(window, game);
}

void animate_coin(game_t *game, int i)
{
	static int left = 0;

	if (get_img_seconds(&game->ui.coin[i]) > 0.1) {
		sfClock_restart(game->ui.coin[i].sfClock.clock);
			left += 100;
	}
	if (left >= 600)
		left = 0;
	sfSprite_setTextureRect(game->ui.coin[i].sprite, (sfIntRect){left, 0,
		100, 100});
}

void handle_money_ui(window_t *window, game_t *game)
{
	if (game->in_shop == 1 || window->scene == PAUSE) {
		set_coin_position(window, game);
		animate_coin(game, 0);
		sfRenderWindow_drawSprite(window->window,
		game->ui.coin->sprite, NULL);
		sfRenderWindow_drawText(window->window,
		game->ui.money_txt.text, NULL);
	}
}
