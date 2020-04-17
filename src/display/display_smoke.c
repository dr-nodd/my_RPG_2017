/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Smoke shader
*/

#include <stdlib.h>
#include "struct.h"
#include "elapsed_time.h"

void display_smoke(window_t *window, menu_t *menu)
{
	sfRenderStates state;
	sfShader *shader;
	float seconds;

	shader = sfShader_createFromFile(NULL, "assets/shaders/smoke.frag");
	state.shader = shader;
	state.blendMode = sfBlendAlpha;
	state.transform = sfTransform_Identity;
	state.texture = NULL;
	sfSprite_setPosition(menu->smoke.sprite,
	sfView_getCenter(window->camera));
	seconds = get_img_seconds(&menu->smoke);
	sfShader_setFloatParameter(shader, "level", 0);
	sfShader_setFloatParameter(shader, "time", seconds);
	sfShader_setTextureParameter(shader, "currentTexture",
	menu->smoke.texture);
	sfShader_setTextureParameter(shader, "distortionMapTexture",
	menu->smoke_texture);
	sfRenderWindow_drawSprite(window->window, menu->smoke.sprite, &state);
}
