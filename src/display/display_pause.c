/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Displays pause
*/

#include <stdlib.h>
#include "struct.h"
#include "init.h"
#include "interactions.h"
#include "my.h"
#include "display.h"

void draw_pause_buttons(window_t *window, game_t *game, sfVector2f vignette)
{
	for (int i = 0; i < 5; i++) {
		sfSprite_setScale(game->pause_button[i].sprite,
		sfSprite_getScale(game->scroll.sprite));
		sfSprite_setPosition(game->pause_button[i].sprite,
		(sfVector2f){vignette.x - (float)(window->mode.width / 3.5),
		vignette.y - (float)(window->mode.height / 4.7) + (i *
		((float)(window->mode.height / 8)))});
		sfSprite_setPosition(game->pause_button[5].sprite,
		(sfVector2f){-20000, -20000});
		sfSprite_setPosition(game->pause_button[6].sprite,
		(sfVector2f){-20000, -20000});
		sfRenderWindow_drawSprite(window->window,
		game->pause_button[i].sprite, NULL);
	}
}

void display_pause_buttons(window_t *window, game_t *game)
{
	sfVector2f vignette;

	vignette = sfSprite_getPosition(game->vignette.sprite);
	if (sfSprite_getTextureRect(game->scroll.sprite).height < 1920)
		sfSprite_setTextureRect(game->scroll.sprite, (sfIntRect){0, 0,
		sfSprite_getTextureRect(game->scroll.sprite).width,
		sfSprite_getTextureRect(game->scroll.sprite).height + 100});
	sfSprite_setScale(game->pause_rect.sprite,
	sfSprite_getScale(game->scroll.sprite));
	draw_pause_buttons(window, game, vignette);
}

void display_stat(game_t *game, window_t *window)
{
	sfVector2f coin_pos = sfSprite_getPosition(game->ui.coin->sprite);

	sfText_setString(game->ui.hp_stat_txt.text, my_strcat(my_strcat(
	my_strcat(my_strcat(my_strcat("Level\t", my_itoa(
	game->player_stat.lvl, 10)), my_strcat("\nSpeed\t", my_itoa((int)(
	game->player_stat.speed * 10), 10))), my_strcat(my_strcat("\nHp\t",
	my_itoa((int)(game->player_stat.health), 10)), my_strcat(" / ",
	my_itoa(game->player_stat.max_health, 10)))), my_strcat(my_strcat(
	"\nMana\t", my_itoa(game->player_stat.mana, 10)), my_strcat(" / ",
	my_itoa(game->player_stat.max_mana, 10)))), my_strcat(my_strcat(
	"\nXp\t", my_itoa(game->player_stat.xp, 10)), my_strcat(" / ",
	my_itoa(game->player_stat.max_xp, 10)))));
	sfText_setPosition(game->ui.hp_stat_txt.text,
	(sfVector2f){coin_pos.x - 900, coin_pos.y + 300});
	sfRenderWindow_drawText(window->window,
	game->ui.hp_stat_txt.text, NULL);
}

void draw_launch_pause(window_t *window, game_t *game, sfRenderStates state)
{
	sfRenderWindow_clear(window->window, sfBlack);
	sfRenderWindow_drawSprite(window->window, game->pause.sprite, &state);
	sfRenderWindow_drawSprite(window->window, game->vignette.sprite,
	NULL);
	sfRenderWindow_drawSprite(window->window, game->scroll.sprite, NULL);
	sfRenderWindow_drawSprite(window->window, game->pause_rect.sprite,
	NULL);
	while (sfSprite_getGlobalBounds(game->scroll.sprite).left <
	sfSprite_getGlobalBounds(game->pause.sprite).left)
		sfSprite_scale(game->scroll.sprite, (sfVector2f){0.999,
		0.999});
	display_pause_buttons(window, game);
	display_save_prompt(window, game);
	handle_money_ui(window, game);
	display_stat(game, window);
}

void launch_pause(window_t *window, game_t *game)
{
	sfRenderStates state;
	sfShader *shader;

	shader = sfShader_createFromFile(NULL, "assets/shaders/blur.frag");
	state.shader = shader;
	state.blendMode = sfBlendAlpha;
	state.transform = sfTransform_Identity;
	state.texture = NULL;
	sfShader_setFloatParameter(shader, "sigma", 5);
	sfSprite_setPosition(game->vignette.sprite,
	sfSprite_getPosition(game->player.sprite));
	sfSprite_setPosition(game->pause.sprite,
	sfSprite_getPosition(game->vignette.sprite));
	sfSprite_setPosition(game->scroll.sprite,
	sfSprite_getPosition(game->vignette.sprite));
	sfView_setCenter(window->camera,
	sfSprite_getPosition(game->vignette.sprite));
	set_pause_buttons(window, game);
	sfRenderWindow_setView(window->window, window->camera);
	draw_launch_pause(window, game, state);
}
