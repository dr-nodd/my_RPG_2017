/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Particles destroy
*/

#include "struct.h"

void destroy_particles(game_t *game)
{
	sfVertexArray_destroy(game->fireball_particles);
	sfVertexArray_destroy(game->walking_particles);
}
