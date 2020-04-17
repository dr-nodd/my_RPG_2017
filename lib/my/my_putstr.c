/*
** EPITECH PROJECT, 2017
** putstr
** File description:
** arnaud
*/

#include <unistd.h>
#include "my.h"

void my_putstr(char const *str)
{
	write(1, str, my_strlen(str));
}
