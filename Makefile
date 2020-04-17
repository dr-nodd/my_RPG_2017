##
## EPITECH PROJECT, 2018
## cook
## File description:
## makefile
##

SRC	=	src/main.c					\
		src/combat/arrow_collides.c			\
		src/combat/combat_animations.c			\
		src/combat/combat.c				\
		src/combat/enemy_ai.c				\
		src/combat/enemy_attack.c			\
		src/combat/find_attack_direction.c		\
		src/combat/fireball_collides.c			\
		src/combat/mob_hit.c				\
		src/combat/player_bow.c				\
		src/combat/player_range.c			\
		src/combat/reset_mob_position.c			\
		src/combat/set_dagger_range.c			\
		src/combat/set_god_hitbox.c			\
		src/combat/set_recruit_hitbox.c			\
		src/combat/set_warrior_hitbox.c			\
		src/destroy/destroy_all.c			\
		src/destroy/destroy_main_menu.c			\
		src/destroy/destroy_map.c			\
		src/destroy/destroy_mob.c			\
		src/destroy/destroy_music.c			\
		src/destroy/destroy_particles.c			\
		src/destroy/destroy_pause.c			\
		src/destroy/destroy_player.c			\
		src/destroy/destroy_ui.c			\
		src/display/animate_enemy.c			\
		src/display/change_player_equipment.c		\
		src/display/display_arrow.c			\
		src/display/display_dialogue.c			\
		src/display/display_game.c			\
		src/display/display_help.c			\
		src/display/display_pause.c			\
		src/display/display_player.c			\
		src/display/display_smoke.c			\
		src/display/display_spell.c			\
		src/display/exit_screen.c			\
		src/display/gameover_buttons.c			\
		src/display/gameover.c				\
		src/display/loot.c				\
		src/display/menu_knight.c			\
		src/display/menu_screen.c			\
		src/display/move.c				\
		src/display/new_game.c				\
		src/display/npc.c				\
		src/display/particles.c				\
		src/display/pause_back_to_menu.c		\
		src/display/pause_quit.c			\
		src/display/rescale_in_game_buttons.c		\
		src/display/save_prompt.c			\
		src/display/settings_buttons_states.c		\
		src/display/settings_in_game.c			\
		src/display/settings_screen.c			\
		src/display/show_armors.c			\
		src/display/spell.c				\
		src/display/splashscreen.c			\
		src/display/start_screen.c			\
		src/display/world_map.c				\
		src/event/analyse_event.c			\
		src/event/exit_event.c				\
		src/event/game_intro.c				\
		src/event/gameover_event.c			\
		src/event/menu_event.c				\
		src/event/new_game_event.c			\
		src/event/pause_back_menu_event.c		\
		src/event/pause_event.c				\
		src/event/pause_quit_event.c			\
		src/event/pause_settings_event.c		\
		src/event/settings_events.c			\
		src/event/world_map_event.c			\
		src/features/screenshot.c			\
		src/init/general_init.c				\
		src/init/init_all.c				\
		src/init/init_dialogue.c			\
		src/init/init_environment.c			\
		src/init/init_fx.c				\
		src/init/init_game.c				\
		src/init/init_gameover.c			\
		src/init/init_menu_settings_sprite.c		\
		src/init/init_menu_sprite.c			\
		src/init/init_mob.c				\
		src/init/init_music.c				\
		src/init/init_npc.c				\
		src/init/init_particles.c			\
		src/init/init_pause.c				\
		src/init/init_player.c				\
		src/init/init_shop.c				\
		src/init/init_smoke.c				\
		src/init/init_spells.c				\
		src/init/init_stat.c				\
		src/init/init_ui.c				\
		src/init/init_window.c				\
		src/init/init_world_map.c			\
		src/init/pause_yesno_buttons.c			\
		src/init/set_pause.c				\
		src/interactions/check_class_mage.c			\
		src/interactions/potion.c			\
		src/interactions/shop_buy.c			\
		src/interactions/shop_interaction.c		\
		src/interactions/shop.c				\
		src/save/load.c					\
		src/save/load_game.c				\
		src/save/load_variables.c			\
		src/save/save_game.c				\
		src/save/write_save.c				\
		src/sound/menu_sound.c				\
		src/sound/play_fx.c				\
		src/sound/volume.c				\
		src/tools/animate.c				\
		src/tools/chained_list.c			\
		src/tools/check_flags.c				\
		src/tools/collisions.c				\
		src/tools/dash.c				\
		src/tools/get_time.c				\
		src/tools/interactions.c			\
		src/tools/mouse.c				\
		src/tools/rand.c				\
		src/tools/scale.c				\
		src/ui/dialogues.c				\
		src/ui/health.c					\
		src/ui/mana.c					\
		src/ui/mana_potion.c				\
		src/ui/money.c					\
		src/ui/set_ui.c					\
		src/ui/ui_potions_arrows.c


NAME	=	my_rpg

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iinclude/ -Wall -W -Wextra --pedantic
LIBS	=	-Llib/my -lmy
LDFLAGS	=	-lc_graph_prog -lm

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my/
		gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(LIBS)

clean:
		rm -f $(OBJ)
		make clean -C lib/my/

fclean:		clean
		rm -f $(NAME)
		make fclean -C lib/my/

re:		fclean all

debug:	CFLAGS += -g
debug:	re
