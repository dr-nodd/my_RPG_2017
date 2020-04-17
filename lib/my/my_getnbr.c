/*
** EPITECH PROJECT, 2018
** arnaud
** File description:
** my_getnbr
*/

int my_getnbr(char *str)
{
	int i = 0;
	int res = 0;

	while (*str == '+' || *str == '-') {
		if (*str == '-')
			i++;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (-1);
	for (int stk = 0; *str >= '0' && *str <= '9';) {
		stk = (*str - '0');
		res = (res * 10) + stk;
		str++;
	}
	if (i % 2 == 1)
		res = (res * -1);
	return (res);
}
