/*
** EPITECH PROJECT, 2018
** load_game
** File description:
** my_rpg
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

char *find_name(char *str)
{
	char *name;
	int i = 0;
	int n = 0;

	while (str[n] != '\0' && str[n] != ':')
		n++;
	name = malloc(sizeof(char) * (n + 1));
	while (str[i] != '\0' && str[i] != ':') {
		name[i] = str[i];
		i++;
	}
	name[i] = str[i];
	name[i + 1] = '\0';
	return (name);
}

char *init_my_string(char *new, char *str)
{
	int n = 0;

	new = malloc(sizeof(char) * my_strlen(str));
	while (str[n] != '\0') {
		new[n] = str[n];
		n++;
	}
	new[n] = '\0';
	return (new);
}

char **config_load(void)
{
	char **array;

	array = malloc(sizeof(char *) * 15);
	array[0] = init_my_string(array[0], "POSX:");
	array[1] = init_my_string(array[0], "POSY:");
	array[2] = init_my_string(array[0], "LIFE:");
	array[3] = init_my_string(array[0], "LIFEMAX:");
	array[4] = init_my_string(array[0], "MANA:");
	array[5] = init_my_string(array[0], "MANAMAX:");
	array[6] = init_my_string(array[0], "MANAPOTION:");
	array[7] = init_my_string(array[0], "LIFEPOTION:");
	array[8] = init_my_string(array[0], "EQUIPEMENT:");
	array[9] = init_my_string(array[0], "MONEY:");
	array[10] = init_my_string(array[0], "XP:");
	array[11] = init_my_string(array[0], "XPMAX:");
	array[12] = init_my_string(array[0], "LVL:");
	array[13] = init_my_string(array[0], "ARROW:");
	array[14] = NULL;
	return (array);
}

char *find_variable_name(char *str)
{
	char *new;
	int i = 0;
	int n = 0;

	for (i = 0; str[i] != '\0' && str[i] != ':'; i++);
	i++;
	for (n = i; str[n] != '\0'; n++);
	new = malloc(sizeof(char) * (n + 1 - i));
	n = 0;
	for (; str[i] != '\0'; i++) {
		new[n] = str[i];
		n++;
	}
	new[n] = '\0';
	return (new);
}
