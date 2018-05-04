/*
** EPITECH PROJECT, 2017
** sources/utils/my_itoa.c
** File description:
** My_itoa function.
*/

#include "utils.h"

char *my_itoa(int nb)
{
	int size = my_nblen(nb);
	char *str = my_calloc(sizeof(char) * (size + 1));

	for (int i = 0; i < size; i++, nb /= 10)
		str[i] = (nb % 10) + 48;
	my_revstr(str);
	return (str);
}