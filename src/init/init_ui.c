/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** UI initialisation
*/

#include <stdlib.h>
#include "mob.h"
#include "init.h"
#include "struct.h"

void init_ui_sprites(game_t *game)
{
	init_img(&game->ui.health, "assets/sprites/ui/health.png",
	(sfIntRect){0, 0, 713, 201}, (sfVector2f){0, 0});
	init_img(&game->ui.health_bar, "assets/sprites/ui/health_bar.png",
	(sfIntRect){0, 0, 713, 201}, (sfVector2f){0, 0});
	init_img(&game->ui.arrow_count, "assets/sprites/ui/arrow_count.png",
	(sfIntRect){0, 0, 35, 35}, (sfVector2f){0, 0});
	init_img(&game->ui.potion_count, "assets/sprites/ui/potion_count.png",
	(sfIntRect){0, 0, 35, 35}, (sfVector2f){0, 0});
	init_img(&game->ui.key_e, "assets/keys/e.png", (sfIntRect){0, 0, 28,
	29}, (sfVector2f){0, 0});
	init_img(&game->ui.save_prompt, "assets/sprites/ui/save_prompt.png",
	(sfIntRect){0, 0, 220, 30}, (sfVector2f){0, 0});
	sfSprite_setColor(game->ui.save_prompt.sprite, (sfColor){255, 255,
	255, 0});
	init_text(&game->ui.money_txt, "assets/fonts/pixelade.ttf", 20, "x");
	init_text(&game->ui.arrow_count_txt, "assets/fonts/pixelade.ttf", 20,
	"x");
	init_text(&game->ui.potion_count_txt, "assets/fonts/pixelade.ttf", 20,
	"x");
	init_mana_bar(game);
}

int init_mana_potion(game_t *game)
{
	game->ui.potion_mana_nbr = 0;
	init_img(&game->ui.potion_mana_count, "assets/sprites/ui/mana_poti\
on_count.png", (sfIntRect){0, 0, 35, 35}, (sfVector2f){0, 0});
	init_text(&game->ui.potion_mana_count_txt,
		"assets/fonts/pixelade.ttf", 20, "x");
	return (0);
}

int init_ui(game_t *game)
{
	init_ui_sprites(game);
	init_mana_potion(game);
	game->ui.arrow_nbr = 10;
	game->ui.potion_nbr = 3;
	game->ui.potion_mana_nbr = 1;
	game->ui.coin = malloc(sizeof(img_t) * (1 + MOBS_COUNT));
	if (!game->ui.coin)
		return (-1);
	game->ui.loot_txt = malloc(sizeof(text_t) * (1 + MOBS_COUNT));
	if (!game->ui.loot_txt)
		return (-1);
	for (int i = 0; i < 1 + MOBS_COUNT; i++) {
		init_img(&game->ui.coin[i], "assets/game_menu/coin.png",
		(sfIntRect){0, 0, 100, 100}, (sfVector2f){0, 0});
		init_text(&game->ui.loot_txt[i], "assets/fonts/pixelade.ttf",
		80, "HP");
	}
	return (0);
}
