/*
** EPITECH PROJECT, 2018
** arnaud
** File description:
** gnl
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int my_strlengnl(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char *my_realloc(char *str, int size)
{
	char *res;
	int i = 0;

	res = malloc(sizeof(char) * size + 1);
	if (res == NULL)
		return (NULL);
	while (str[i] != '\0') {
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	free(str);
	return (res);
}

char get_c(int fd)
{
	static char buffer[READ_SIZE + 1];
	static int i = 0;
	static int size = 0;
	char c;

	if (size == 0) {
		size = read(fd, buffer, READ_SIZE);
		buffer[size + 1] = '\0';
		if (size == 0)
			return ('\0');
		i = 0;
	}
	c = buffer[i];
	i++;
	size--;
	return (c);
}

char *my_get_line(char *res, int fd, char sep)
{
	char c;
	int i = 0;

	c = get_c(fd);
	while (c != sep && c != '\0') {
		res[i] = c;
		c = get_c(fd);
		i++;
		if (i % (READ_SIZE + 1) == 0) {
			res = my_realloc(res, my_strlengnl(res) + i);
			if (res == NULL)
				return (NULL);
		}
	}
	res[i] = '\0';
	if (c == '\0')
		return (NULL);
	return (res);
}

char *get_next_line(int fd, char sep)
{
	char *res;

	res = malloc(sizeof(char) * READ_SIZE + 1);
	if (res == NULL)
		return (NULL);
	res = my_get_line(res, fd, sep);
	if (res == NULL)
		return (NULL);
	return (res);
}
