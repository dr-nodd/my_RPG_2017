/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** task02 // Nathalie Hugot-Porez
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
	int i = 0;
	int j = 0;
	char *str = malloc(sizeof(char) *
			(my_strlen(dest) + my_strlen(src) + 1));

	if (str == NULL || dest == NULL || src == NULL)
		return (NULL);
	while (dest[i] != '\0') {
		str[i] = dest[i];
		i++;
	}
	while (src[j] != '\0') {
		str[i] = src[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
