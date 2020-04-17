/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Random
*/

#include <stdlib.h>

double frand_a_b(double a, double b)
{
	return (rand()/(double)RAND_MAX) * (b-a) + a;
}
