/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Particles
*/

#include <time.h>
#include <stdlib.h>
#include "animation.h"
#include "struct.h"
#include "tools.h"

int init_fire_particles(game_t *game)
{
	sfVertex point;

	game->fireball_particles = sfVertexArray_create();
	sfVertexArray_resize(game->fireball_particles, FIRE_PART_NB);
	for (int i = 0; i < FIRE_PART_NB; i++)
		sfVertexArray_append(game->fireball_particles, point);
	sfVertexArray_setPrimitiveType(game->fireball_particles, sfQuads);
	game->fireball_particles_color = malloc(sizeof(sfColor) * FIRE_PART_NB
	/ 4);
	if (!game->fireball_particles_color)
		return (-1);
	for (int i = 0; i < FIRE_PART_NB / 4; i++)
		game->fireball_particles_color[i] = (sfColor){254, 164, 0, 0};
	return (0);
}

int init_walk_particles(game_t *game)
{
	sfVertex point;

	srand(time(NULL));
	game->walking_particles = sfVertexArray_create();
	sfVertexArray_resize(game->walking_particles, WALK_PART_NB);
	for (int i = 0; i < WALK_PART_NB; i++)
		sfVertexArray_append(game->walking_particles, point);
	sfVertexArray_setPrimitiveType(game->walking_particles, sfQuads);
	game->walking_particles_color = malloc(sizeof(sfColor) * WALK_PART_NB
	/ 4);
	if (!game->walking_particles_color)
		return (-1);
	for (int i = 0; i < WALK_PART_NB / 4; i++)
		game->walking_particles_color[i] = (sfColor){43, 33, 25, 0};
	return (0);
}
