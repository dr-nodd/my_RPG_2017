/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** NPC initialisation
*/

#include "init.h"
#include "interactions.h"
#include "struct.h"

void init_icon(element_t *rect)
{
	if (rect->type == QUEST)
		init_img(&rect->icon, "assets/game_menu/exclamation.png",
		(sfIntRect){0, 0, 24, 24}, (sfVector2f){rect->rect.left +
		rect->rect.width / 2, rect->rect.top - 55});
}
