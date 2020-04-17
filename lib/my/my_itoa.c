/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Itoa
*/

char *my_itoa(int val, int base)
{
	static char buf[32] = {0};
	int i = 30;

	if (val == 0)
		return ("0");
	for (; val && i ; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];
	return (&buf[i + 1]);
}
