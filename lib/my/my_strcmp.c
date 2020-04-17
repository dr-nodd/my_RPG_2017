/*
** EPITECH PROJECT, 2018
** RPG / Lib
** File description:
** Compares two strings
*/

int my_strcmp(char const *s1, char const *s2)
{
	while (*s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
