/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Check flags
*/

#include <unistd.h>
#include "my.h"
#include "struct.h"

void check_flags(int ac, char **av, window_t *window)
{
	for (int i = 0; i < ac; i++) {
		if (my_strcmp(av[i], "--debug") == 0 &&	window->debug == 0) {
			window->debug = 1;
			write(2, "DEBUG MODE ACTIVATED\n", 21);
		}
		if ((my_strcmp(av[i], "--help") == 0 ||
		my_strcmp(av[i], "-H") == 0 ||
		my_strcmp(av[i], "-h") == 0) && window->show_help == 0) {
			window->show_help = 1;
		}
	}
}
