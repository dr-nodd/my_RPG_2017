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

sfVector2f wp_dim(game_t *game, int option)
{
	if (option == 1) {
		return (sfSprite_getTextureRect(game->player.sprite).top ==
		WALK_DOWN || sfSprite_getTextureRect(game->player.sprite).top
		== WALK_UP ? (sfVector2f){4, 8} : (sfVector2f){8, 4});
	} else {
		return ((sfVector2f){frand_a_b(1, 3), frand_a_b(1, 3)});
	}
}

void set_particles_rectangle(sfVertexArray *arr, sfVertex **point, int i,
	sfVector2f *dim)
{
	point[i+1] = sfVertexArray_getVertex(arr,
		i+1);
	point[i+1]->position = (sfVector2f){point[i]->position.x,
		point[i]->position.y + dim[i/4].y};
	point[i+1]->color = point[i]->color;
	point[i+2] = sfVertexArray_getVertex(arr,
		i+2);
	point[i+2]->position = (sfVector2f){point[i]->position.x +
		dim[i/4].x, point[i]->position.y + dim[i/4].y};
	point[i+2]->color = point[i]->color;
	point[i+3] = sfVertexArray_getVertex(arr,
		i+3);
	point[i+3]->position = (sfVector2f){point[i]->position.x +
		dim[i/4].x, point[i]->position.y};
	point[i+3]->color = point[i]->color;
}

void set_walking_particles(game_t *game)
{
	sfVertex *point[WALK_PART_NB];
	sfVector2f player_pos =
		sfRectangleShape_getPosition(game->player.hitbox);
	static sfVector2f dim[WALK_PART_NB / 4];

	for (int i = 0; i < WALK_PART_NB; i += 4) {
		point[i] = sfVertexArray_getVertex(game->walking_particles,
			i);
		if (point[i]->color.a < 30) {
			point[i]->position = (sfVector2f)
			{frand_a_b(player_pos.x - 6, player_pos.x + 6),
			frand_a_b(player_pos.y - 6, player_pos.y + 6)};
			dim[i / 4] = wp_dim(game, 1);
			game->walking_particles_color[i / 4] = BROWN;
			game->walking_particles_color[i / 4].a = 255;
		}
		point[i]->color = game->walking_particles_color[i/4];
		set_particles_rectangle
		(game->walking_particles, point, i, dim);
		game->walking_particles_color[i/4].a -= i / WALK_PART_NB + 5;
	}
}

void set_fireball_particles(game_t *game)
{
	sfVertex *point[FIRE_PART_NB];
	sfVector2f player_pos = sfSprite_getPosition(game->fireball.sprite);
	static sfVector2f dim[FIRE_PART_NB / 4];

	for (int i = 0; i < FIRE_PART_NB; i += 4) {
		point[i] =
		sfVertexArray_getVertex(game->fireball_particles, i);
		if (point[i]->color.a < 30) {
			point[i]->position = (sfVector2f){frand_a_b
			(player_pos.x - 20, player_pos.x + 20), frand_a_b
			(player_pos.y + 20, player_pos.y - 20)};
			dim[i/4] = wp_dim(game, 2);
			game->fireball_particles_color[i / 4] = sfYellow;
			game->fireball_particles_color[i / 4].a = 255;
		}
		point[i]->color = game->fireball_particles_color[i/4];
		set_particles_rectangle
		(game->fireball_particles, point, i, dim);
		game->fireball_particles_color[i/4].a -= (rand() % 8 * 2);
	}
}
