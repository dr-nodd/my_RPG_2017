/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Destroy ui
*/

#include "mob.h"
#include "struct.h"

void destroy_dialogue(game_t *game)
{
	sfSprite_destroy(game->ui.dialogue_background.sprite);
	sfTexture_destroy(game->ui.dialogue_background.texture);
	sfText_destroy(game->ui.dialogue_txt.text);
}

void destroy_animation_coin(game_t *game)
{
	for (int i = 0; i < 1 + MOBS_COUNT; i++) {
		sfSprite_destroy(game->ui.coin[i].sprite);
		sfTexture_destroy(game->ui.coin[i].texture);
		sfText_destroy(game->ui.loot_txt[i].text);
	}
}

void destroy_shop(game_t *game)
{
	for (int i = 0; i < 9; i++) {
		sfSprite_destroy(game->shop_background[i].sprite);
		sfTexture_destroy(game->shop_background[i].texture);
		sfSprite_destroy(game->shop_items[i].sprite);
		sfTexture_destroy(game->shop_items[i].texture);
	}
}

void destroy_invent(game_t *game)
{
	sfSprite_destroy(game->ui.arrow_count.sprite);
	sfTexture_destroy(game->ui.arrow_count.texture);
	sfText_destroy(game->ui.arrow_count_txt.text);
	sfSprite_destroy(game->ui.potion_count.sprite);
	sfTexture_destroy(game->ui.potion_count.texture);
	sfText_destroy(game->ui.potion_count_txt.text);
	sfSprite_destroy(game->ui.potion_mana_count.sprite);
	sfTexture_destroy(game->ui.potion_mana_count.texture);
	sfText_destroy(game->ui.potion_mana_count_txt.text);
}

void destroy_ui(game_t *game)
{
	sfText_destroy(game->ui.hp_stat_txt.text);
	sfSprite_destroy(game->ui.health.sprite);
	sfTexture_destroy(game->ui.health.texture);
	sfSprite_destroy(game->ui.health_bar.sprite);
	sfTexture_destroy(game->ui.health_bar.texture);
	sfSprite_destroy(game->ui.mana.sprite);
	sfTexture_destroy(game->ui.mana.texture);
	sfSprite_destroy(game->ui.mana_bar.sprite);
	sfTexture_destroy(game->ui.mana_bar.texture);
	sfSprite_destroy(game->ui.key_e.sprite);
	sfTexture_destroy(game->ui.key_e.texture);
	sfSprite_destroy(game->ui.save_prompt.sprite);
	sfTexture_destroy(game->ui.save_prompt.texture);
	sfText_destroy(game->ui.money_txt.text);
	destroy_invent(game);
	destroy_shop(game);
	destroy_animation_coin(game);
	destroy_dialogue(game);
}
