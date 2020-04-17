/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Help display
*/

#include "struct.h"
#include "my.h"

void display_help(void)
{
	my_putstr("\n====================== MANUAL ======================\n");
	my_putstr("\nAmong Gods is a game created as part of the Epitech\
\nProject 'My RPG', using the C binding of the SFML\nlibrary\n");
	my_putstr("\n Usage: ./my_rpg [--help | -h | -H] [--debug]\n");
	my_putstr("\nKey bindings:\n");
	my_putstr("   Key Up: Move Upward\n   Key Down: Move Downward\n");
	my_putstr("   Key Left: Move Left\n   Key Right: Move Right\n");
	my_putstr("   F12: Take a screenshot\n   Comma ',': Show the map\n");
	my_putstr("   Escape: Pause the game and show the stats\n");
	my_putstr("   Space: Primary Attack\n   E: Interact\n");
	my_putstr("   A: Drink a life potion\n   Z: Drink a mana potion\n");
	my_putstr("   Tab: Select class\n   Enter: Switch to the selected \
class\n");
	my_putstr("   Shift: Dash\n");
	my_putstr("\nUse the --help | -h | -H flags to show this help\n");
	my_putstr("We hope you like our game !\n\n");
}
