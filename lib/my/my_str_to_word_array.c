/*
** EPITECH PROJECT, 2018
** Library
** File description:
** Separate a string into an array
*/

#include <stdio.h>
#include <stdlib.h>

int word_size(char *str, int i, char c)
{
	int n = 0;

	while (str[i] != c && str[i] != '\0') {
		n++;
		i++;
	}
	return (n);
}

int word_nbr(char *str, char c)
{
	int i = 0;
	int n = 0;

	while (str[i] != '\0') {
		if (str[i] == c && str[i + 1] != c
		&& (str[i + 1] != '\0' || str[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

char **my_str_to_word_array(char *str, char c)
{
	char **array;
	int x = 0;
	int y = 0;

	array = malloc(sizeof(char *) * (word_nbr(str, c) + 2));
	for (int i = 0; str[i] != '\0';) {
		while (str[i] == c)
			i++;
		array[x] = malloc(sizeof(char) * (word_size(str, i, c) + 1));
		while (str[i] != c && str[i] != '\0') {
			array[x][y] = str[i];
			y++;
			i++;
		}
		array[x][y] = '\0';
		x++;
		y = 0;
	}
	array[x] = NULL;
	return (array);
}
