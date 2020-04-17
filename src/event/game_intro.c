/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Game intro
*/

#include "interactions.h"
#include "display.h"
#include "init.h"
#include "elapsed_time.h"
#include "scene.h"
#include "sound.h"
#include "class.h"
#include "struct.h"
#include "tools.h"

void handle_event_dialogue(window_t *window, game_t *game)
{
	if (window->event.type == sfEvtKeyPressed) {
		if (window->event.key.code == sfKeyE
		&& game->player.can_interact == 1
		&& game->in_dialogue == 0
		&& game->in_quest == 0) {
			game->in_shop = 1;
		} else if (window->event.key.code == sfKeyE
			&& game->in_dialogue == 1) {
			game->rand_dial = rand_dialogue();
			game->in_dialogue++;
		}
	}
}

int handle_event_pause_and_map(window_t *window, game_t *game)
{
	if (window->event.key.code == sfKeyEscape) {
		sfMusic_play(game->page_flip.music);
		load_pause(window, game);
		window->scene = PAUSE;
		return (0);
	}
	if (window->event.key.code == sfKeyComma) {
		sfMusic_setVolume(game->page_flip.music,
				window->effect_volume);
		sfMusic_play(game->page_flip.music);
		window->scene = WORLDMAP;
		return (0);
	}
	return (1);
}

void handle_event_attack_arrow(game_t *game)
{
	if (game->player.equipment == ARCHER) {
		if (game->ui.arrow_nbr > 0 &&
		get_img_seconds(&game->arrow) > ARROW_LIFETIME) {
			game->ui.arrow_nbr--;
			game->player.in_attack = 1;
			play_fx(game);
			sfClock_restart(game->player.cooldown.clock);
		}
	} else if (game->player.equipment == MAGE) {
		if (game->player_stat.mana >= 50) {
			game->player_stat.mana -= 50;
			game->player.in_attack = 1;
			play_fx(game);
			sfClock_restart(game->player.cooldown.clock);
		}
	} else {
		game->player.in_attack = 1;
		play_fx(game);
		sfClock_restart(game->player.cooldown.clock);
	}
}

void handle_event_armor_and_dash(window_t *window, game_t *game)
{
	if (window->event.type == sfEvtKeyPressed && window->event.key.code
	== sfKeyTab) {
		game->show_armor = 1;
		set_armor_to_show(window, game);
	}
	if (window->event.type == sfEvtKeyPressed &&
	(window->event.key.code == sfKeyLShift && game->player.dash == 0 &&
	get_dash_cooldown_seconds(&game->player) > 0.6)) {
		game->player.dash = 1;
		sfSprite_setPosition(game->dash_smoke.sprite,
		sfSprite_getPosition(game->player.sprite));
	}
	if (window->event.type == sfEvtKeyPressed &&
	(window->event.key.code == sfKeyReturn && game->show_armor == 1))
		change_player_equipment(game);
}

void game_intro_events(window_t *window, game_t *game)
{
	handle_event_dialogue(window, game);
	refill_player(window, game);
	check_if_player_used_a_potion(window, game);
	if (window->event.type == sfEvtKeyPressed)
		if (handle_event_pause_and_map(window, game) == 0)
			return;
	if (window->event.type == sfEvtKeyPressed &&
	window->event.key.code == sfKeySpace && !game->player.in_attack) {
		handle_event_attack_arrow(game);
	}
	handle_event_armor_and_dash(window, game);
}
