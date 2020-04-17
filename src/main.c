/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Main
*/

#include <unistd.h>
#include "destroy.h"
#include "flags.h"
#include "struct.h"
#include "event.h"
#include "display.h"
#include "init.h"

void launch_my_rpg(window_t *window, menu_t *menu, game_t *game)
{
	if (sfRenderWindow_hasFocus(window->window)) {
		while (sfRenderWindow_pollEvent(window->window,
			&window->event))
			analyse_event(window, menu, game);
		display_game(window, menu, game);
		if (window->is_screenshot)
			display_screenshot(window, menu);
		sfRenderWindow_display(window->window);
	}
}

int available_shader(void)
{
	if (sfShader_isAvailable() == sfFalse) {
		write(2, "Error: Your system doesn't match\
		the requirements, go rebuild your PC.\n", 76);
		return (84);
	}
	return (0);
}

int main(int ac, char **av)
{
	window_t window;
	menu_t menu;
	game_t game;

	if (available_shader() == 84)
		return (84);
	window.debug = 0;
	window.show_help = 0;
	menu.ld_game = 0;
	if (ac > 1)
		check_flags(ac, av, &window);
	if (window.show_help == 1)
		display_help();
	else {
		if (init_all(&window, &menu, &game) == -1)
			return (-1);
		while (sfRenderWindow_isOpen(window.window))
			launch_my_rpg(&window, &menu, &game);
	}
	destroy_all(&window, &menu, &game);
	return (0);
}
