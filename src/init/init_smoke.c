/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Init smoke shader
*/

#include <stdlib.h>
#include "init.h"
#include "struct.h"

void init_menu_smoke(menu_t *menu)
{
	init_img(&menu->smoke, "assets/menu/smoke/smoke.png",
	(sfIntRect){0, 0, 1920, 1080}, (sfVector2f){0, 0});
	menu->smoke_texture =
	sfTexture_createFromFile("assets/menu/smoke/smokenoise.png", NULL);
	sfTexture_setRepeated(menu->smoke_texture, sfTrue);
	sfTexture_setSmooth(menu->smoke_texture, sfTrue);
}
