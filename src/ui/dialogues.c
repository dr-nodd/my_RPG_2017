/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Dialogue
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"
#include "my.h"

char *check_dialogue(char *str)
{
	int i = 0;
	int n = 0;
	char *dest = malloc(sizeof(char) * my_strlen(str));

	while (str[i] != ':' && str[i] != '\0')
		i++;
	if (str[i] != '\0')
		i++;
	while (str[i] != '\0') {
		dest[n] = str[i];
		n++;
		i++;
	}
	dest[n] = '\0';
	return (dest);
}

char **dialogue_to_array(void)
{
	int fd = open("dialogues/eng_dialogues.txt", O_RDONLY);
	char *str = get_next_line(fd, '\n');
	char **array = malloc(sizeof(char *) * 100);
	int i = 0;

	for (; str != NULL; i++) {
		array[i] = check_dialogue(str);
		str = get_next_line(fd, '\n');
	}
	close(fd);
	array[i] = NULL;
	return (array);
}

int rand_dialogue(void)
{
	char **array = dialogue_to_array();
	int n = 0;
	int rd;

	while (array[n] != NULL)
		n++;
	rd = rand() % n;
	return (rd);
}
