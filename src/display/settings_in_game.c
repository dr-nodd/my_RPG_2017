/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Pause settings
*/

#include <stdlib.h>
#include "mouse.h"
#include "sound.h"
#include "display.h"
#include "struct.h"

void reset_volume_cursors(window_t *window, menu_t *menu, game_t *game)
{
	sfFloatRect rect[2];
	sfVector2f center;

	center = sfSprite_getPosition(game->vignette.sprite);
	sfSprite_setPosition(menu->sliders_bar[0].sprite,
	(sfVector2f){center.x + (float)(window->mode.width / 6.5), center.y});
	sfSprite_setPosition(menu->sliders_bar[1].sprite,
	(sfVector2f){center.x + (float)(window->mode.width / 6.5), center.x +
	(float)(window->mode.width / 9.1)});
	rect[0] = sfSprite_getGlobalBounds(menu->sliders_bar[0].sprite);
	rect[1] = sfSprite_getGlobalBounds(menu->sliders_bar[1].sprite);
	sfSprite_setPosition(menu->sliders[0].sprite, (sfVector2f)
	{rect[0].left + (window->music_volume * (sfSprite_getGlobalBounds
		(menu->sliders_bar[0].sprite).width / 100)),
		sfSprite_getPosition(menu->sliders_bar[0].sprite).y});
	sfSprite_setPosition(menu->sliders[1].sprite, (sfVector2f)
	{rect[1].left + (window->effect_volume * (sfSprite_getGlobalBounds
		(menu->sliders_bar[1].sprite).width / 100)),
		sfSprite_getPosition(menu->sliders_bar[1].sprite).y});
}

void set_pause_settings_buttons(window_t *window, menu_t *menu, game_t *game)
{
	sfVector2f center;

	center = sfSprite_getPosition(game->vignette.sprite);
	sfSprite_setPosition(menu->check.sprite, (sfVector2f){center.x +
	(float)(window->mode.width / 2.8), center.y -
	(float)(window->mode.width / 4.8)});
	sfSprite_setPosition(menu->resolutions.sprite, (sfVector2f){center.x
	+ (float)(window->mode.width / 2.8), center.y -
	(float)(window->mode.width / 10)});
	handle_cursors(window, menu);
	check_buttons_states(window, menu);
	check_menu_sounds(window, menu, 6, 11);
	rescale_in_game_settings_buttons(window, menu, game, center);
	for (int i = 6; i < 12; i++)
		if (i != 9)
			sfRenderWindow_drawSprite(window->window,
			menu->buttons[i].sprite, NULL);
	sfRenderWindow_drawSprite(window->window, menu->resolutions.sprite,
	NULL);
	sfRenderWindow_drawSprite(window->window, menu->check.sprite, NULL);
}

void draw_pause_settings(window_t *window, menu_t *menu, game_t *game,
	sfRenderStates state)
{
	sfRenderWindow_drawSprite(window->window, game->pause.sprite, &state);
	sfRenderWindow_drawSprite(window->window, game->vignette.sprite,
	NULL);
	sfRenderWindow_drawSprite(window->window, game->scroll.sprite, NULL);
	sfRenderWindow_drawSprite(window->window, game->pause_rect.sprite,
	NULL);
	sfRenderWindow_drawSprite(window->window,
	game->pause_button[2].sprite, NULL);
	set_pause_settings_buttons(window, menu, game);
}

void pause_settings_scale(window_t *window, game_t *game)
{
	if (mouse_is_on_button(game->pause_button[2].sprite,
	window->mouse_pos)) {
		if (sfSprite_getScale(game->pause_button[2].sprite).x <= 1 ||
		sfSprite_getScale(game->pause_button[2].sprite).y <= 1) {
			sfSprite_scale(game->pause_button[2].sprite,
			(sfVector2f){1.1, 1.1});
			sfSprite_setPosition(game->pause_rect.sprite,
			sfSprite_getPosition(game->pause_button[2].sprite));
		}
	} else
		sfSprite_setScale(game->pause_button[2].sprite,
		(sfVector2f){0.8, 0.8});
	sfView_setCenter(window->camera,
	sfSprite_getPosition(game->vignette.sprite));
	sfRenderWindow_setView(window->window, window->camera);
	sfRenderWindow_clear(window->window, sfBlack);
}

void pause_settings(window_t *window, menu_t *menu, game_t *game)
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
	pause_settings_scale(window, game);
	draw_pause_settings(window, menu, game, state);
}
