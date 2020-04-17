/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Dialogue initialisation
*/

#include "struct.h"
#include "init.h"

int init_dialogue_background(game_t *game)
{
	init_img(&game->ui.dialogue_background,
	"assets/game_menu/dialog_prompt.png", (sfIntRect){0, 0, 489, 144},
	(sfVector2f){0, 0});
	init_text(&game->ui.dialogue_txt, "assets/fonts/pixelade.ttf", 26,
	NULL);
	return (0);
}
