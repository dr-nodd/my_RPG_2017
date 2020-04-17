/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Init mob
*/

#include <stdlib.h>
#include "my.h"
#include "init.h"
#include "mob.h"
#include "combat.h"
#include "struct.h"

char **find_mob_t_path(void)
{
	char **tab;
	char *str = malloc(sizeof(char) * (255));

	if (!str)
		return (NULL);
	str = "assets/sprites/mobs/1.png:assets/sprites/mobs/2.png:assets/\
sprites/mobs/3.png:assets/sprites/mobs/4.png:assets/sprites/mobs/5.png:\
assets/sprites/mobs/6.png:assets/sprites/mobs/7.png";
	tab = my_str_to_word_array(str, ':');
	return (tab);
}

int init_mobs(game_t *game)
{
	char **mob_t_path = find_mob_t_path();

	game->mob = malloc(sizeof(sprite_t) * MOBS_COUNT);
	if (!game->mob)
		return (-1);
	game->mobshadow = malloc(sizeof(sprite_t) * MOBS_COUNT);
	if (!game->mobshadow)
		return (-1);
	for (int i = 0; i < MOBS_COUNT; i++) {
		init_sprite(&game->mob[i], mob_t_path[rand() % 6],
		(sfIntRect){0, 0, 64,
		64}, (sfVector2f){100, 500});
		reset_mob_position(game, i);
		init_img(&game->mobshadow[i],
		"assets/sprites/player/character_shadow.png", (sfIntRect){0,
		0, 41, 72}, (sfVector2f){500, 500});
	}
	return (0);
}
