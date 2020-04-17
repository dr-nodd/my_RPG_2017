/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** save/load functions
*/

#ifndef SAVE_H_
#define SAVE_H_

#include "struct.h"

char *find_name(char *);
char *init_my_string(char *, char *);
char **config_load(void);
char *find_variable_name(char *);
void load_equipement(game_t *, char *);
void load_variable(int, char *, game_t *);
int load_game(game_t *);
char *write_in_save(int, char *, game_t *);
char *save_equipement(game_t *);
int save_game(game_t *);

#endif
