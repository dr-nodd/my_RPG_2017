/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Check attack direction
*/

#include "animation.h"
#include "class.h"
#include "struct.h"

int switch_option(int option, int i)
{
	int warrior[4] = {SWORD_LEFT, SWORD_UP, SWORD_RIGHT, SWORD_DOWN};
	int archer[4] = {BOW_LEFT, BOW_UP, BOW_RIGHT, BOW_DOWN};
	int mage[4] = {SPELL_LEFT, SPELL_UP, SPELL_RIGHT, SPELL_DOWN};
	int dagger[4] = {DAGGER_LEFT, DAGGER_UP, DAGGER_RIGHT, DAGGER_DOWN};

	switch (option) {
	case (WARRIOR):
		return (warrior[i]);
	case (ARCHER):
		return (archer[i]);
	case (MAGE):
		return (mage[i]);
	case (DAGGER):
		return (dagger[i]);
	}
	return (0);
}

int check_attack_direction(sfSprite *sprite, int option)
{
	int anim[4] = {WALK_LEFT, WALK_UP, WALK_RIGHT, WALK_DOWN};

	if (option != WARRIOR && option != ARCHER && option != MAGE && option
	!= DAGGER)
		return (0);
	for (int i = 0; i < 4; i++)
		if (sfSprite_getTextureRect(sprite).top == anim[i])
			return (switch_option(option, i));
	return (0);
}
