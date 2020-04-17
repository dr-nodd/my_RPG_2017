/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Pause quit
*/

#include <stdlib.h>
#include "struct.h"
#include "init.h"

void pause_window(window_t *window, game_t *game, sfRenderStates state)
{
	sfView_setCenter(window->camera,
		sfSprite_getPosition(game->vignette.sprite));
	sfRenderWindow_setView(window->window, window->camera);
	sfRenderWindow_clear(window->window, sfBlack);
	sfRenderWindow_drawSprite(window->window, game->pause.sprite, &state);
	sfRenderWindow_drawSprite(window->window, game->vignette.sprite,
		NULL);
	sfRenderWindow_drawSprite(window->window, game->scroll.sprite, NULL);
	sfRenderWindow_drawSprite(window->window, game->pause_rect.sprite,
		NULL);
	sfRenderWindow_drawSprite(window->window, game->pause_text[0].sprite,
		NULL);
	for (int i = 5; i < 7; i++)
		sfRenderWindow_drawSprite(window->window,
		game->pause_button[i].sprite, NULL);
}

void pause_quit(window_t *window, game_t *game)
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
	sfSprite_setPosition(game->pause_text[0].sprite,
		sfSprite_getPosition(game->scroll.sprite));
	set_pause_yesno_buttons(window, game);
	pause_window(window, game, state);
}
