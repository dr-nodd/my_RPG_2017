/*
** EPITECH PROJECT, 2018
** include
** File description:
** include libmy
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include "get_next_line.h"

int my_strlen(char const *);
void my_putstr(char const *);
int my_getnbr(char *);
int my_strcmp(char const *, char const *);
char **my_str_to_word_array(char *, char);
char *my_itoa(int, int);
char *my_strcat(char *, char const *);
int calculate_distance(sfSprite *, sfSprite *);
int calculate_rect_distance(sfFloatRect *, sfFloatRect *);
float find_angle(sfSprite *, sfSprite *);

#endif
