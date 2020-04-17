/*
** EPITECH PROJECT, 2018
** RPGG
** File description:
** Init player's sprites
*/

#include <stdlib.h>
#include "struct.h"
#include "tools.h"
#include "init.h"
#include "mob.h"

void handle_colide(sfImage *image, int x, game_t *game)
{
	for (unsigned int y = 0; y < sfImage_getSize(image).y; y++) {
		if (sfImage_getPixel(image, x, y).a > 0) {
			insert_rect(game->list, image, x, y);
			x = 0;
			y = 0;
		}
	}
}

int init_collisions(game_t *game)
{
	sfImage *image;
	sfTexture *coltex =
		sfTexture_createFromFile("assets/environment/col.png",
			NULL);

	init_img(&game->col, "assets/environment/collisions.png",
		(sfIntRect){0, 0, 1376, 1376}, (sfVector2f){1376 / 2,
		1376 / 2});
	image = sfTexture_copyToImage(coltex);
	game->list = initialisation();
	for (unsigned int x = 0; x < sfImage_getSize(image).x; x++)
		handle_colide(image, x, game);
	return (0);
}

void init_environment(game_t *game)
{
	game->in_shop = 0;
	init_img(&game->grass, "assets/environment/grass.png",
		(sfIntRect){0, 0, 1376, 1376}, (sfVector2f){1376 / 2,
		1376 / 2});
}
