/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Player initialisation
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"
#include "init.h"
#include "class.h"
#include "animation.h"

void init_player_hitbox(sprite_t *sprite)
{
	sfRectangleShape *hitbox;
	sfVector2f pos;

	hitbox = sfRectangleShape_create();
	pos = sfSprite_getPosition(sprite->sprite);
	sfRectangleShape_setPosition(hitbox, (sfVector2f){pos.x, pos.y});
	sfRectangleShape_setSize(hitbox, (sfVector2f){30, 10});
	sfRectangleShape_setOrigin(hitbox, (sfVector2f){30 / 2, 10 / 2 });
	sfRectangleShape_setFillColor(hitbox, (sfColor){255, 0, 0, 100});
	sprite->hitbox = hitbox;
}

void init_player(game_t *game)
{
	init_sprite(&game->player, "assets/sprites/player/hero_peasant.png",
		(sfIntRect){0, 0, 64, 64}, (sfVector2f){413, 1189});
	init_player_hitbox(&game->player);
	init_stat(game);
	game->player.can_interact = 0;
}

char **find_armors_t_path(void)
{
	char **tab;
	char *str = malloc(sizeof(char) * (235 + 1));

	if (!str)
		return (NULL);
	str = "assets/sprites/player/hero_peasant.png:\
assets/sprites/player/hero_warrior_2.png:\
assets/sprites/player/hero_warrior_3.png:\
assets/sprites/player/hero_archer.png:\
assets/sprites/player/hero_mage.png:assets/sprites/player/hero_warrior_4.png";
	tab = my_str_to_word_array(str, ':');
	return (tab);
}

int init_player_armors(game_t *game)
{
	init_img(&game->armors_prompt, "assets/sprites/player/prompt.png",
		(sfIntRect){0, 0, 167, 164}, (sfVector2f){0, 0});
	game->show_armor = 0;
	game->armor_unlocked = malloc(sizeof(int) * 6);
	if (!game->armor_unlocked)
		return (-1);
	game->armor_unlocked[0] = 1;
	for (int i = 1; i < CLASSES_COUNT; i++)
		game->armor_unlocked[i] = 0;
	game->armors_t_path = malloc(sizeof(char *) * (CLASSES_COUNT + 1));
	if (!game->armors_t_path)
		return (-1);
	game->armors_t_path = find_armors_t_path();
	return (0);
}

int init_player_sprites(game_t *game)
{
	init_img(&game->high_dust, "assets/sprites/player/high_dust.png",
	(sfIntRect){174 * 10, 0, 174, 213}, (sfVector2f){500, 500});
	init_img(&game->player_shadow, "assets/sprites/player/\
character_shadow.png", (sfIntRect){0, 0, 41, 72}, (sfVector2f){500, 500});
	init_img(&game->dash_smoke, "assets/sprites/player/dash_smoke.png",
	(sfIntRect){-79, 0, 799 / 10, 80}, (sfVector2f){500, 500});
	sfSprite_setScale(game->dash_smoke.sprite, (sfVector2f){0.7, 0.7});
	sfSprite_setTextureRect(game->player.sprite, (sfIntRect){0, WALK_UP,
	64, 64});
	sfSprite_setScale(game->high_dust.sprite, (sfVector2f){0.52, 0.46});
	game->player.equipment = 0;
	game->player.dash = 0;
	init_img(&game->arrow, "assets/sprites/player/arrow.png",
	(sfIntRect){0, 0, 33, 5}, (sfVector2f){200, 500});
	init_sprite(&game->fireball, "assets/sprites/player/fireball.png",
	(sfIntRect){0, 0, 154, 44}, (sfVector2f){200, 500});
	init_gameover_assets(game);
	init_player_armors(game);
	return (0);
}
